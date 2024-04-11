#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, a, cnt = 0;
    cin >> n;
    LL res = 0;
    int mn = 2e9;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        if (a & 1) {
            cnt++;
            mn = min (mn, a);
        }
        res += a;
    }
    if (cnt & 1) res -= mn;
    cout << res << endl;
}