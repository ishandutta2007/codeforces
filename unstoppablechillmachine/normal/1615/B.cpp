#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 2e5 + 10;
const int L = 18;
int pref[N][L];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < L; j++) {
            pref[i][j] = pref[i - 1][j] + ((i >> j) & 1);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        int ans = r - l;
        for (int bit = 0; bit < L; bit++) {
            ans = min(ans, (r - l + 1) - pref[r][bit] + pref[l - 1][bit]);
        }
        cout << ans << '\n';
    }
}