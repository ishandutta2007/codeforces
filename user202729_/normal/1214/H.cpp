#ifndef LOCAL
#define NDEBUG
#endif
#include<queue>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

std::vector<std::vector<int>> ad;

std::vector<int> dt; // depth
std::vector<int> parof; // parent of

void fs(int node,int par){ // dfs
	parof[node]=par;
	for(int x:ad[node])if(x!=par){
		dt[x]=dt[node]+1;
		fs(x,node);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,k;std::cin>>n>>k;
	ad.resize(n);
	for(int z=n-1;z--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	dt.resize(n);dt[0]=0;
	parof.resize(n);
	fs(0,-1);

	if(k==2){
		std::cout<<"Yes\n";
		for(int d:dt)
			std::cout<<(d%2?'1':'2')<<' ';
		std::cout<<'\n';
		return 0;
	}
	
	auto root=int(std::max_element(begin(dt),end(dt))-begin(dt));
	dt.resize(n);dt[root]=0;
	parof.resize(n);
	fs(root,-1);

	auto leaf=int(std::max_element(begin(dt),end(dt))-begin(dt));
	int dia=1+dt[leaf]; // num of nodes on the diameter
	if(dia<k){
		std::cout<<"Yes\n";
		for(int i=0;i<n;++i)
			std::cout<<"1 ";
		std::cout<<'\n';
		return 0;
	}

	struct state{
		int // x,
			homei, // depth of nearest node on leaf-root path
			dist, // to that node
			color;
	};
	std::vector<state> s(n,{-1,-1,-1});

	std::queue<int> q;

	// now par points to the node closer to leaf..root path
	for(int x=leaf,oldparx;;x=oldparx){
		q.push(x);
		s[x]={dt[x],0,dt[x]%k};
		oldparx=parof[x];
		parof[x]=-1;

		if(x==root)
			break;
	}

	while(!q.empty()){
		auto x=q.front();q.pop();
		for(int y:ad[x])if(s[y].dist<0){
			q.push(y);
			s[y]={s[x].homei,s[x].dist+1,-1 /* will fill color later */};
			parof[y]=x;

			int dy=s[y].dist;
			int hy=s[y].homei;
			int add1=hy+1;
			int add2=dia-hy;
			if(dy+add1>=k&&dy+add2>=k){
				std::cout<<"No\n";
				return 0;
			}

			if(dy+add1>=k){
				for(int z=y;s[z].color<0;){
					s[z].color=(hy+s[z].dist)%k;
					z=parof[z];
				}
			}else if(dy+add2>=k){
				for(int z=y;s[z].color<0;){
					s[z].color=((hy-s[z].dist)%k+k)%k;
					z=parof[z];
				}
			}
		}
	}

	std::cout<<"Yes\n";
	for(state& st:s)
		std::cout<<std::max(st.color,0)+1<<' ';
	std::cout<<'\n';
}