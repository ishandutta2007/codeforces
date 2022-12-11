#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 507;
int ans[N][N];
int len[N][N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        ans[i][i] = len[i][i] = p;
    }
    for (int t = n; t > 1; t--) {
        int i = 1 + (n - t);
        int j = 1;
        while (len[i][j] != 1) {
            len[i + 1][j] = len[i][j] - 1;
            ans[i + 1][j] = ans[i][j];
            i++;
            j++;
        }
        i = n;
        j = t;
        while (len[i][j] != 1) {
            len[i][j - 1] = len[i][j] - 1;
            ans[i][j - 1] = ans[i][j];
            i--;
            j--;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}