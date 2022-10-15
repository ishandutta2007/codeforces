#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<ll> inv,fact,invfact;
void mod_build(int n=101010){
	fact.resize(n+1);
	inv.resize(n+1);
	invfact.resize(n+1);
	fact[0]=inv[0]=invfact[0]=1;
	inv[1]=1;
	rep(i,n){
		fact[i+1]=fact[i]*(i+1)%mod;
		if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
		invfact[i+1]=invfact[i]*inv[i+1]%mod;
	}
}
ll perm(int n,int k){
	if(n<0||k<0||k>n)return 0;
	return fact[n]*invfact[n-k]%mod;
}
ll comb(int n,int k){
	if(n<0||k<0||k>n)return 0;
	return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}
ll powmod(ll n,ll k){
	ll ret=1;
	while(k){
		if(k&1)ret=ret*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return ret;
}


template<typename T>
struct LazySegmentTree{
private:
	int n;
	vector<T> node,lazy;
	T E0,E1;

	inline void updatef(T& lazy,T& value){
		//lazy += value;
		//lazy = value;
		//lazy = max(lazy, value);
		//lazy = min(lazy, value);
		lazy.first = lazy.first*value.first%mod;
		lazy.second|=value.second;
	}
	inline void calculatef(T& node,T& lazy,int len){
		//node += lazy * len;
		// node += lazy ;
		//node = lazy ;
		node.first = node.first * powmod(lazy.first,len)%mod;
		node.second |= lazy.second;
	}
	inline T queryf(T& x,T& y){
		//return x + y;
		return make_pair(x.first * y.first %mod, x.second | y.second);
		//return max(x, y);
		//return min(x, y);
	}
public:
	LazySegmentTree(int sz,T nodeE,T lazyE = 0):E0(nodeE), E1(lazyE){
		n=1;
		while(n<sz)n<<=1;
		node.resize(2*n-1,E0);
		lazy.resize(2*n-1,E1);
	}

	LazySegmentTree(vector<T>& v,T E0,T E1 = 0):E0(E0),E1(E1){
		n=1;
		int sz=v.size();
		while(n<sz)n<<=1;
		node.resize(2*n-1,E0);
		lazy.resize(2*n-1,E1);
		rep(i,sz)node[i+n-1] = v[i];
		for(int i=n-2; i>=0; --i){
			node[i] = queryf(node[2*i+1],node[2*i+2]);
		}
	}

	void eval(int k,int l,int r){
		if(lazy[k]==E1)return ;
		calculatef(node[k], lazy[k], r-l);
		if(r-l>1){
			updatef(lazy[2*k+1], lazy[k]);
			updatef(lazy[2*k+2], lazy[k]);
		}
		lazy[k]=E1;
	}

	void update(int a, int b, T x,int k=0,int l=0,int r=-1){
		if(r<0)r=n;
		eval(k,l,r);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			updatef(lazy[k], x);
			eval(k,l,r);
		}
		else {
			update(a,b,x,2*k+1,l,(l+r)/2);
			update(a,b,x,2*k+2,(l+r)/2,r);
			node[k]=queryf(node[2*k+1], node[2*k+2]);
		}
	}

	T query(int a,int b,int k=0,int l=0,int r=-1){
		if(r<0)r=n;
		eval(k,l,r);
		if(r<=a||b<=l)return E0;
		if(a<=l&&r<=b)return node[k];
		T xl=query(a,b,2*k+1,l,(l+r)/2);
		T xr=query(a,b,2*k+2,(l+r)/2,r);
		return queryf(xl, xr);
	}
};


int main(){
	vector<int>isprime(303,1);
	vector<int>prime;
	vector<ll> bs(303);
	ll e=1;
	isprime[0]=isprime[1]=0;
	rep(i,303){
		if(!isprime[i])continue;
		prime.push_back(i);
		for(int j=i;j<303;j+=i){
			bs[j]|=e;
			isprime[j]=false;
		}
		e<<=1;
	}
	mod_build(303);
	int n,q;
	cin>>n>>q;
	vector<pair<ll,ll>> a(n);
	vector<bitset<70>> b(n);
	rep(i,n){
		scanf("%lld",&a[i].first);
		a[i].second = bs[a[i].first];
	}
	LazySegmentTree<pair<ll,ll>> sg(a,{1,0},{1,0});
	while(q--){
		string s;
		cin>>s;
		if(s[0]=='T'){
			int l,r;
			cin>>l>>r;
			auto ret=sg.query(l-1,r);
			rep(i,prime.size()){
				if(ret.second&(1LL<<i)){
					ret.first=ret.first*(mod+1-inv[prime[i]])%mod;
				}
			}
			printf("%lld\n",ret.first);
		}
		else {
			int l,r,x;
			cin>>l>>r>>x;
			sg.update(l-1,r,{x,bs[x]});
		}
	}
	return 0;
}