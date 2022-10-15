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

int main()
{ _
    int n; cin >> n;

    string s; cin >> s;

    stack<tuple<int, int, ll>> stk;

    stk.emplace(INF, -1, 0LL);

    ll ans = 0LL;

    for (int i = 0, sum = 0; i < n; ++i)
    {
        sum = s[i] == '1' ? sum + 1 : 0;

        while (sum >= get<0>(stk.top())) stk.pop();

        auto [ prv, idx, prefix ] = stk.top();

        ll cur = ll(sum) * ll(sum + 1) / 2 + ll((i - sum) - idx) * sum;

        if (idx != -1) cur += ll(sum) * (sum - 1) / 2;

        stk.emplace(sum, i, prefix + cur);

        ans += prefix + cur;
    }

    cout << ans << endl;

    exit(0);
}