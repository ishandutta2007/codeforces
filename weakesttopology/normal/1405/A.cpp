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

void solve()
{
    int n; cin >> n;
    vector p(n, 0);
    for (int i = 0; i < n; ++i) cin >> p[i];
    reverse(all(p));
    for (int i = 0; i < n; ++i) cout << p[i] << " ";
    cout << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}