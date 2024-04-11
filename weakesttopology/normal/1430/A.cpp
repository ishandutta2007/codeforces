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
    constexpr int N = 1000;

    array<int, N + 1> dp = { 0 }; dp [0] = 1;

    array<int, 3> v = { 3, 5, 7 };

    array<array<int, 3>, N + 1> ct; ct[0] = { 0, 0, 0 };

    for (int i = 0; i < 3; ++i)
    {
        int x = v[i];
        for (int y = 0; y + x <= N; ++y)
            if (y + x <= N && dp[y])
            {
                dp[y + x] = 1;
                ct[y + x] = ct[y];
                ct[y + x][i] += 1;
            }
    }


    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        if (dp[n])
        {
            cout << ct[n][0] << " " << ct[n][1] << " " << ct[n][2] << endl;
        }
        else
            cout << -1 << endl;
    }

    exit(0);
}