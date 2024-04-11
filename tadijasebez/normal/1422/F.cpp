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

const int N=200050;
const int S=450;

struct SegTreeMax{
	vector<int> mx;
	int n;
	void init(int _n){n=_n;mx=vector<int>(2*n,0);}
	SegTreeMax(int _n){init(_n);}
	void Set(int i,int x){i+=n;mx[i]=x;for(i>>=1;i;i>>=1)mx[i]=max(mx[i<<1],mx[i<<1|1]);}
	int Get(int l,int r){
		int ans=0;
		for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
			if(l%2==1)ckmx(ans,mx[l++]);
			if(r%2==0)ckmx(ans,mx[r--]);
		}
		return ans;
	}
};

/*struct SegTreeMul{
	vector<int> a;
	int n;
	void init(int _n){n=_n;a=vector<int>(2*n,1);}
	SegTreeMul(int _n){init(_n);}
	void Set(int i,int x){i+=n;a[i]=x;for(i>>=1;i;i>>=1)a[i]=mul(a[i<<1],a[i<<1|1]);}
	int Get(int l,int r){
		int ans=1;
		for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
			if(l%2==1)ckmul(ans,a[l++]);
			if(r%2==0)ckmul(ans,a[r--]);
		}
		return ans;
	}
};*/
const int M=N*40;
int ls[M],rs[M],tsz,root[N],a[M];
void Set(int p,int&c,int ss,int se,int qi,int x){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];
	if(ss==se){a[c]=x;return;}
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi,x);
	else Set(rs[p],rs[c],mid+1,se,qi,x);
	a[c]=mul(a[ls[c]],a[rs[c]]);
}
int Get(int c,int ss,int se,int qs,int qe){
	if(!c||qs>qe||qs>se||ss>qe)return 1;
	if(qs<=ss&&qe>=se)return a[c];
	int mid=ss+se>>1;
	return mul(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}

int main(){
	int n=ri();
	auto a=rv<int>(n);
	vector<int> prime;
	vector<bool> sieve(S,0);
	for(int i=2;i<S;i++){
		if(!sieve[i]){
			prime.pb(i);
			for(int j=i*2;j<S;j+=i)sieve[j]=1;
		}
	}
	vector<SegTreeMax> ST(prime.size(),SegTreeMax(n));
	::a[0]=1;
	map<int,int> last;
	for(int i=0;i<n;i++){
		if(i)root[i]=root[i-1];
		for(int j=0;j<prime.size();j++){
			int cnt=0;
			while(a[i]%prime[j]==0){
				a[i]/=prime[j];
				cnt++;
			}
			if(cnt)ST[j].Set(i,cnt);
		}
		if(a[i]!=1){
			if(last.count(a[i]))Set(root[i],root[i],0,n-1,last[a[i]],1);
			Set(root[i],root[i],0,n-1,i,a[i]);
			last[a[i]]=i;
		}
	}
	int q=ri();
	int ans=0;
	while(q--){
		int l,r;rd(l,r);
		l=(l+ans)%n;
		r=(r+ans)%n;
		if(l>r)swap(l,r);
		ans=Get(root[r],0,n-1,l,r);
		for(int j=0;j<prime.size();j++){
			ckmul(ans,powmod(prime[j],ST[j].Get(l,r)));
		}
		printf("%i\n",ans);
	}
	return 0;
}