#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 3e5 + 5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n;
bool mag[N];

int ask(int l1, int r1, int l2, int r2) {
    cout << "? " << r1 - l1 + 1 << " " << r2 - l2 + 1 << endl;
    rep(i, l1, r1) cout << i << " ";
    cout << endl;
    rep(i, l2, r2) cout << i << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T--) {
        memset(mag, 0, sizeof mag);
        cin >> n;
        int k = 2;
        while (k <= n && ask(1, k - 1, k, k) == 0)
            k++;
        assert(k <= n);
        mag[k] = true;

        int l = 1, r = k - 1;
        while (l < r) {
            int mid = l + r >> 1;
            ask(l, mid, k, k) ? r = mid : l = mid + 1;
        }
        mag[l] = true;

        rep(i, k + 1, n) mag[i] = ask(k, k, i, i);
        cout << "! ";
        int ans = 0;
        rep(i, 1, n) ans += (!mag[i]);
        cout << ans << " ";
        rep(i, 1, n) if (!mag[i]) cout << i << " ";
        cout << endl;
    }
    return 0;
}