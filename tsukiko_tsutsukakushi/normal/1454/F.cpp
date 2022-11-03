/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
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

const ll inf = 1'000'000'007;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    map<ll, vector<int>> g;
    rep(i, n) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
    ll all = *max_element(all(a));
    if(g[all].size() >= 3) {
        cout << "YES\n";
        cout << g[all][1] << " " << 1 << " " << n - 1 - g[all][1] << "\n";
        return;
    }
    SegmentTree<ll> seg(a, inf);
    map<ll, int> left, right;
    vector<int> lma(n + 1, 0), rma(n + 1, 0);
    ll ma = 0;
    rep(i, n) {
        chmax(ma, a[i]);
        lma[i + 1] = ma;
        left[ma] = i + 1;
    }
    ma = 0;
    rep(i, n) {
        chmax(ma, a[n - 1 - i]);
        rma[i + 1] = ma;
        right[ma] = i + 1;
    }
    for(auto p: left) {
        ll m = p.fr;
        if(m == ma) continue;
        int col = p.sc;
        if(!right.count(m)) continue;
        int cor = right[m];
        int l = col, r = n - cor;
        if(l >= r) continue;
        if(seg.get(l, r) == m) {
            cout << "YES\n";
            cout << col << " " << n - col - cor << " " << cor << "\n";
            return;
        } else if(seg.get(l, r) > m) {
            if(a[l - 1] == m and col > 1 and lma[col - 1] == m) {
                cout << "YES\n";
                cout << col - 1 << " " << n - col - cor + 1 << " " << cor << "\n";
                return;
            }
            if(a[r] == m and cor > 1 and rma[cor - 1] == m) {
                cout << "YES\n";
                cout << col << " " << n - col - cor + 1 << " " << cor - 1 << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}