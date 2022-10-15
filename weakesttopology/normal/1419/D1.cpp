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

int main()
{ _
    int n; cin >> n;
    vector a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    for (int i = 0; i + 1 < n; i += 2) swap(a[i], a[i + 1]);
    int ans = 0;
    for (int i = 1; i + 1 < n; i += 2) ans += a[i] < min(a[i - 1], a[i + 1]);
    cout << ans << endl;
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
    exit(0);
}