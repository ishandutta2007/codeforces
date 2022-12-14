#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

struct TreapConstructor{ // root = min priority
	struct Node{
		int priority;
		int depth; // of the subtree, excluding right branch, relative from this node (least 1)
	};
	std::vector<Node> a; // rightmost branch (increasing)
	int depth;

	//TreapConstructor(int priority):a{{priority,1}},depth{1}{}
	TreapConstructor():a{},depth{0}{}

	void add(int priority){
		Node newn{priority,1};
		if(a.empty()||priority>a.back().priority){
			a.push_back(newn);
			depth=std::max(depth,(int)a.size());
			return;
		}
		while(a.size()>=2&&a.end()[-2].priority>priority){
			int d1=a.back().depth;
			a.pop_back();
			a.back().depth=std::max(a.back().depth,d1+1);
		}

		newn.depth=std::max(newn.depth,a.back().depth+1);
		a.back()=newn;
		depth=std::max(depth,newn.depth+(int)a.size()-1);
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);
	for(int& x:a)std::cin>>x;

	int nrot;
	{
		auto iter=std::find(begin(a),end(a),1);
		nrot=int(iter-begin(a));
		if(nrot)
			std::rotate(begin(a),iter,end(a));
	}

	std::vector<int> pre(n);
	{
		TreapConstructor t;
		for(int i=1;i<n;++i){
			t.add(a[i]);
			pre[i]=t.depth;
		}
	}

	std::vector<int> suf(n+1);
	// suf[n]=0;
	{
		TreapConstructor t;
		for(int i=n-1;i;--i){
			t.add(a[i]);
			suf[i]=t.depth;
		}
	}

	int mindi=INT_MAX,besti;
	for(int i=0;i<n;++i){
		int di=std::max(pre[i],suf[i+1])+1;
		if(di<mindi){
			mindi=di;
			besti=i;
		}
	}
	std::cout<<mindi<<' '<<(besti+1+nrot)%n<<'\n';
}