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

const int N = 100100;
pii a[N];
char s[N];
int res[N];

bool cmp (pii a, pii b) { return a.xx > b.xx; }

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i].xx);
        a[i].yy = i;
    }
    sort (a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].xx != a[i - 1].xx) res[a[i].yy] = i;
        else res[a[i].yy] = res[a[i - 1].yy];
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}