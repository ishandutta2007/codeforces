#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 200020, mod = 1e9 + 7;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, b, p;
    cin >> n >> b >> p;
    int res1 = 0, res2 = n * p;
    while (n > 1) {
        int t = 1;
        while (t * 2 <= n) t *= 2;
        t /= 2;
        res1 += t * (2 * b + 1);
        n -= t;
//        cout << n << endl;
    }
    cout << res1 << ' ' <<res2;
}