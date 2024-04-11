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

int main()
{ _
    constexpr int nmax = 60;

    int n; cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    if (n > nmax)
    {
        cout << 1 << endl;
        exit(0);
    }

    int ans = INF;

    map<int, int> cost;

    for (int i = 0; i < n; ++i)
    {
        int xor_sum = 0;
        for (int j = i; j < n; ++j)
        {
            xor_sum ^= a[j];
            cost[xor_sum] = INF;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i, xor_sum = 0; j < n; ++j)
        {
            xor_sum ^= a[j];
            for (auto [key, value] : cost)
            {
                if (key <= xor_sum) continue;
                ans = min(j - i + value, ans);
            }
        }
        for (int j = i, xor_sum = 0; j >= 0; --j)
        {
            xor_sum ^= a[j];
            cost[xor_sum] = min(cost[xor_sum], i - j);
        }
    }

    if (ans == INF) ans = -1;

    cout << ans << endl;

    exit(0);
}