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
string s, sa, sb;

ll solve(string s) {
    // cout << "solve " << s << nl;
    ll i, a, b, al, bl, au, bu;
    a = 0; b = 0;
    for (i = 1; i <= n; i++) {
        if (i % 2) {
            if (s[i] == '1') a++;
        } else {
            if (s[i] == '1') b++;
        }

        // cout << "i, a, b = " << i _ a _ b << nl;

        al = a; bl = b;
        au = a + (n - i) / 2;
        bu = b + (n - i + 1) / 2;

        if (al > bu || au < bl) return i;
    }

    return n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> s; n = s.size(); s = '#' + s;
        sa = s; sb = s;
        for (i = 1; i <= n; i++) {
            if (i % 2) {
                if (sa[i] == '?') sa[i] = '1';
                if (sb[i] == '?') sb[i] = '0';
            } else {
                if (sa[i] == '?') sa[i] = '0';
                if (sb[i] == '?') sb[i] = '1';
            }
        }

        res = min(solve(sa), solve(sb));
        cout << res << nl;
    }

    return 0;
}