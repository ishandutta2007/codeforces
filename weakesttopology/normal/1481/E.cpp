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

template<typename T>
bool chmax(T& x, T y){ return x < y ? (x = y, true) : false; }

int main()
{ _
    int n;
    cin >> n;

    vector<int> l(n), r(n), f(n, 0), a(n);

    for (auto& x : a)
    {
        cin >> x;
        --x;
    }
    for (int i = 0; i < n; ++i) r[a[i]] = i;
    for (int i = n - 1; i >= 0; --i) l[a[i]] = i;

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i)
    {
        dp[i] = dp[i + 1];

        int x = a[i];

        f[x] += 1;

        chmax(dp[i], f[x]);

        if (i == l[x]) chmax(dp[i], f[x] + dp[r[x] + 1]);
    }

    int res = n - dp[0];

    cout << res << endl;

    exit(0);
}