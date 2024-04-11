#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve()
{
    int n, T; cin >> n >> T;
    vector a(n, 0);
    for (auto& x : a) cin >> x;

    if (T & 1)
    {
        for (auto x : a) cout << (x & 1) << " ";
        cout << endl;
    }
    else
    {
        vector color(n, -1);
        for (int i = 0, b = 0; i < n; ++i)
        {
            if (a[i] < T / 2) color[i] = 0;
            else if (a[i] > T / 2) color[i] = 1;
            else
            {
                color[i] = b;
                b = !b;
            }
        }
        for (auto x : color) cout << x << " ";
        cout << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}