#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

int vis[3100];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k, w;
    cin >> k >> n >> w;
    int all = (w + 1) * w / 2 * k;
    if (all <= n) {
        cout << 0;
    } else {
        cout << all - n;
    }
}