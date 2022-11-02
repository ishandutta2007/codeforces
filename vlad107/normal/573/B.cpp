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

int cnt[N], cnt2[N];
int n, h[N];

bool ok(int m) {
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < n; i++) {
        int ll = i + max(0, m - h[i]);
        int rr = i + m - 1;
        if (ll <= rr) {
            cnt[ll]++;
            cnt[rr + 1]--;
        }
//      cerr << i << " " << ll << " " << rr << endl;
    }
    for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int ll = i - m + 1;
        int rr = i - max(0, m - h[i]);
        ll = max(ll, 0);
        if (ll > rr) continue;
        rr = max(rr, 0);
        if (ll <= rr) {
            cnt2[ll]++;
            cnt2[rr + 1]--;
        }
//      cerr << i << " " << ll << " " << rr << endl;
    }
    for (int i = 1; i < n; i++) cnt2[i] += cnt2[i - 1];
    for (int i = 0; i < n; i++) {
        if (cnt[i] + cnt2[i] == m + m) {
//          cerr << i << " " << cnt[i] << " " << cnt2[i] << endl;
            return true;
        }
    }
    return false;
}   

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif 

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
//  cerr << ok(3) << endl;
//  return 0;
    int ll = 1, rr = n + n;
    while (ll < rr - 1) {
        int mid = (ll + rr) / 2;
        if (ok(mid)) {
            ll = mid;
        } else {
            rr = mid;
        }
    }
    printf("%d\n", ll);
}