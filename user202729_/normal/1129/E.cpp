#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

int x;

struct edge{int a,b;};
std::vector<edge> ans;

template<class Iter>
int solve(Iter first,Iter last,int cnt=-1){
	// for all node y int [first..last[ range determine if y is int the subtree of x
	// if so add edge x..y to ans and set y=-1 

	assert(first!=last);

	if(cnt<0){
		std::cout<<"1\n1\n"; // S = {root}

		std::cout<<last-first<<'\n'; // T = {first..last}
		for(auto iter=first;iter!=last;++iter)
			std::cout<<*iter<<' ';
		std::cout<<'\n';

		std::cout<<x<<std::endl; // v = x

		std::cin>>cnt; // number of such node y
	}

	assert(0<=cnt&&cnt<=last-first);

	if(cnt!=0){
		if(cnt==last-first){
			for(auto iter=first;iter!=last;++iter){
				ans.push_back({x,*iter});
				*iter=-1;
			}
		}else{
			assert(last-first>=2);
			Iter mid=(last-first)/2+first;
			int cntl=solve(first,mid);
			solve(mid,last,cnt-cntl);
		}
	}

	return cnt;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	struct node{
		int x /* 1-indexing */,stsize;
	};

	std::vector<node> nodes;nodes.reserve(n);
	nodes.push_back({1,n});

	for(int i=2;i<=n;++i){
		std::cout<<"1\n1\n"; // S = {root}

		std::cout<<n-1<<"\n"; // T = V - {root}
		for(int j=2;j<=n;++j)
			std::cout<<j<<' ';
		std::cout<<'\n';

		std::cout<<i<<std::endl; // v = i

		int stsize;
		std::cin>>stsize;
		nodes.push_back({i,stsize});
	}

	std::sort(begin(nodes),end(nodes),[](node a,node b){
			return a.stsize>b.stsize;
			});

	std::vector<int> leaves;
	/*
	leaves.reserve(n);
	while(nodes.back().stsize==1){
		leaves.push_back(nodes.back().x);
		nodes.pop_back();
	}
	*/

	while(!nodes.empty()){
		/*global*/ x=nodes.back().x;
		if(!leaves.empty()){
			solve(begin(leaves),end(leaves));
			leaves.erase(std::remove(begin(leaves),end(leaves),-1),end(leaves));
		}
		leaves.push_back(x);
		nodes.pop_back();
	}
	
	std::cout<<"ANSWER\n";
	for(edge e:ans)std::cout<<e.a<<' '<<e.b<<'\n';
}