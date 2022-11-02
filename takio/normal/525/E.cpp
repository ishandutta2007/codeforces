#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define LL long long
#define pii pair <LL, int>
#define xx first
#define yy second
using namespace std;

const int N = 30;
int a[N], cnt[N];
int n, k, x, type, t[N], tn;
LL s, res, f[N];
map <pii, int> mp;

void dfs (int id, LL tsum, int tcnt) {
    if (tsum > s || tcnt > k) return;
    if (id == tn + 1) {
        if (type == 0) {
            mp[pii (tsum, tcnt)] ++;
//            cout << "1 " << tsum << ' ' << tcnt << endl;
        }
        else {
            for (int o = 0; o <= k - tcnt; o++) {
                res += mp[pii (s - tsum, o)];
            }
//            cout << "2 " << tsum << ' ' << tcnt << endl;
        }
        return;
    }
    dfs (id + 1, tsum, tcnt);
    dfs (id + 1, tsum + t[id], tcnt);
    if (t[id] <= 19) dfs (id + 1, tsum + f[t[id]], tcnt + 1);
}

void solve1 (int x) {
//    cout << x << endl;
    tn = 0;
    for (int i = x; i <= n; i++) {
        t[++tn] = a[i];
    }
    type = 0;
    dfs (1, 0, 0);
}

void solve2 (int x) {
    tn = 0;
    for (int i = 1; i <= x; i++) {
        t[++tn] = a[i];
    }
    type = 1;
    dfs (1, 0, 0);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    f[1] = 1;
    for (int i = 2; i <= 19; i++) f[i] = f[i - 1] * i;
//    cout << f[19] << ' ' << f[18] << ' ' << f[18] + f[19] << endl;
//    c[0][0] = 1;
//    for (int i = 1; i < 30; i++) {
//        for (int j = 0; j <= i; j++) {
//            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
//        }
//    }
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    int t = n / 2 + 1;
//    cout << t << endl;
    solve1(t);
    solve2(t - 1);
    cout << res << endl;
}
//const int N = 100100;
//int a[N];

//int main () {
////    freopen ("in.txt", "r", stdin);
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        scanf ("%d", &a[i]);
//    }
//    sort (a + 1, a + 1 + n);
//    LL res = 0, now = 1, cnt = 0;
//    for (int i = n; i >= 2; i--) {
//        if (a[i] == a[i - 1] || a[i] == a[i - 1] + 1) {
//            now *= a[i - 1];
//            if (++cnt == 2) {
//                res += now;
//                cnt = 0;
//                now = 1;
//            }
//            i--;
//        }
//    }
//    cout << res << endl;
//}