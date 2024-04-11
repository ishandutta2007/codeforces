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
    scanf ("%s", s);
    n = strlen (s);
    if (n & 1) {
        cout << -1 << endl;
        return 0;
    }
    int c = 0, d = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') c++;
        if (s[i] == 'R') c--;
        if (s[i] == 'U') d++;
        if (s[i] == 'D') d--;
    }
    cout << (abs (c) + abs (d)) / 2;
}