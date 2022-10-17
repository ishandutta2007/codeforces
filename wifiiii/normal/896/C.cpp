#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fpow(ll a,ll b,ll mod){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
const int mod = 1e9 + 7;
int sd;
int rd() { int r = sd; sd = (1ll * sd * 7 + 13) % mod; return r; }
struct node {
    int l;
    mutable int r;
    mutable ll x;
    bool operator < (const node & n) const {
        return l < n.l;
    }
};
set<node> s;
set<node>::iterator split(int x) {
    auto it = --s.upper_bound({x});
    if(it->l == x) return it;
    node p = *it;
    it->r = x - 1, p.l = x;
    return s.insert(p).first;
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, vx;
    cin >> n >> m >> sd >> vx;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) a[i] = rd() % vx + 1;
    vector<node> vs;
    for(int i = 0, j; i < n; i = j) {
        j = i; while(j < n && a[i] == a[j]) ++j;
        vs.push_back({i, j - 1, a[i]});
    }
    s = set<node>(vs.begin(), vs.end());
    for(int i = 0; i < m; ++i) {
        int op = rd() % 4 + 1, l = rd() % n, r = rd() % n;
        if(l > r) swap(l, r);
        if(op == 1) {
            int x = rd() % vx + 1;
            auto itr = r + 1 == n ? s.end() : split(r + 1), it = split(l);
            for(; it != itr; ++it) it->x += x;
        } else if(op == 2) {
            int x = rd() % vx + 1;
            auto itr = r + 1 == n ? s.end() : split(r + 1), it = split(l);
            for(; it != itr; it = s.erase(it)) ;
            s.insert({l, r, x});
        } else if(op == 3) {
            int k = rd() % (r - l + 1) + 1;
            auto itr = r + 1 == n ? s.end() : split(r + 1), it = split(l);
            vector<pair<ll,ll>> b;
            for(; it != itr; ++it) {
                b.push_back({it->x, it->r - it->l + 1});
            }
            sort(b.begin(), b.end());
            ll ans = -1;
            for(auto [x, len] : b) {
                k -= len;
                if(k <= 0) {
                    ans = x;
                    break;
                }
            }
            cout << ans << '\n';
        } else {
            int x = rd() % vx + 1, y = rd() % vx + 1;
            auto itr = r + 1 == n ? s.end() : split(r + 1), it = split(l);
            ll ans = 0;
            for(; it != itr; ++it) {
                ans += (it->r - it->l + 1) * fpow(it->x, x, y) % y;
            }
            ans %= y;
            cout << ans << '\n';
        }
    }
}