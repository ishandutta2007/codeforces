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
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}

const int N=500050;
const int M=2*N;
char s[N];
int ls[M],rs[M],tsz,root,dp[M][2][2];

int Get(char a,char b){
	if(a!='1')return 0;
	int o=(a-'0')*10+(b-'0');
	if(o>18)return 0;
	return 19-o;
}
int Get(char a){return (a-'0')+1;}

void pull(int c,int ss,int se){
	int mid=ss+se>>1;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			dp[c][i][j]=add(mul(dp[ls[c]][i][0],dp[rs[c]][0][j]),mul(dp[ls[c]][i][1],mul(Get(s[mid],s[mid+1]),dp[rs[c]][1][j])));
		}
	}
}

void Make(int c,char ch){
	dp[c][0][0]=Get(ch);
	dp[c][0][1]=1;
	dp[c][1][0]=1;
	dp[c][1][1]=0;
}

void Build(int&c,int ss,int se){
	c=++tsz;
	if(ss==se){Make(c,s[ss]);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	pull(c,ss,se);
}

void Set(int c,int ss,int se,int qi,char ch){
	if(ss==se){Make(c,ch);return;}
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi,ch);
	else Set(rs[c],mid+1,se,qi,ch);
	pull(c,ss,se);
}

int main(){
	int n,m;rd(n,m);
	rd(s+1);
	Build(root,1,n);
	while(m--){
		int i,d;
		rd(i,d);
		s[i]='0'+d;
		Set(root,1,n,i,'0'+d);
		printf("%i\n",dp[root][0][0]);
	}
	return 0;
}