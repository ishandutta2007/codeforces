#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 101000;

char s[N];


int c[330], n;

int main () {
//    freopen ("in", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mn = min (a, min (c, d));
    LL res = 0;
    a -= mn;
    c -= mn;
    d -= mn;
    res += 1LL * mn * 256;
    mn = min (a, b);
    res += 1LL * mn * 32;
    cout << res << endl;
}