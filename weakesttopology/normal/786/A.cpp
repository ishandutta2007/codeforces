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
    int n;
    cin >> n;

    vector<vector<int>> s(2);

    for (auto& v : s)
    {
        int k;
        cin >> k;
        v.resize(k);
        for (auto& x : v) cin >> x;
    }

    enum State { loop = 0, win, lose };

    vector<array<State, 2>> dp(n);
    vector<array<int, 2>> cnt(n);

    dp[0][0] = dp[0][1] = lose;

    queue<int> q[2];
    q[0].push(0), q[1].push(0);

    while (not empty(q[0]) || not empty(q[1]))
    {
        for (int t = 0; t < 2; ++t) if (not empty(q[t]))
        {
            int x = q[t].front();
            q[t].pop();
            for (auto d : s[t ^ 1])
            {
                int y = (x + n - d) % n;
                if (dp[y][t ^ 1] == loop)
                {
                    dp[y][t ^ 1] = win;
                    for (auto e : s[t])
                    {
                        int z = (y + n - e) % n;
                        if (dp[z][t] == loop && ++cnt[z][t] == size(s[t]))
                        {
                            dp[z][t] = lose;
                            q[t].push(z);
                        }
                    }
                }
            }
        }
    }

    for (int t = 0; t < 2; ++t)
    {
        for (int x = 1; x < n; ++x)
        {
            State st = dp[x][t];
            string res = st == win ? "Win" : (st == lose ? "Lose" : "Loop");
            cout << res << "\n "[x + 1 < n];
        }
    }



    exit(0);
}