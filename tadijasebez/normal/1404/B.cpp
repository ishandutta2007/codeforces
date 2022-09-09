#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}

int main(){
	for(int t=ri();t--;){
		int n,a,b,da,db;
		rd(n,a,b,da,db);
		vector<vector<int>> E(n+1,vector<int>());
		for(int i=1,u,v;i<n;i++)rd(u,v),E[u].pb(v),E[v].pb(u);
		function<int(int,int,int)> DFS=[&](int u,int p,int g){
			if(u==g)return 0;
			int ans=1e9;
			for(int v:E[u])if(v!=p)ans=min(ans,DFS(v,u,g)+1);
			return ans;
		};
		int dist=DFS(a,0,b);
		int diam=0;
		function<int(int,int)> FindD=[&](int u,int p){
			int best=0;
			for(int v:E[u])if(v!=p){
				int o=FindD(v,u)+1;
				diam=max(diam,best+o);
				best=max(best,o);
			}
			return best;
		};
		FindD(1,0);
		if(dist<=da)printf("Alice\n");
		else if(db>da*2&&diam>da*2)printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}