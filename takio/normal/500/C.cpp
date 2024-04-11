#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define LL long long

using namespace std;

const int N = 100100;

int a[N], b[N], c[N], cn, vis[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if (!vis[b[i]]) {
            vis[b[i]] = 1;
            c[++cn] = b[i];
        }
    }
    int res = 0;
    for (int k = 1; k <= m; k++) {
//        int now = b[k];
        for (int i = 1; i <= cn; i++) {
            if (c[i] == b[k]) {
                int tmp = c[i];
                for (int j = i - 1; j >= 1; j--) {
                    c[j + 1] = c[j];
                }
                c[1] = tmp;
                break;
            }
            res += a[c[i]];
        }
//        for (int i = 1; i <= cn; i++) cout << c[i]; cout << endl;
    }
    cout << res;
}