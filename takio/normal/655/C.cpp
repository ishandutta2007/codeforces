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

const int N = 200100;

char s[N];
int sum[N], n;

int getl (int x, int d) {
    if (sum[x - 1] < d) return -1;
    int l = 1, r = x;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (sum[x - 1] - sum[m - 1] >= d) l = m;
        else r = m;
    }
    return l;
}
int getr (int x, int d) {
    if (sum[n] - sum[x] < d) return -1;
    int l = x, r = n;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (sum[m] - sum[x] >= d) r = m;
        else l = m;
    }
    return r;
}

int gets (int x) {
    if (x < 0) return 0;
    if (x > n) return sum[n];
    return sum[x];
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int k;
    cin >> n >> k;
    scanf ("%s", s + 1);
    int cnt = 0, res = n;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] == '0');
    for (int i = 1; i <= n; i++) if (s[i] == '0'){
        int l = 0, r = n;
        while (l + 1 < r) {
            int m = l + r >> 1;
            if (gets (i + m) - gets (i - m - 1) - 1 >= k) r = m;
            else l = m;
        }
        res = min (res, r);
//        if (k & 1) {
//            int l = getl (i, k / 2), r = getr (i, k / 2 + 1);
//            if (l != -1 && r != -1) res = min (res, max (i - l, r - i));
//            l = getl (i, k / 2 + 1), r = getr (i, k / 2);
//            if (l != -1 && r != -1) res = min (res, max (i - l, r - i));
//        } else {
//            int l = getl (i, k / 2), r = getr (i, k / 2);
//            if (l != -1 && r != -1) res = min (res, max (i - l, r - i));
//        }
    }
    cout << res << endl;
//    cout << r << endl;
}