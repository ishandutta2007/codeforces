#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

const int N = 2e5 + 10;
int a[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i] - i] += a[i];
      ans = max(ans, cnt[a[i] - i]);
    }
    cout << ans << '\n';
}