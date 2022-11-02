#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5e5;
const int INF = 1e9 + 19;

int f[N];
int n;
vector<int> g[N];
int a[N], b[N], cnt[N];

int gcd(int x, int y) {
    while ((x != 0) && (y != 0)) {
        if (x > y) x %= y; else y %= x;
    }
    return x + y;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // scanf("%d", &n);
    // for (int i = 1; i < n; i++) {
    //  for (int j = 0; j < n; j++) f[j] = -1;
    //  int cnt = 0;
    //  for (int j = 0; j < n; j++) {
    //      if (f[j] == -1) {
    //          int x = j;
    //          while (f[x] == -1) {
    //              f[x] = cnt;
    //              x = (x + i) % n;
    //          }
    //          ++cnt;
    //      }
    //  }
    //  for (int j = 0; j < n; j++) cerr << f[j] << " ";
    //  cerr << endl;
    // }
    scanf("%d", &n);
    // n = 2e5;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    // for (int i = 0; i < n; i++) a[i] = 1;
    for (int i = 1; i < n; i++) {
        int x = gcd(i, n);
        g[x].pb(i);
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (!g[i].empty()) {
            for (int j = 0; j < i; j++) {
                int x = j;
                int mx = 0;
                for (int it = 0; it < n / i; it++) {
                    mx = max(mx, a[x]);
                    x += i;
                    if (x >= n) x -= n;
                }
                x = j;
                for (int it = 0; it < n / i; it++) {
                    b[x] = (a[x] == mx);
                    x += i;
                    if (x >= n) x -= n;
                }
            }
            for (int j = 0; j <= n; j++) cnt[j] = 0;
            for (int j = n; j < n + n; j++) b[j] = b[j - n];
            b[n + n - 1] = 0;
            for (int j = n + n - 2; j >= 0; j--) {
                if (b[j] == 0) continue;
                b[j] = b[j + 1] + 1;
                if (b[j] >= n) b[j] = n;
                if (j < n) cnt[b[j]]++;
            }
            for (int j = 1; j <= n; j++) cnt[j] += cnt[j - 1];
            for (int it = 0; it < (int)g[i].size(); it++) {
                int x = g[i][it];
                ans += cnt[n] - cnt[x - 1];
            }
        }
    }
    cout << ans << endl;
}