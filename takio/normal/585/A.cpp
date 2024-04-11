#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100010;
const LL INF = 1LL << 55;

LL a[N], b[N], c[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%I64d%I64d%I64d", &a[i], &b[i], &c[i]);
    }
    vector <int> res;
//    memset (vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
//        if (c[i] < 0) {
//            for (int j = 1; j <= n; j++) c[j] -= b[i];
//            continue;
//        }
        if (c[i] < 0) continue;
//        for (int j = 1; j <= n; j++) cout << c[j] << ' '; cout << endl;
        res.push_back(i);
        for (int j = i + 1; j <= n; j++) {
            if (c[j] >= 0) {
                if (a[i] > 0) c[j] -= a[i];
                a[i]--;
            }
        }
        while (1) {
            int flag = 0;
            for (int j = i + 1; j <= n; j++) if (c[j] < 0 && c[j] > -INF) {
                c[j] = -INF;
                for (int k = j + 1; k <= n; k++) c[k] -= b[j];
                flag = 1;
            }
            if (!flag) break;
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
}