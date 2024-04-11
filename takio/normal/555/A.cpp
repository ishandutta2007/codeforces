#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define pb push_back
using namespace std;

const int N = 100100;
int a[N], n, m;

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    int res = 2 * n - m - 1;
    for (int i = 1; i <= m; i++) {
        int c;
        scanf ("%d", &c);
        for (int j = 1; j <= c; j++) {
            scanf ("%d", &a[j]);
        }
        if (a[1] == 1) {
            for (int j = 2; j <= c; j++) {
                if (a[j] == a[j - 1] + 1) res -= 2;
                else break;
            }
        }
    }
    cout << res << endl;
}