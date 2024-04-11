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
void chmax(T& x, T y) { x = max(x, y); }

int main()
{ _
    int n;
    cin >> n;

    vector<int> p(n);
    for (auto& x : p) cin >> x;

    vector<ll> b(n), dp(n, -LINF), best(n, -LINF);
    for (auto& x : b) cin >> x;

    stack<int> stk;

    ll prefix_max = 0;

    for (int i = 0; i < n; ++i)
    {
        ll removed_max = -LINF;
        while (not empty(stk) && p[stk.top()] > p[i])
        {
            chmax(removed_max, best[stk.top()]);
            stk.pop();
        }

        ll cur = -LINF;
        if (empty(stk)) cur = prefix_max + b[i];
        else
        {
            int j = stk.top();
            chmax(best[j], removed_max);
            chmax(cur, best[j] + b[i]);
            chmax(cur, dp[j]);
        }

        stk.push(i);

        best[i] = dp[i] = cur;
        prefix_max = max(prefix_max, cur);
    }

    ll res = dp[n - 1];

    cout << res << endl;

    exit(0);
}