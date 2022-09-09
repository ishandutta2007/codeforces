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
const int mod=998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}

const int N=1000050;
int F[N],I[N];
int binom(int n, int k){ return mul(F[n],mul(I[k],I[n-k]));}
void calc()
{
	F[0]=1;
	for(int i=1;i<N;i++) F[i]=mul(F[i-1],i);
	I[N-1]=inv(F[N-1]);
	for(int i=N-2;~i;i--) I[i]=mul(I[i+1],i+1);
}

int main(){
	calc();
	int n=ri(),k=ri();
	vector<pii> evs;
	for(int i=1;i<=n;i++){
		int l,r;rd(l,r);
		evs.pb({l,-1});
		evs.pb({r,1});
	}
	sort(evs.begin(),evs.end());
	int bal=0;
	int ans=0;
	for(pii e:evs){
		int x=e.second;
		if(x<0){
			bal++;
			if(bal==k)ckadd(ans,binom(k,k));
			else if(bal>k)ckadd(ans,binom(bal-1,k-1));
		}else bal--;
	}
	printf("%i\n",ans);
	return 0;
}