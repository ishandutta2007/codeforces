#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
template<typename T>void rd(vector<T>&v){for(T&i:v)rd(i);}

pii Ask(vector<int> nodes){
	printf("? %i ",nodes.size());
	for(int i:nodes)printf("%i ",i);
	printf("\n");
	fflush(stdout);
	pii b;rd(b);
	return b;
}
int main(){
	for(int t=ri();t--;){
		int n=ri();
		vector<vector<int>> E(n+1,vector<int>());
		for(int i=1,u,v;i<n;i++)rd(u,v),E[u].pb(v),E[v].pb(u);
		vector<int> lid(n+1);
		int tid=0;
		vector<int> ord;
		function<void(int,int)> DFS=[&](int u,int p){
			lid[u]=++tid;ord.pb(u);
			for(int v:E[u])if(v!=p)DFS(v,u);
		};
		DFS(1,0);
		int dst=Ask(ord).second;
		int top=n-1,bot=0,mid;
		while(top>bot){
			int mid=top+bot+1>>1;
			vector<int> a;
			for(int i=mid;i<n;i++)a.pb(ord[i]);
			pii b=Ask(a);
			if(b.second==dst)bot=mid;
			else top=mid-1;
		}
		int fir=ord[bot];
		vector<int> vec;
		function<void(int,int,int)> DFS2=[&](int u,int p,int d){
			if(d==dst)vec.pb(u);
			for(int v:E[u])if(v!=p)DFS2(v,u,d+1);
		};
		DFS2(fir,0,0);
		int sec=Ask(vec).first;
		printf("! %i %i\n",fir,sec);
		fflush(stdout);
		char ver[20];
		scanf("%s",ver);
	}
	return 0;
}