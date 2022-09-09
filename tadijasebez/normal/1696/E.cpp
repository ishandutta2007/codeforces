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

const int mod=1e9+7;//998244353
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}

const int M=1000050;
int F[M],I[M];
int binom(int n, int k){
	if(n<k||k<0)return 0;
	return mul(F[n],mul(I[k],I[n-k]));
}
void calc()
{
	F[0]=1;
	for(int i=1;i<M;i++) F[i]=mul(F[i-1],i);
	I[M-1]=inv(F[M-1]);
	for(int i=M-2;~i;i--) I[i]=mul(I[i+1],i+1);
}



const int N=400050;
int a[N];
vector<int> when[N];

int main(){
	calc();

	int n=ri()+1,mx=0;
	for(int i=0;i<n;i++){
		a[i]=ri()+i;
		when[a[i]].pb(i);
		ckmx(mx,a[i]);
	}
	if(a[0]==0){
		printf("0\n");
		return 0;
	}

	int sum=1,ans=1;
	set<array<int,3>> intervals;
	for(int i=1;i<=mx;i++){
		sum=sub(mul(sum,2),binom(i-1,n-1));
		ckadd(ans,sum);
		set<array<int,3>> newIntervals;
		for(auto interval:intervals){
			int l=interval[0];
			int r=interval[1];
			int sum=interval[2];
			ckmul(sum,2);
			cksub(sum,binom(i-1,r));
			ckadd(sum,binom(i-1,l-1));
			newIntervals.insert({l,r,sum});
		}
		for(int j : when[i]){
			newIntervals.insert({j,j,binom(i,j)});
		}

		for(auto interval:newIntervals){
			cksub(ans,interval[2]);
		}
		intervals.clear();
		for(auto interval:newIntervals){
			if(intervals.size()&&(*intervals.rbegin())[1]==interval[0]-1){
				auto pre = *intervals.rbegin();
				intervals.erase(--intervals.end());
				intervals.insert({pre[0],interval[1],add(pre[2],interval[2])});
			}else{
				intervals.insert(interval);
			}
		}
	}
	printf("%i\n",ans);
	return 0;
}