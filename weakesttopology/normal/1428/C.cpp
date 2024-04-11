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
    string s; cin >> s;
    const int n = size(s);

    int bs = 0;

    vector rem(n, 0);

    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == 'A' && bs > 0)
        {
            rem[i] = 1;
            bs -= 1;
        }
        if (s[i] == 'B') ++bs;
    }

    int ans = 2 * accumulate(all(rem), 0) + (bs - (bs % 2));

    // for (int i = 0; i < n && not rem[i]; ++i)
    // {
    //     if (not rem[i] && s[i] == 'B') add += 1;
    // }

    // ans += add - (add % 2);

    return n - ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}