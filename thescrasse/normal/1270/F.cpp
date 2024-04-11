#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 200010
#define maxm 70000010
#define sq 300

int i, i1, j, k, k1, t, n, m, flag[10], a[maxn], b;
int ps[maxn], mp[maxm], sz, x, y, mn, mx;
ll res;
string s;
vector<int> v;

void solve(int x) {
    int i;
    // cout << "solve" _ x << nf;
    for (i = 1; i <= n; i++) mp[ps[i]] = 0;
    mp[n] = 1; ps[0] = n;
    for (i = 1; i <= n; i++) {
        if (a[i] == 0) ps[i] = ps[i - 1] - 1;
        else ps[i] = ps[i - 1] + x;
        res += (ll)mp[ps[i]]; mp[ps[i]]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> s; n = s.size(); s = '#' + s;

    for (i = 1; i <= n; i++) a[i] = (int)s[i] - '0';

    for (i = 0; i <= sq; i++) {
        solve(i);
        // cout << "solve" _ i _ res << nl;
    }

    v.pb(0);
    for (i = 1; i <= n; i++) {
        if (a[i] == 1) v.pb(i);
    }
    v.pb(n + 1);

    sz = (int)v.size() - 2;

    /* for (auto u : v) cout << u << ' ';
    cout << nl; */

    for (i = 1; i <= sz; i++) {
        // cout << "solve" _ i << nf;
        y = 0;
        for (j = v[i]; j <= v[min(sz, i + n / sq) + 1] - 1; j++) {
            mn = j - v[i] + 1; mx = j - v[i - 1];
            if (a[j] == 1) y++;
            mn = (mn + y - 1) / y; mx /= y;
            mn = max(mn, sq + 2);
            res += (ll)max(0, mx - mn + 1);
            // cout << "found" _ i _ j _ mn _ mx << nl;
        }
    }

    cout << res << nl;

    return 0;
}