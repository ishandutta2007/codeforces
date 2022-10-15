#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve()
{
    int n, q; cin >> n >> q;

    string s; cin >> s;

    for (int z = 0; z < q; ++z)
    {
        int l, r; cin >> l >> r; --l, --r;

        string ans = "NO";

        for (int i = 1; i + 1 < n; ++i)
        {
            int lcur = l;

            for (int j = 0; j < i && lcur <= r; ++j)
                if (s[j] == s[lcur]) ++lcur;

            int rcur = r;

            for (int j = n - 1; j > i && rcur >= l; --j)
                if (s[j] == s[rcur]) --rcur;

            if (lcur > rcur && lcur > l && rcur < r)
            {
                ans = "YES";
                break;
            }
        }

        cout << ans << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}