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
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}

const int B=37;

const int M=105;
const int N=1000050;
char s[M],t[N],u[N];
char tmp_l[N],tmp_r[N];
int hsh_l[N],hsh_r[N],sz[N],pwb[N],sum[26][N];
int main(){
	int n=ri(),q=ri();
	rd(s+1);
	rd(t+1);
	int m=strlen(s+1);
	int len_l=0,len_r=0;
	for(int i=1;i<=m;i++)tmp_l[++len_l]=s[i];
	for(int i=m;i>=1;i--)tmp_r[++len_r]=s[i];
	for(int i=1;i<=n;i++){
		if(len_l+1<N){
			tmp_l[++len_l]=t[i];
			tmp_r[++len_r]=t[i];
			int sz=len_l-1;
			for(int j=1;j<=sz;j++){
				if(len_l+1<N){
					tmp_l[++len_l]=tmp_l[j];
					tmp_r[++len_r]=tmp_r[j];
				}
			}
		}
		for(int j=0;j<26;j++)sum[j][i]=sum[j][i-1];
		ckadd(sum[t[i]-'a'][i],powmod(2,n-i));
	}
	for(int i=1;i<=len_l;i++){
		hsh_l[i]=add(mul(hsh_l[i-1],B),tmp_l[i]-'a'+1);
		hsh_r[i]=add(mul(hsh_r[i-1],B),tmp_r[i]-'a'+1);
	}
	sz[0]=1;for(int i=1;i<=n;i++)sz[i]=mul(sz[i-1],2);
	pwb[0]=1;for(int i=1;i<N;i++)pwb[i]=mul(pwb[i-1],B);
	auto AtLeast=[&](int sz){
		int k=0,now=m;
		while(sz>now)k++,now=now*2+1;
		return k+1;
	};
	auto Get=[&](int l,int r,char ch){
		if(l>r)return 0;
		return mul(sub(sum[ch-'a'][r],sum[ch-'a'][l-1]),inv(powmod(2,n-r)));
	};
	for(int qi=1;qi<=q;qi++){
		int k=ri();
		rd(u+1);
		int l=strlen(u+1);
		int ans=0,LH=0,RH=0;
		for(int i=1;i<=l;i++)RH=add(mul(RH,B),u[i]-'a'+1);
		for(int i=1;i<=l;i++){
			cksub(RH,mul(pwb[l-i],u[i]-'a'+1));
			if(hsh_r[i-1]==LH&&hsh_l[l-i]==RH){
				//printf("%i ",i);
				ckadd(ans,Get(AtLeast(max(i-1,l-i)),k,u[i]));
			}
			ckadd(LH,mul(pwb[i-1],u[i]-'a'+1));
		}
		if(l<=m){
			for(int st=1;st+l-1<=m;st++){
				bool ok=1;
				for(int i=1;i<=l;i++){
					if(u[i]!=s[st+i-1])ok=0;
				}
				if(ok){
					ckadd(ans,sz[k]);
				}
			}
		}
		printf("%i\n",ans);
	}
	return 0;
}