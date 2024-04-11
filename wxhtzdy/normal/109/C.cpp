#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int n, rt[100005], cnt[100005];

int root(int x) {
        return rt[x] == x ? x : rt[x] = root(rt[x]);
}

LL f(LL n) { return n * (n - 1) / 2; }
LL f2(LL n) { return n * (n - 1) * (n - 2) / 6; }

bool lucky(int x) { return x == 0 || ((x % 10 == 4 || x % 10 == 7) && lucky(x / 10)); }
int main()
{
        scanf("%d", &n);
        LL ans = 0;
        for(int i = 1; i <= n; i ++) rt[i] = i;
        for(int i = 1; i < n; i ++) {
                int u, v, w; 
                scanf("%d%d%d", &u, &v, &w);
                if(!lucky(w)) rt[root(u)] = root(v);
        }
        for(int i = 1; i <= n; i ++) cnt[root(i)]++;
        int s = n;
        for(int i = 1; i <= n; i ++) {
                ans += cnt[i] * f(n - cnt[i]) * 2;
        }
        printf("%lld", ans);
        return 0;
}