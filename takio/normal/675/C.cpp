#include <bits/stdc++.h>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;
int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    map <LL, int> mp;
    int n, r = 0;
    LL sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        r = max (r, ++mp[sum += a[i]]);
    }
    cout << n - r << endl;
}