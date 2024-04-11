#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Line {
    ll x, y;
    mutable ll k;
    bool operator<(const Line& rhs) const { return x < rhs.x; }
    bool operator<(ll rhs) const { return k < rhs; }
};
struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = numeric_limits<ll>::max();
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator a, iterator b) {
        if (b == end()) return a->k = inf, 0;
        if (a->x == b->x) a->k = a->y > b->y ? -inf : inf;
        else a->k = div(b->y - a->y, b->x - a->x);
        return a->k >= b->k;
    }
    void add(ll x, ll y) {
        auto c = insert({x, y, 0}), b = c++, a = b;
        while (isect(b, c)) c = erase(c);
        if (a != begin() && isect(--a, b)) isect(a, b = erase(b));
        while ((b = a) != begin() && (--a)->k >= b->k) isect(a, erase(b));
    }
    ll query(ll k) {
        assert(!empty());
        auto r = *lower_bound(-k);
        return r.x * k + r.y;
    }
};

const int inf = 1e9;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    ++n, ++m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> h(n, vector<int>(m, inf));
    for(int i = 0; i < m; ++i) {
        int lst = -1;
        for(int j = 0; j < n; ++j) {
            if(a[j][i] == '1') lst = j;
            if(lst != -1) h[j][i] = min(h[j][i], (j - lst) * (j - lst));
        }
        lst = -1;
        for(int j = n - 1; j >= 0; --j) {
            if(a[j][i] == '1') lst = j;
            if(lst != -1) h[j][i] = min(h[j][i], (j - lst) * (j - lst));
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        LineContainer lc;
        for(int j = 0; j < m; ++j) {
            lc.add(-2 * j, j * j + h[i][j]);
        }
        for(int j = 0; j < m; ++j) {
            int k = lc.query(j);
            ans += k + j * j;
        }
    }
    cout << ans << '\n';
}