#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 3010, mod = 1e9 + 7;

char s[110][110];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf ("%s", s[i] + 1);
    int r = 0;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 'C') c++;
        }
        r += c * (c - 1) / 2;
    }
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = 1; j <= n; j++) {
            if (s[j][i] == 'C') c++;
        }
        r += c * (c - 1) / 2;
    }
    cout << r << endl;
}