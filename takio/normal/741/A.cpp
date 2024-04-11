#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 110;
int a[N], c[N], vis[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        if (++c[a[i]] > 1) {
            printf ("-1");
            return 0;
        }
    }
    long long res = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int u = a[i], c = 1;
        vis[u] = 1;
        while (u != i) {
            u = a[u], c++;
            vis[u] = 1;
        }
        if (c % 2 == 0) c /= 2;
        res = res / __gcd  ((LL)c, res) * c;
    }
    cout << res << endl;
}