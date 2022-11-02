#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 110000;
int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    while (cin >> n) {
//        cin >> n ;
        LL sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &a[i]);
            sum += a[i];
        }
        sort (a + 1, a + 1 + n);
        int c = sum / n;
        int d = sum % n;
        d = n - d;
        LL res = 0;
//        cout << c <<  ' ' << d << endl;
        for (int i = 1; i <= n; i++) {
            if (i <= d) res += abs (a[i] - c);
            else res += abs (a[i] - (c + 1));
        }
//        cout << res << endl;
        cout << res / 2 << endl;
    }
}