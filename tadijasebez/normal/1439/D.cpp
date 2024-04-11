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

int mod;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}

const int N=505;
int blok[N],sum[N];
int c2(int x){return ((ll)x*(x+1)/2)%mod;}
int dp[N][N],ways[N][N];

//const int M=1050;
//int F[M],I[M];
//int binom(int n, int k){ return mul(F[n],mul(I[k],I[n-k]));}
int binom[N][N];
void calc()
{
	binom[0][0]=1;
	for(int i=1;i<N;i++){
		binom[i][0]=1;
		for(int j=1;j<=i;j++){
			binom[i][j]=add(binom[i-1][j],binom[i-1][j-1]);
		}
	}
	/*F[0]=1;
	for(int i=1;i<M;i++) F[i]=mul(F[i-1],i);
	I[M-1]=inv(F[M-1]);
	for(int i=M-2;~i;i--) I[i]=mul(I[i+1],i+1);*/
}
int main(){
	int n,m;rd(n,m,mod);
	calc();
	blok[0]=1;
	for(int x=1;x<=m;++x){//block size
		for(int i=1;i<=x;++i){//last element
			ckadd(blok[x],mul(blok[i-1],mul(blok[x-i],binom[x-1][i-1])));
			ckadd(sum[x],mul(add(c2(i-1),c2(x-i)),mul(blok[i-1],mul(blok[x-i],binom[x-1][i-1]))));
			ckadd(sum[x],mul(sum[i-1],mul(mul(blok[x-i],binom[x-1][i-1]),x+1)));
			ckadd(sum[x],mul(sum[x-i],mul(mul(blok[i-1],binom[x-1][i-1]),x+1)));
		}
		ckmul(blok[x],x+1);
		//printf("%i %i\n",blok[x],sum[x]);
	}
	ways[0][0]=1;
	for(int i=1;i<=m;++i){//total size
		for(int j=1;j<=i;++j){//number of blocks
			for(int sz=1;sz<=i;++sz){//last block size
				ckadd(ways[i][j],mul(ways[i-sz][j-1],mul(blok[sz],binom[m-i+sz][sz])));
				ckadd(dp[i][j],mul(ways[i-sz][j-1],mul(sum[sz],binom[m-i+sz][sz])));
				ckadd(dp[i][j],mul(dp[i-sz][j-1],mul(blok[sz],binom[m-i+sz][sz])));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){//number of blocks
		int zero=n-m;
		int lef=zero-(i-1);
		if(lef>=0){
			ckadd(ans,mul(dp[m][i],binom[i+1+lef-1][lef]));
		}
	}
	printf("%i\n",ans);
	return 0;
}