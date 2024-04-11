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
    string s; cin >> s;

    int n = size(s);

    vector dp(n, vector(2, 0));

    int len[2] = { 2, 3 };

    auto check = [&](int i, int x)
    {
        if (i + len[x] > n) return false;
        if (i + len[x] == n) return true;
        return dp[i + len[x]][x ^ 1] || (s.substr(i, len[x]) != s.substr(i + len[x], len[x]) && dp[i + len[x]][x]);
    };

    set<string> ans;

    for (int i = n - 1; i > 4; --i)
        for (int x = 0; x < 2; ++x)
            if (check(i, x))
            {
                dp[i][x] = 1;
                ans.insert(s.substr(i, len[x]));
            }

    cout << size(ans) << endl;

    for (auto r : ans) cout << r << endl;

    exit(0);
}