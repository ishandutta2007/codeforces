#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define maxn 100005
#define maxm 320
#define pb push_back
#define LL long long int
using namespace std;
int n, m, q;

vector<int> set[maxn];
vector<int> rec[maxn];
int siz[maxn];
LL add[maxn];
LL sum[maxn];
int cnt[maxm][maxn];
LL a[maxn];
int heav[maxn];
int ct = 0;

int main(){
    /*freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);*/
    int x, op;
    LL y;
    scanf("%d%d%d", &n, &m, &q);
    int blo = (int) sqrt(n) + 1;
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    for (int i = 1; i <= m; i++){
        scanf("%d", &siz[i]);
        if (siz[i] >= blo) {
            heav[++ct] = i;
            for (int j = 0; j < siz[i]; j++){
                scanf("%d", &x);
                set[i].pb(x);
                rec[x].pb(ct);
                sum[i] += a[x];
            }
        }
        else{
            for (int j = 0; j < siz[i]; j++){
                scanf("%d", &x);
                set[i].pb(x);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < siz[i]; j++){
            op = set[i][j];
            for (int k = 0; k < rec[op].size(); k++) cnt[rec[op][k]][i]++;
        }
    }
    char sop[5];
    for (int i = 1; i <= q; i++){
        scanf("%s", &sop);
        if (sop[0] == '?') {
            scanf("%d", &x);
            if (siz[x] >= blo){
                LL ans = sum[x];
                for (int i = 1; i <= ct; i++) ans += add[heav[i]] * cnt[i][x];
                printf("%I64d\n", ans);
            }
            else {
                LL ans = 0;
                for (int i = 0; i < siz[x]; i++) ans += a[set[x][i]];
                for (int i = 1; i <= ct; i++) ans += add[heav[i]] * cnt[i][x];
                printf("%I64d\n", ans);
            }
        }
        else if (sop[0] == '+') {
            scanf("%d%I64d", &x, &y);
            if (siz[x] >= blo) add[x] += y;
            else{
                for (int j = 0; j < siz[x]; j++) a[set[x][j]] += y;
                for (int i = 1; i <= ct; i++) sum[heav[i]] += y * cnt[i][x];
            }
        }
    }
    return 0;
}