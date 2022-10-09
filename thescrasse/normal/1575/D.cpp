#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
string s;
vector<ll> v;

void count(vector<ll> v) {
    ll i, r = 1;
    for (i = 1; i <= n; i++) {
        if (v[i] != -1) continue;
        if (i == 1) r *= 9;
        else r *= 10;
    }
    res += r;
}

void solve(vector<ll> v, ll x) {
    ll i, a, b, f = 0;

    if (v[1] == -2 && x == 0) return;
    for (auto &u : v) {
        if (u == -2) {
            u = x; f = 1;
        }
    }

    if (f == 0 && x != 1) return;

    a = v[n - 1]; b = v[n];
    if ((a == 0 || a == -1) && (b == 0 || b == -1) && n >= 3) {
        v[n - 1] = 0; v[n] = 0; count(v);
    }
    if ((a == 2 || a == -1) && (b == 5 || b == -1)) {
        v[n - 1] = 2; v[n] = 5; count(v);
    }
    if ((a == 5 || a == -1) && (b == 0 || b == -1)) {
        v[n - 1] = 5; v[n] = 0; count(v);
    }
    if ((a == 7 || a == -1) && (b == 5 || b == -1)) {
        v[n - 1] = 7; v[n] = 5; count(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> s; n = s.size();

    if (s == "0" || s == "X" || s == "_") {
        cout << 1 << nl; return 0;
    }
    if (n == 1) {
        cout << 0 << nl; return 0;
    }

    v.pb(-1);
    for (auto u : s) {
        if (u == 'X') v.pb(-2);
        else if (u == '_') v.pb(-1);
        else v.pb((ll)u - '0');
    }

    for (i = 0; i <= 9; i++) solve(v, i);

    cout << res << nl;

    return 0;
}