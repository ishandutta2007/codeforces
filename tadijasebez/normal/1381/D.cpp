#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
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
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=100050;
const int inf=1e9+7;
vector<int> E[N];
int Go(int u,int p,int g){
	if(u==g)return 0;
	int ans=inf;
	for(int v:E[u])if(v!=p)ckmn(ans,Go(v,u,g)+1);
	return ans;
}
int dw[N],up[N];
void DFS1(int u,int p){
	dw[u]=0;
	for(int v:E[u])if(v!=p){
		DFS1(v,u);
		ckmx(dw[u],dw[v]+1);
	}
}
int ans;
void DFS2(int u,int p){
	if(!p)up[u]=0;
	for(int i=0;i<2;i++){
		int best=up[u]+1;
		for(int v:E[u])if(v!=p){
			ckmx(up[v],best);
			ckmx(best,dw[v]+2);
		}
		reverse(E[u].begin(),E[u].end());
	}
	vector<int> best={up[u],-inf,-inf};
	for(int v:E[u])if(v!=p){
		DFS2(v,u);
		int now=dw[v]+1;
		if(best[0]<now)best[2]=best[1],best[1]=best[0],best[0]=now;
		else if(best[1]<now)best[2]=best[1],best[1]=now;
		else ckmx(best[2],now);
	}
	ckmx(ans,best[2]);
	//printf("%i: %i %i %i\n",u,best[0],best[1],best[2]);
}
int par[N],dep[N];
void DFS3(int u,int p){
	par[u]=p;
	for(int v:E[u])if(v!=p){
		dep[v]=dep[u]+1;
		DFS3(v,u);
	}
}
bool Check(int a,int b){
	dep[a]=0;
	DFS3(a,0);
	vector<int> path;
	for(int i=b;i;i=par[i])path.pb(i);
	reverse(path.begin(),path.end());
	int A=1,B=(int)path.size()-1;
	//int L=up[path[A]]-1,R=dw[path[B]];
	while(A<B){
		//printf("%i %i\n",A,B);
		bool cng=0;
		int L=up[path[A]]-1;
		int nB=(int)path.size()-1-L+A-1;
		if(nB<B){
			cng=1;
			B=nB;
			if(B<=A)break;
		}
		int R=dw[path[B]];
		int nA=1+R-((int)path.size()-1-B);
		if(nA>A){
			cng=1;
			A=nA;
			if(B<=A)break;
		}
		if(!cng)break;
	}
	return A>=B;
}
int main(){
	for(int t=ri();t--;){
		int n,a,b;rd(n,a,b);
		for(int i=1;i<=n;i++)E[i].clear(),up[i]=0;
		re(E,n-1);
		int dist=Go(a,0,b);
		ans=0;
		DFS1(a,0);
		DFS2(a,0);
		if(dist<=ans&&Check(a,b))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}