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
    int n; cin >> n;
    vector a(3, vector(n, 0));
    for (int z = 0; z < 3; ++z)
        for (auto& x : a[z]) cin >> x;

    vector p(n, -1);
    for (int i = 0; i < n; ++i)
    {
        int z = 0;
        while (a[z][i] == p[(i + n - 1) % n] || a[z][i] == p[(i + 1) % n]) ++z;
        p[i] = a[z][i];
    }
    for (auto x : p) cout << x << " ";
    cout << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}