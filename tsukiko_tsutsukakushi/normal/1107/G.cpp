/**
 *    author:  otera    
**/
#include<iostream>
#include<string> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm> 
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>
struct SegmentTree{
    int n;
    T E;
    vector<T> node;
    inline void updatef(T& x,T& y){
        x = y;
        //x += y;
        //x = max(x,y);
        //x = min(x,y);
    }
    inline T queryf(T& x,T& y){
        //return min(x,y);
        //return x+y;
        return max(x,y);
    }

    // SegmentTree(int sz,T E_):E(E_){
    //     n=1;
    //     while(n<sz)n<<=1;
    //     node.resize(2*n-1,E);
    // }

    // SegmentTree(vector<T>& A,T E_):E(E_){
    //     int sz=A.size();
    //     n=1;
    //     while(n<sz)n<<=1;
    //     node.resize(2*n-1,E);
    //     rep(i,sz)node[i+n-1]=A[i];
    //     for(int i=n-2;i>=0;--i){
    //         node[i]=queryf(node[2*i+1], node[2*i+2]);
    //     }
    // }
    void init(vector<T>& A,T E_) {
        E = E_;
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

int n, a;
vector<int> d, c;
vector<P> diff;
vector<P> ac;

SegmentTree<P> diff_, ac_sum, ac_sum_ms;

int solve(int l, int r) {
    if(l >= r) return 0LL;
    if(l + 1 == r) return max(0LL, a - c[l]);
    int mid = diff_.get(l, r - 1).sc;
    int ret = max(solve(l, mid + 1), solve(mid + 1, r));
    int ac_s = ac_sum.get(mid + 2, r + 1).fr + ac_sum_ms.get(l, mid + 1).fr;
    chmax(ret, ac_s - diff[mid].fr);
    return ret;
}

void solve() {
	cin >> n >> a;
    d.resize(n), c.resize(n), diff.resize(n - 1), ac.assign(n + 1, P{0, 0});
    rep(i, n) {
        cin >> d[i] >> c[i];
    }
    rep(i, n - 1) {
        diff[i].fr = (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
        diff[i].sc = i;
    }   
    rep(i, n) {
        ac[i + 1].fr = ac[i].fr + a - c[i];
        ac[i + 1].sc = i + 1;
    }
    diff_.init(diff, P{-INF, -INF});
    ac_sum.init(ac, P{-INF, -INF});
    rep(i, n + 1) {
        ac[i].fr = -ac[i].fr;
    }
    ac_sum_ms.init(ac, P{-INF, -INF});
    cout << solve(0, n) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}