#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#       define LLD "%I64d"
#       define debug(args...) {}
#else
#       define LLD "%lld"
#       define debug(args...) fprintf(stderr, args)
#endif

const int N = 212345;
int ri[N], le[N], sn; ll sum[N];
int a[N];

ll brut(int n) {
        ll tot = 0;
        for(int i = 1; i < n; i++) {
                printf("for %d\n", i);
                int cur, best = a[i], ct = 0;
                for(cur = i; cur < n;) {
                        ct++;
                        printf("[%d] %d -> %d\n", ct, cur, best);
                        tot += ll(best - cur) * ll(ct);
                        int old_b = best;
                        best = a[best];
                        for(int j = old_b - 1; j > cur; j--)
                                best = max(best, a[j]);
                        cur = old_b;
                }
        }
        return tot;
}

int main(int argn, char **args) {
        int i, j, n;
        scanf("%d", &n);
        for(i = 1; i < n; i++)
                scanf("%d", &a[i]);
        sum[sn] = 0; le[sn] = n; ri[sn++] = n + 1;
        ll all = 0;
        for(i = n - 1; i >= 1; i--) {
                while(sn && ri[sn-1] <= a[i]) sn--;
                int l = 0, r = sn-1;
                while(l < r) {
                        int m = (l + r + 1) / 2;
                        if(le[sn - 1 - m] <= a[i]) l = m;
                        else r = m - 1;
                }
                l = sn - 1 - l;
                debug("chose (%d->%d) %lld\n", le[l], ri[l], sum[l]);
                ll rest = sum[l] - (a[i] - le[l]) + (n - i);
                debug(">from %d eq %lld\n", i, rest);
                all += rest;
                sum[sn] = rest; le[sn] = i; ri[sn++] = a[i];
                //sum[sn] = rest + dif; ri[sn++] = i;
        }
        printf(LLD "\n", all);
}