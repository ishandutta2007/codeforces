#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 55;
int a[N][N], n, res[N];

int jug (int x, int y) {
    for (int i = 1; i <= n; i++) if (a[i][x] > y) return 0;
    for (int i = 1; i <= n; i++) if (a[x][i] > y) return 0;
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf ("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (res[j] == 0 && jug (j, i)) {
            res[j] = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) cout << res[i] <<' ';
}