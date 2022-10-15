#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        --x;
    }
    a.erase(unique(all(a)), end(a));
    n = (int)size(a);
    a.push_back(n);

    vector<int> dp(n, INF);
    int prefmin = 1, res = n;

    for (int i = 1, last = a[0]; i < n; ++i) {
        int x = a[i];
        int cur = min(prefmin + 1, dp[x]) + i - 1;
        res = min(res, cur + n - (i + 1));
        dp[last] = min(dp[last], cur - i);
        prefmin = min(prefmin, cur - i);
        last = x;
    }

    cout << res << endl;

    exit(0);
}