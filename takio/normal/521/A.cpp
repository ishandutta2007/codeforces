#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100, mod = 1e9 + 7;

char s[N];
int cnt[200];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, mx = 0, c = 0;
    cin >> n;
    scanf ("%s", s);
    for (int i = 0; s[i]; i++) {
        cnt[s[i]]++;
        mx = max (mx, cnt[s[i]]);
    }
    if (cnt['A'] == mx) c++;
    if (cnt['G'] == mx) c++;
    if (cnt['T'] == mx) c++;
    if (cnt['C'] == mx) c++;
    LL res = 1;
    for (int i = 1; i <= n; i++) (res *= c) %= mod;
    cout << res << endl;
}