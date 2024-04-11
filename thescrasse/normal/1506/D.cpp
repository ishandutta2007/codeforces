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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x, y;
map<ll, ll> mp;
multiset<ll> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; mp.clear(); s.clear();
        for (i = 1; i <= n; i++) {
            cin >> a[i]; mp[a[i]]++;
        }

        for (auto u : mp) s.insert(u.second);

        res = n;
        while (s.size() >= 2) {
            auto it = s.end(); it--;
            x = *(it); s.erase(s.find(x));
            it = s.end(); it--;
            y = *(it); s.erase(s.find(y));
            // cout << x _ y << nf;
            if (x - 1 != 0) s.insert(x - 1);
            if (y - 1 != 0) s.insert(y - 1);
            res -= 2;
        }

        cout << res << nl;
    }

    return 0;
}