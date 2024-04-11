#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <ctime>
#define LL long long
#define pii pair <int, int>
#define ULL unsigned long long
using namespace std;

const int N = 10;
int a[N], t[N];
double res;
int n, k, tmp;

void rev (int l, int r) {
    memcpy (t, a, sizeof a);
    for (int i = l, j = r; i <= r; i++, j--) {
        a[i] = t[j];
    }
}

void dfs (int kk) {
//    cout << k << endl;
    if (kk == k + 1) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] > a[j]) cnt++;
            }
        }
//        cout << cnt << ' ' << tmp << endl;
        res += 1.0 * cnt / tmp;
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            rev (i, j);
            dfs (kk + 1);
            rev (i, j);
        }
    }
}

int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    tmp = 1;
    for (int i = 1; i <= k; i++) tmp *= (n + 1) * n / 2;
    dfs (1);
    printf ("%.12f", res);
}