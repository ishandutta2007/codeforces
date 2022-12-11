#include <iostream>
#define int long long

using namespace std;

const int N = 1e5 + 7;
int a[N];

void solve() {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    int pos = 0, mv = -1, maxi = -1;
    while (pos < n) {
        if (a[pos] > maxi) {
            maxi = a[pos];
            mv = pos;
        }
        if (s >= a[pos]) {
            s -= a[pos];
            pos++;
        } else break;
    }
    if (pos == n) mv = -1;
    cout << mv + 1 << "\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}