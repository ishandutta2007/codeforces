#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve()
{
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    vector rem(n, 0);
    for (int i = 1; i < n; ++i)
        if (s[i] == s[i - 1]) rem[i] = 1;

    for (int i = 0, j = 1; i < n; ++ans, j = max(j, i + 1))
    {
        while (j < n && not rem[j]) ++j;

        if (j < n) s[j++] = '*';
        else break;

        char c = s[i];

        while (i < n && (s[i] == '*' || s[i] == c)) s[i++] = '*';
    }

    // debug(s);
    // debug(ans);

    char c = '*';

    int add = 0;

    for (auto d : s)
        if (d != '*' && d != c) add += 1, c = d;

    ans += (add + 1) / 2;

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}