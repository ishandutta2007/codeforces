#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll q, tt, eq;
map<array<ll, 3>, ll> mp;
map<array<ll, 2>, ll> fc;
char c;

void add(ll a, ll b, ll c) {
    fc[{a, b}] = c; mp[{a, b, c}] = 1;
    if (fc[{b, a}] != 0) tt++;
    if (mp[{b, a, c}] == 1) eq++;
}

void rm(ll a, ll b) {
    ll c;
    c = fc[{a, b}]; mp[{a, b, c}] = 0; fc[{a, b}] = 0;
    if (fc[{b, a}] != 0) tt--;
    if (mp[{b, a, c}] == 1) eq--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q;
    while (q--) {
        cin >> c;
        if (c == '+') {
            cin >> a >> b >> c;
            add(a, b, (ll)c - 'a' + 1);
        } else if (c == '-') {
            cin >> a >> b;
            rm(a, b);
        } else if (c == '?') {
            cin >> k;
            if (k % 2) {
                if (tt > 0 || eq > 0) cout << "YES" << nl;
                else cout << "NO" << nl;
            } else {
                if (eq > 0) cout << "YES" << nl;
                else cout << "NO" << nl;
            }
            // cout << tt _ eq << nl;
        }
    }

    return 0;
}