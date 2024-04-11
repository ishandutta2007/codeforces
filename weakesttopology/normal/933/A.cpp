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

    vector<int> a(n);
    for (auto& x : a)
    {
        cin >> x;
        --x;
    }

    int ctzero = 0, ans = 0;

    for (int l = 0; l < n; ++l)
    {
        int ctones = 0;
        for (int r = l; r < n; ++r) ctones += a[r] == 1;

        vector<int> lis(n + 1, INF);
        lis[0] = -INF;

        for (int r = l; r < n; ++r)
        {
            auto iter = upper_bound(all(lis), -a[r]);
            int len = (int)distance(begin(lis), iter);
            lis[len] = -a[r];

            ctones -= a[r] == 1;

            ans = max(ans, ctzero + len + ctones);
        }
        ctzero += (a[l] == 0);
    }

    ans = max({ ans, ctzero, n - ctzero });

    cout << ans << endl;

    exit(0);
}