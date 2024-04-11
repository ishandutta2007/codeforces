#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 3010, mod = 1e9 + 7;

char s[10];
int c[2][400];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, a, b, t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%s%d%d", s, &a, &b);
        if (s[0] == 'F') t = 0;
        else t = 1;
        for (int j = a; j <= b; j++) {
            c[t][j]++;
        }
    }
    int r = 0;
    for (int i = 1; i <= 366; i++) r = max (r, min (c[0][i], c[1][i]));
    cout << r * 2 << endl;
}