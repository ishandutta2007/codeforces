#include<iostream>
#include<vector>
#include<array>
#include<string>
#include<cassert>

int maxStep;
struct SegmentTree{
	struct Node{
		// represent the change of win/lose state when apply a range of array values
		std::array<int,6> fn,flipFn;
		Node(){ // identity function
			for(int i=0;i<=maxStep;++i)
				fn[i]=flipFn[i]=i;
		}
		Node(char x){
			for(int i=0;i<maxStep;++i)
				fn[i]=flipFn[i]=i+1;
			fn[maxStep]=maxStep;if(x)fn[maxStep]=0;
			flipFn[maxStep]=maxStep;if(!x)flipFn[maxStep]=0;
		}
		void flip(){
			std::swap(fn,flipFn);
		}
		Node operator*(Node a)const{
			Node ans;
			for(int i=0;i<=maxStep;++i){
				ans.fn[i]=fn[a.fn[i]];
				ans.flipFn[i]=flipFn[a.flipFn[i]];
			}
			return ans;
		}
	};
	struct LazyNode{
		Node n;
		bool lazy; // lazy does not affect n
		void flip(){ // after this operation, the status of the tree (except the
			// ancestors of this node) is still correct
			lazy^=true;
			n.flip();
		}
	};
	std::vector<LazyNode> data;

	SegmentTree(std::vector<char> const& arrParity){
		auto n=(unsigned)arrParity.size();
		data.resize(2*n);
		for(unsigned i=0;i<n;++i)
			data[i+n].n=Node(arrParity[i]);
		for(unsigned i=n-1;i;--i)
			data[i].n=data[i<<1].n*data[i<<1|1].n;
	}

	void pushLazy(int node){
		for(int i=31^__builtin_clz(node);i;--i){
			int n1=node>>i;
			if(data[n1].lazy){
				data[n1].lazy=false;
				data[n1<<1  ].flip();
				data[n1<<1|1].flip();
			}
		}
	}
	void recompute(int node){
		node>>=1;
		while(node){
			assert(!data[node].lazy);
			data[node].n=data[node<<1].n*data[node<<1|1].n;
			node>>=1;
		}
	}

	void update(int left,int right){
		if(left==right)return;
		int l0=left +=int(data.size()/2);
		int r0=right+=int(data.size()/2);
		pushLazy(l0);pushLazy(r0-1);
		while(left<right){
			if(left &1)data[left++ ].flip();
			if(right&1)data[--right].flip();
			left>>=1;right>>=1;
		}
		pushLazy(l0);pushLazy(r0-1);
		recompute(l0);recompute(r0-1);
	}
	Node get(int left,int right){
		left +=int(data.size()/2);
		right+=int(data.size()/2);
		pushLazy(left);pushLazy(right-1);
		Node ansL,ansR;
		while(left<right){
			if(left &1)ansL=ansL*data[left++ ].n;
			if(right&1)ansR=data[--right].n*ansR;
			left>>=1;right>>=1;
		}
		return ansL*ansR;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int arrSize,nQuery;
	std::cin>>arrSize>>maxStep>>nQuery;
	std::vector<char> arrParity(arrSize);
	std::string x;
	for(char& c:arrParity){
		std::cin>>x; // a[i] value
		c=char(x.back()&1);
	}
	SegmentTree arrParity_ST(arrParity);
	for(int _=nQuery;_-->0;){
		char type;int left,right;std::cin>>type>>left>>right;--left;
		if(type=='1'){
			std::cin>>x; // delta
			if((x.back()&1)==0)continue; // adding an even number doesn't change parity
			// for(int i=left;i<right;++i)arrParity[i]^=1;
			arrParity_ST.update(left,right);
		}else{
			int minRmToLose=maxStep; // the empty array is not a valid state, but this
			// best fits the formula (because after prepending a number, it's impossible
			// to reach a losing state in <= maxStep pop front)
			
			// naive algorithm: ========
			//for(int i=right;i-->left;){
			//	if(minRmToLose<maxStep)
			//		++minRmToLose;
			//	else if(arrParity[i])
			//		minRmToLose=0;
			//}
			minRmToLose=arrParity_ST.get(left,right).fn[minRmToLose];
			std::cout<<(minRmToLose==0?'2':'1')<<'\n';
		}
	}
}