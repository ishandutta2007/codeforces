#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second

using namespace std;

const int N = 100100;

int a[N], b[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        res += a[i] / 10;
    }
//    cout << "x";
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= n && k >= i; j++) {
            if (a[j] % 10 == 10 - i) {
                k -= i;
                res++;
                a[j] = a[j] / 10 * 10 + 10;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        while (a[i] < 100 && k >= 10) {
            a[i] += 10;
            k -= 10;
            res++;
        }
    }
    cout << res << endl;
}