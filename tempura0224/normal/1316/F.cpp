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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;


struct dp{
	ll ans, plus, minus;
};

template<typename T, typename S>
struct LazySegmentTree{
private:
	int n;
	vector<T> node;
	vector<S> lazy;
	T E0;
	S E1;

	inline void updatef(S& lazy,S& value){
		lazy.first = lazy.first*value.first%mod;
		lazy.second = lazy.second*value.second%mod;
		//lazy = value;
		//lazy = max(lazy, value);
		//lazy = min(lazy, value);
	}
	inline void calculatef(T& node,S& lazy,int len){
		//node += lazy * len; //sum
		// node += lazy ; //max
		node.plus = node.plus*lazy.first%mod;
		node.minus = node.minus*lazy.second%mod;
	}
	inline T queryf(T& x,T& y){
		T res;
		res.ans =(x.ans + y.ans + x.plus*y.minus)%mod;
		res.plus = (x.plus + y.plus)%mod;
		res.minus = (x.minus + y.minus)%mod;
		return res;
	}
public:
	LazySegmentTree(int sz,T nodeE,S lazyE ):E0(nodeE), E1(lazyE){
		n=1;
		while(n<sz)n<<=1;
		node.resize(2*n-1,E0);
		lazy.resize(2*n-1,E1);
	}

	LazySegmentTree(vector<T>& v,T E0,S E1 ):E0(E0),E1(E1){
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

	void update(int a, int b, S x,int k=0,int l=0,int r=-1){
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

	void update2(int a, int b, T x,int k=0,int l=0,int r=-1){
		if(r<0)r=n;
		eval(k,l,r);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			node[k] = x;
		}
		else {
			update2(a,b,x,2*k+1,l,(l+r)/2);
			update2(a,b,x,2*k+2,(l+r)/2,r);
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

template<typename T>
struct SegmentTree{
private:
	int n;
	T E;
	vector<T> node;
	inline void updatef(T& x,T& y){
		x = y;
	}
	inline T queryf(T& x,T& y){
		return x+y;
	}

public:
	SegmentTree(int sz,T E_):E(E_){
		n=1;
		while(n<sz)n<<=1;
		node.resize(2*n-1,E);
	}

	SegmentTree(vector<T>& A,T E_):E(E_){
		int sz=A.size();
		n=1;
		while(n<sz)n<<=1;
		node.resize(2*n-1,E);
		rep(i,sz)node[i+n-1]=A[i];
		for(int i=n-2;i>=0;--i){
			node[i]=queryf(node[2*i+1], node[2*i+2]);
		}
	}
	void update(int k,T x){
		k+=n-1;
		updatef(node[k],x);
		while(k>0){
			k=(k-1)/2;
			node[k]=queryf(node[2*k+1], node[2*k+2]);
		}
	}
	   //[a,b)
	T get(int a,int b,int k=0,int l=0,int r=-1){
		if(r<0)r=n;
		if(r<=a||b<=l)return E;
		if(a<=l&&r<=b)return node[k];
		T xl=get(a,b,2*k+1,l,(l+r)/2);
		T xr=get(a,b,2*k+2,(l+r)/2,r);
		return queryf(xl, xr);
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];
	int q;
	cin>>q;
	vector<int> x(q);
	rep(i,q){
		cin>>x[i];
		--x[i];
		int y;cin>>y;
		a.push_back(y);
	}
	vector<int> ord(n+q);
	rep(i,n+q)ord[i]=i;
	sort(ord.begin(),ord.end(),[&](int x,int y){
		return a[x]<a[y];
	});
	vector<int> inv(n+q);
	rep(i,n+q)inv[ord[i]]=i;
	SegmentTree<int> sg(n+q,0);
	vector<int> cur(n);
	LazySegmentTree<dp,pair<ll,ll>> lsg(n+q,{0,0,0},{1,1});
	rep(i,n){
		cur[i]=inv[i];
		sg.update(inv[i],1);
	}
	vector<ll> plus(n+q+1),minus(n+q+1);
	plus[0]=minus[0]=1;
	rep(i,n+q){
		plus[i+1]=plus[i]*2%mod;
		minus[i+1]=minus[i]*(mod+1)/2%mod;
	}
	rep(i,n){
		int t = sg.get(0,cur[i]+1);
		lsg.update2(cur[i],cur[i]+1,{0,a[i]*plus[t]%mod,a[i]*minus[t]%mod});
	}
	cout<<lsg.query(0,n+q).ans*minus[1]%mod<<"\n";
	rep(i,q){
		int idx = cur[x[i]];
		lsg.update2(idx,idx+1,{0,0,0});
		lsg.update(idx,n+q,{minus[1],plus[1]});
		sg.update(idx,0);
	
		idx = inv[n+i];
		sg.update(idx,1);
		int t = sg.get(0,idx+1);
		lsg.update(idx,n+q,{plus[1],minus[1]});
		lsg.update2(idx,idx+1,{0,a[n+i]*plus[t]%mod,a[n+i]*minus[t]%mod});
		cout<<lsg.query(0,n+q).ans*minus[1]%mod<<"\n";
		cur[x[i]]=idx;
	}

	return 0;
}