#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3007;
int cntl[N], cntr[N], a[N];

void solve() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        memset(cntl, 0, sizeof(cntl));
        memset(cntr, 0, sizeof(cntr));
        int pw = 0;
        for (int j = i + 1; j < n; j++) cntr[a[j]]++;
        for (int j = i + 1; j < n; j++) {
            pw -= cntr[a[j]] * cntl[a[j]];
            cntr[a[j]]--;
            pw += cntr[a[j]] * cntl[a[j]];
            if (a[i] == a[j]) res += pw;
            pw -= cntr[a[j]] * cntl[a[j]];
            cntl[a[j]]++;
            pw += cntr[a[j]] * cntl[a[j]];
        }
    }
    cout << res << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}