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

int solve()
{
    int n; cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto get = [&](int i)
    {
        if (i <= 0 || i >= n - 1) return 0;
        int res = 0;
        res += max(a[i - 1], a[i + 1]) < a[i];
        res += min(a[i - 1], a[i + 1]) > a[i];
        return res;
    };

    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += get(i);

    int ans = cnt;

    vector<int> candidates;
    for (int i = 0; i < n; ++i)
    {
        int prv = a[i];

        for (int j = max(0, i - 1); j <= min(i + 1, n - 1); ++j)
        {
            cnt -= get(j);
            for (int x = a[j] - 1; x <= a[j] + 1; ++x)
                candidates.push_back(x);
        }

        for (auto x : candidates)
        {
            a[i] = x;
            for (int j = max(0, i - 1); j <= min(i + 1, n - 1); ++j)
                cnt += get(j);
            ans = min(ans, cnt);
            for (int j = max(0, i - 1); j <= min(i + 1, n - 1); ++j)
                cnt -= get(j);
        }
        candidates.clear();

        a[i] = prv;

        for (int j = max(0, i - 1); j <= min(i + 1, n - 1); ++j)
            cnt += get(j);
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}