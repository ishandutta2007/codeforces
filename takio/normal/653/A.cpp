#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 200100, M = 1000010, mod = 1e9 + 7;

int c[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &x);
        c[x] = 1;
    }
    for (int i = 1; i <= 1000; i++) if (c[i] && c[i + 1] && c[i + 2]) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
//    return
}