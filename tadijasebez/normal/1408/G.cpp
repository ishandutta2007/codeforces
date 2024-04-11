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

const int mod=998244353;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int mul_inv(int x){ return powmod(x,mod-2);}
void fft(int a[], int n, bool inv)
{
	for(int i=1,j=0;i<n;i++)
	{
		int k=n;do j^=k>>=1; while(~j&k);
		if(j>i) swap(a[i],a[j]);
	}
	for(int j=2;j<=n;j<<=1)
	{
		int ang=powmod(3,(mod-1)/j);
		if(inv) ang=mul_inv(ang);
		for(int i=0;i<n/j;i++)
		{
			int cur=1;
			for(int k=i*j;k<i*j+j/2;k++)
			{
				int tmp=mul(cur,a[k+j/2]);
				a[k+j/2]=sub(a[k],tmp);
				a[k]=add(a[k],tmp);
				cur=mul(cur,ang);
			}
		}
	}
	int m=mul_inv(n);
	if(inv) for(int i=0;i<n;i++) a[i]=mul(a[i],m);
}
void mul(int a[],int b[],int c[],int n){
	fft(a,n,0);
	fft(b,n,0);
	for(int i=0;i<n;i++)c[i]=mul(a[i],b[i]);
	fft(c,n,1);
}

const int N=1505;
const int M=2*N;
const int H=1<<11;
int a[N][N],tot,my[N],was[M];
vector<int> cmp[M],E[M];
pii pt[N*N];
int c2(int x){return x*(x-1)/2;}
int dp[M][H];
void DFS(int u){
	if(E[u].size()){
		//printf("%i -> %i %i\n",u,E[u][0],E[u][1]);
		DFS(E[u][0]);
		DFS(E[u][1]);
		for(int i=0;i<H;i++)dp[u][i]=mul(dp[E[u][0]][i],dp[E[u][1]][i]);
		//mul(dp[E[u][0]],dp[E[u][1]],dp[u],H);
	}
	if(was[u]==c2(cmp[u].size())){
		fft(dp[u],H,1);
		//printf("%i ok\n",u);
		ckadd(dp[u][1],1);
		fft(dp[u],H,0);
	}
	//printf("%i: ",u);
	//for(int i=1;i<=4;i++)printf("%i ",dp[u][i]);
}
int main(){
	int n=ri();
	for(int i=1;i<=n;i++){
		ra(a[i],n);
		for(int j=i+1;j<=n;j++){
			pt[a[i][j]]={i,j};
		}
	}
	for(int i=1;i<=n;i++)my[i]=i,cmp[i]={i};
	tot=n;
	for(int i=1;i<=n*(n-1)/2;i++){
		int u,v;tie(u,v)=pt[i];
		if(my[u]!=my[v]){
			int a=my[u],b=my[v];
			tot++;
			E[tot].pb(a);
			E[tot].pb(b);
			for(int j:cmp[a])cmp[tot].pb(j),my[j]=tot;
			for(int j:cmp[b])cmp[tot].pb(j),my[j]=tot;
			was[tot]=was[a]+was[b]+1;
		}else was[my[u]]++;
	}
	DFS(tot);
	fft(dp[tot],H,1);
	for(int i=1;i<=n;i++)printf("%i ",dp[tot][i]);
	return 0;
}