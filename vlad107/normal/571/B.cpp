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

using namespace std;

const int N = 5e5;
const int INF = 2e9 + 5;

int n, k, a[N], cnt[N];
long long f[N], ff[N];

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif 

  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    //n = 3e5 - 1;
  //  k = 5e3;
//    for (int i = 0; i < n; i++) a[i] = rand() % 1000000000 - 500;
    sort(a, a + n);
    int d = n / k;
    int e = n % k;
    for (int i = 0; i <= n; i++) {
        f[i] = INF;
        ff[i] = INF;
    }
    ff[0] = 0;
    for (int i = 0; i <= e; i++) {
        for (int j = i; j <= n; j += d) {
            f[j] = ff[j];
            ff[j] = INF;
        }
        for (int j = i; j <= n - d; j += d) {
            if (f[j] == INF) continue;
//          int j = v[jj];
            long long cur = f[j] - a[j];
            if (cur + a[j + d - 1] < f[j + d]) f[j + d] = cur + a[j + d - 1];
            if ((j + d + 1 <= n) && (cur + a[j + d] < ff[j + d + 1])) {
                ff[j + d + 1] = cur + a[j + d];
            }
        }
        if (i == e) break;
    }
    cout << f[n] << endl;
}