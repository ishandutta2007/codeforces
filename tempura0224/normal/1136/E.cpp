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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

template<typename T>
struct LazySegmentTree{
private:
	int n;
	vector<T> node,lazy;
	T E0,E1;

	inline void updatef(T& lazy,T& value){
		lazy += value;
		//lazy = value;
		//lazy = max(lazy, value);
		//lazy = min(lazy, value);
	}
	inline void calculatef(T& node,T& lazy,int len){
		//node += lazy * len;
		node += lazy *len ;
		//node = lazy ;
	}
	inline T queryf(T& x,T& y){
		return x + y;
		//return x * y;
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
	int n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];
	ll k[n-1];
	rep(i,n-1)cin>>k[i];
	set<int> st;
	rep(i,n+1)st.insert(i);
	LazySegmentTree<ll> sg(a, 0, 0);
	int q;
	cin>>q;
	while(q--){
		char type;
		cin>>type;
		if(type=='s'){
			int l,r;
			cin>>l>>r;
			cout<<sg.query(l-1,r)<<"\n";
		}
		else {
			ll i,x;
			cin>>i>>x;
			--i;
			st.insert(i);
			auto itr=st.lower_bound(i);
			int cur=i;
			while(cur!=n){
				if(cur!=i)itr=st.erase(itr);
				else ++itr;
				int nxt=*itr;
				sg.update(cur,nxt,x);
				if(nxt==n)break;
				ll ret1=sg.query(nxt-1,nxt);
				ll ret2=sg.query(nxt,nxt+1);
				if(ret1+k[nxt-1]<=ret2){
					break;
				}
				x=ret1+k[nxt-1]-ret2;
				cur=nxt;
			}
		}
	}
	return 0;
}