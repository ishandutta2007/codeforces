#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans = 0, b = 0;

    vector buckets(0, 0);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'W') b = 1, ans += (i > 0 && s[i - 1] == 'W') ? 2 : 1;
        else if (b)
        {
            if (s[i - 1] == 'W') buckets.push_back(1);
            else ++buckets.back();
        }
    }

    if (not buckets.empty() && s.back() == 'L') buckets.pop_back();

    sort(all(buckets)); reverse(all(buckets));

    // debug(buckets.size());

    while (not buckets.empty() && k > 0)
    {
        int x = buckets.back();
        if (k >= x)
        {
            ans += 2 * x + 1, k -= x;
            buckets.pop_back();
        }
        else
        {
            ans += 2 * k, k = 0;
            break;
        }
    }

    vector endpaths(0, 0);

    for (int i = 0; i < n; ++i)
        if (s[i] == 'W')
        {
            endpaths.push_back(i);
            break;
        }

    for (int i = 0; i < n; ++i)
        if (s[n - 1 - i] == 'W')
        {
            endpaths.push_back(i);
            break;
        }

    if (b)
    {
        int y = min(k, endpaths[0]);
        if (y > 0) ans += 2 * y, k -= y;

        int x = min(k, endpaths[1]);
        if (x > 0) ans += 2 * x, k -= x;
    }
    else
    {
        if (k) ans = 2 * (k - 1) + 1;
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}