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
template <typename T, typename F>
class SegmentTree {
  private:
    T e;
    F op;
    ll n;
    vector<T> dat;
 
  public:
    SegmentTree(F f, T _e, vector<T> v) : op(f), e(_e) {
        int _n = v.size();
        n = 1;
        while(n < _n)
            n *= 2;
        dat.resize(2 * n - 1, e);
        rep(i, _n)
        dat[n + i - 1] = v[i];
        for(int i = n - 2; i >= 0; i--)
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    SegmentTree(F f, T _e, int _n) : op(f), e(_e) {
        n = 1;
        while(n < _n)
            n *= 2;
        dat.resize(2 * n - 1, e);
        for(int i = n - 2; i >= 0; i--)
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while(i > 0) {
            i = (i - 1) / 2;
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    T get(int i) {
        i += n - 1;
        return dat[i];
    }
    T query(int l, int r) {
        //[l,r)
        T left = e, right = e;
        l += n - 1;
        r += n - 1;
        while(l < r) {
            if((l & 1) == 0)
                left = op(left, dat[l]);
            if((r & 1) == 0)
                right = op(dat[r - 1], right);
            l = l / 2;
            r = (r - 1) / 2;
        }
        return op(left, right);
    }
};

int main(){
    cin.tie(nullptr);
	cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+m);
    rep(i,m){
    	cin>>a[m-i-1];
    	--a[m-i-1];
    }
    rep(i,n)a[i+m]=i;
	int id = 0;
    auto op = [](int a, int b) {return a+b;};
	SegmentTree sg(op, id, n+m);
	vector<int> pre(n, -1);
	vector<int> mi(n), ma(n);
	rep(i,n)mi[i]=i;
	rep(i,n+m){
		ma[a[i]]=max(ma[a[i]],sg.query(pre[a[i]]+1, i));
		if(pre[a[i]]!=-1)sg.update(pre[a[i]],0);
		sg.update(i,1);
		pre[a[i]]=i;
		if(i<m)mi[a[i]]=0;
	}
	rep(i,n)cout<<mi[i]+1<<" "<<ma[i]+1<<endl;
    return 0;
}