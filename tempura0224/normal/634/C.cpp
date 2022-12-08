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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

template<typename T>
struct SegmentTree{
private:
	int n;
	ll MAX;
	T E;
	vector<T> node;
	inline void updatef(T& x,T& y){
		x = min(x+y,MAX);
	}
	inline T queryf(T& x,T& y){
		//return x*y;
		return x+y;
	}

public:
	SegmentTree(int sz,T E_, int MAX):E(E_),MAX(MAX){
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
	int n,k,a,b,q;
	cin>>n>>k>>a>>b>>q;
	SegmentTree<ll> sga(n+1,0,a), sgb(n+1,0,b);
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int x,y;
			cin>>x>>y;
			--x;
			sga.update(x,y);
			sgb.update(x,y);
		}
		else {
			int d;
			cin>>d;
			--d;
			cout<<sgb.get(0,d)+sga.get(d+k,n)<<"\n";
		}
	}
	
	return 0;
}