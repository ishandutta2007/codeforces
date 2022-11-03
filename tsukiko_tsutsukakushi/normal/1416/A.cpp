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
private:
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
        return min(x,y);
        //return x+y;
        //return max(x,y);
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

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<int> b(n + 1, -1), d(n + 1, -1);
    rep(i, n) {
        chmax(d[a[i]], abs(i - b[a[i]]));
        b[a[i]] = i;
    }
    for(int i = 1; i <= n; ++ i) {
        if(d[i] != -1) chmax(d[i], abs(n - b[i]));
    }
    int res = inf;
    int j = -1;
    vector<int> ans(n + 1, inf);
    for(int i = 1; i <= n; ++ i) {
        if(d[i] != -1) {
            // cerr << i << " " << res << endl;
            chmin(ans[d[i]], i);
        }
    }
    for(int i = 1; i <= n; ++ i) {
        chmin(ans[i], ans[i - 1]);
    }
    for(int i = 1; i <= n; ++ i) {
        if(ans[i] == inf) ans[i] = -1;
    }
    SegmentTree<int> seg(a, inf);
    for(int k = n / 2 + 1; k <= n; ++ k) {
        if(ans[k] == -1) {
            ans[k] = seg.get(n - k, k);
        } else {
            chmin(ans[k], seg.get(n - k, k));
        }
    }
    for(int k = 1; k <= n; ++ k) {
        cout << ans[k] << " \n"[k == n];
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}