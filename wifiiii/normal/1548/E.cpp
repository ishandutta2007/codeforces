#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct BIT {
    vector<T> a;
    int n;
    BIT() {}
    BIT(int _n) {n=_n+1;a.resize(n+1);}
    void init(int _n) {n=_n+1;a.resize(n+1);}
    void add(int x,T v){++x;for(;x<=n;x+=x&-x)a[x]+=v;}
    T sum(int x) {++x;x=min(x,n);T ret=0;for(;x;x-=x&-x)ret+=a[x];return ret;}
};

struct node {
    int a, b, t;
    bool operator < (const node & n) const {
        return a < n.a || (a == n.a && t < n.t);
    }
};
int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];
    for(auto &i : a) i = min(i, x);
    for(auto &i : b) i = min(i, x);
    auto calc = [](vector<int> a) {
        int n = a.size();
        vector<int> b(n, -1), c(n, -1);
        vector<int> stk(n); int tp = 0;
        for(int i = 0; i < n; ++i) {
            int mx = -1;
            while(tp && a[stk[tp-1]] > a[i]) {
                mx = max(mx, a[stk[tp-1]]);
                mx = max(mx, b[stk[tp-1]]);
                --tp;
            }
            if(tp) b[i] = mx;
            else b[i] = 1e9;
            stk[tp++] = i;
        }
        tp = 0;
        for(int i = n - 1; i >= 0; --i) {
            int mx = -1;
            while(tp && a[stk[tp-1]] >= a[i]) {
                mx = max(mx, a[stk[tp-1]]);
                mx = max(mx, c[stk[tp-1]]);
                --tp;
            }
            if(tp) c[i] = mx;
            else c[i] = 1e9;
            stk[tp++] = i;
        }
        for(int i = 0; i < n; ++i) b[i] = min(b[i], c[i]);
        return b;
    };
    vector<int> c = calc(a), d = calc(b);
    vector<node> vec;
    for(int i = 0; i < n; ++i) {
        if(c[i] > a[i]) vec.push_back({a[i], c[i], 0});
    }
    for(int i = 0; i < m; ++i) {
        if(d[i] > b[i]) vec.push_back({x - d[i], x - b[i], 1});
    }
    ll ans = 0;
    sort(vec.begin(), vec.end());
    BIT<int> bit(200005);
    for(auto &p : vec) {
        if(p.t == 0) {
            ans += bit.sum(p.b - 1) - bit.sum(p.a - 1);
        } else {
            bit.add(p.b, 1);
        }
    }
    cout << ans << endl;
}