#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a[2005], ans[2005];

void reshift(int l, int r)
{
    int rr = a[1];
    rep1(i, r - 1) a[i] = a[i + 1];
    a[r] = rr;
}

void solve()
{
    scanf("%d", &n);
    rep1(i, n) scanf("%d", &a[i]);
    rep1(i, n) ans[i] = 0;
    for(int i = n; i >= 1; i --) {
        while(a[i] != i) reshift(1, i), ans[i] ++;
    }
    rep1(i, n) printf("%d ", ans[i]); printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}