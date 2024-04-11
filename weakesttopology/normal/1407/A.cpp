#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector a(n, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int sum = accumulate(all(a), 0);
        vector ans(0, 0);
        if (sum <= n / 2)
        {
            for (int i = 0; i < n; ++i)
                if (a[i] == 0) ans.push_back(i);
        }
        else
        {
            sum -= min(sum & 1, n / 2);
            for (int i = 0; i < n; ++i)
                if (a[i] == 1 && sum) ans.push_back(i), --sum;
        }
        cout << sz(ans) << endl;
        for (auto i : ans) cout << a[i] << " ";
        cout << endl;
    }
    exit(0);
}