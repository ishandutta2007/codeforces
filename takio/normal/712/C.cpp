#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 100100, eps = 1e-6;
char s[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    int x, y;
    cin >> x >> y;
    int a = y, b = y, c = y, res = 0;
    while (a != x || b != x || c != x) {
//        cout << a << ' ' << b << ' ' << c << endl;
        res++;
        int ta = max (a, max (b, c)), tc = min (a, min (b, c));
        b = a + b + c - ta - tc;
        a = ta, c = tc;
        c = min (a + b - 1, x);
    }
    cout << res;
}