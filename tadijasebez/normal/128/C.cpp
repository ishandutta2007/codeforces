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

const int mod=1e9+7;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int sub(int x,int y){x-=y;return x<0?x+mod:x;}
int mul(int x,int y){return (ll)x*y%mod;}

const int N=3050;
int F[N],I[N];
int binom(int n,int k){return mul(F[n],mul(I[k],I[n-k]));}
int chose(int k,int n){return binom(n+k-1,k);}
int main(){
	int n,m,k;
	rd(n,m,k);
	n-=k*2+1;
	m-=k*2+1;
	if(n<0||m<0)return 0*printf("0\n");
	F[0]=1;for(int i=1;i<N;i++)F[i]=mul(F[i-1],i);
	I[0]=I[1]=1;for(int i=2;i<N;i++)I[i]=mul(mod-mod/i,I[mod%i]);
	for(int i=1;i<N;i++)I[i]=mul(I[i-1],I[i]);
	printf("%i\n",mul(chose(n,k*2+1),chose(m,k*2+1)));
	return 0;
}