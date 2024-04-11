#include <bits/stdc++.h>
#define xx first
#define yy second
#define pii pair <int, int>
#define LL long long
using namespace std;

const int N = 200100, M = 2e9 + 1e8;
pii a[N];
int dp[N];
map <int, int> mp;

LL f (LL x) { return x & (-x); }

void add (LL x, int c) {
    while (x <= M) {
//        cout << x << endl;
        mp[x] = max (mp[x], c);
        x += f (x);
    }
}

int query (int x) {
    int res = 0;
    while (x > 0) {
//        cout << x << ' ' << mp[x] << endl;
        res = max (res, mp[x]);
        x -= f(x);
    }
    return res;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {scanf ("%d%d", &a[i].xx, &a[i].yy);}
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        int tmp = query(a[i].xx - a[i].yy + 1e9) + 1;
//        cout << i << ' ' << tmp << endl;
        mx = max (mx, tmp);
        add(a[i].xx + a[i].yy + 1e9, tmp);
    }
    cout << mx << endl;
}