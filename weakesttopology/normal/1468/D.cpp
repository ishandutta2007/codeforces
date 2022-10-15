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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    --a, --b;

    vector<int> s(m);
    for (auto& x : s) cin >> x;
    sort(all(s));

    int cut = abs(a - b) + (a < b ? a : n - 1 - a);

    auto check = [&](int x)
    {
        for (int i = x; i >= 0; --i)
        {
            if (s[i] + (x - i) >= cut) return false;
        }
        return true;
    };

    int ans = -1;

    for (int z = m; z > 0; z >>= 1)
        while (ans + z < min(m, abs(a - b) - 1) && check(ans + z)) ans += z;

    ans += 1;

    return ans;
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}