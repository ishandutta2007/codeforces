#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 1001000;
const ULL M = 1LL << 33;
const double eps = 0;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    while (cin >> n >> m) {
        if (n < m) cout << -1;
        else if (n == m) cout << n;
        else {
            int t = n + m;
            int x = (int)((1.0 * t + 0.5) / m + eps);
            if (x % 2 == 1) x--;
            pii res = pii (t, x);
    //        cout << t <<' ' << x << ' ' << res << endl;
            t = n - m;
            x = (int)((1.0 * t + 0.5) / m + eps);
            if (x % 2 == 1) x--;
    //        cout <<x << endl;
            if (x) {
                if (res.first * x > res.second * t) res = pii (t, x);
    //            cout << t <<' ' << x << ' ' << res << endl;
            }
            printf ("%.12f\n", 1.0 * res.first / res.second);
        }
    }
}