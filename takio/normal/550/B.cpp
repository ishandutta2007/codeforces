#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

char s[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, l, r, x, a[20];
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0, sum = 0, mx = 0, mn = 1e9;
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            cnt++, sum += a[j], mx = max (mx, a[j]), mn = min (mn, a[j]);
        }
        if (cnt >= 2 && l <= sum && sum <= r && mx - mn >= x) res++;
    }
    cout << res <<endl;
}