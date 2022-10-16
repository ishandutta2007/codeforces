#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp>
#include <stdint.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define rsz resize
#define mp make_pair

#define sz(x) ((int)(x).size())
#define all(x)  (x).begin(),  (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

using ld = double;
using cd = complex<ld>;
using vcd = vector<cd>;

template<class T> using ordered_set = tree<T, null_type, less<T>,
                         rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

const int INF = 1e9;
const int MOD = 998244353;

void test() {
    set<int> s;
    for(int i = 0; i < 20; ++i) {
        bool found = false;
        int ta=-1, tb=-1, tc=-1;
        for(int a = 1; !found && a < 1000; ++a)
        for(int b = 1; !found && b < 1000; ++b)
        for(int c = 1; !found && c < 1000; ++c)
            if((a^b^c) == 0 && !s.count(a) && !s.count(b) && !s.count(c))
                found = 1, ta = a, tb = b, tc = c;
        cout << bitset<8>(ta) << ' ' << bitset<8>(tb) << ' ' << bitset<8>(tc) << endl;
        s.insert(ta), s.insert(tb), s.insert(tc);
    }
}

void solve() {
    ll x; cin >> x; --x; int y = x%3; x /= 3;
    ll a = 0, b = 0, c = 0, d = 1; int k = 0;
    while(x >= d) x -= d, d *= 4LL, ++k;
    a |= 1LL << 2*k; a |= x;
    b |= 2LL << 2*k;
    vector<ll> dig { 0, 2, 3, 1 };
    for(int t = 0; x != 0; t += 2, x /= 4)
        b |= dig[x%4] << t;
    c = a ^ b;
    cout << (y ? y>1 ? c : b : a) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >>t; while(t--) solve();
}