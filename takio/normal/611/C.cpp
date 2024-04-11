#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 510;

char mp[N][N];
int sum[N][N], sumn[N][N], summ[N][N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf ("%s", mp[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (mp[i][j] == '.' && mp[i - 1][j] == '.') + (mp[i][j] == '.' && mp[i][j - 1] == '.');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sumn[i][j] = sumn[i][j - 1] + (mp[i][j] == '.' && mp[i][j - 1] == '.');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            summ[i][j] = summ[i - 1][j] + (mp[i][j] == '.' && mp[i - 1][j] == '.');
        }
    }
//    cout << sum[n][m] << endl;
    int q, a, b, c, d;
    cin >> q;
    while (q--) {
        scanf ("%d%d%d%d", &a, &b, &c, &d);
        printf ("%d\n", sum[c][d] - sum[c][b] - sum[a][d] + sum[a][b] + sumn[a][d] - sumn[a][b] + summ[c][b] - summ[a][b]);
//        cout << c << ' ' <<d <<' ' << sum[c][d] << endl;
    }
}