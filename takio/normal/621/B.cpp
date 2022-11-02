#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 2100, M = 1050;
int a[N], b[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, cnt = 0, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x, &y);
        a[x + y]++;
        b[x - y + M]++;
    }
    LL res = 0;
    for (int i = 0; i < N; i++) {
        res += 1LL * a[i] * (a[i] - 1) / 2;
        res += 1LL * b[i] * (b[i] - 1) / 2;
    }
    cout << res << endl;
}