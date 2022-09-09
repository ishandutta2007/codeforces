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
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}
const int N=300050;
const int M=32*N;
int go[M][2],tsz,root,sz[M];
void Add(int&c,int X,int lvl=30){
	if(!c)c=++tsz;
	sz[c]++;
	if(!~lvl)return;
	Add(go[c][X>>lvl&1],X,lvl-1);
}
const int L=31;
ll sum[L][2];
void Set(int c,int X,int lvl=30){
	if(!~lvl)return;
	int d=X>>lvl&1;
	sum[lvl][d]+=sz[go[c][d^1]];
	Set(go[c][d],X,lvl-1);
}
int a[N];
int main(){
	int n=ri();
	ra(a,n);
	for(int i=1;i<=n;i++){
		Set(root,a[i]);
		Add(root,a[i]);
	}
	ll ans=0,X=0;
	for(int i=L-1;~i;i--){
		if(sum[i][0]<=sum[i][1]){
			ans+=sum[i][0];
		}else{
			ans+=sum[i][1];
			X+=1<<i;
		}
	}
	printf("%lld %i\n",ans,X);
	return 0;
}