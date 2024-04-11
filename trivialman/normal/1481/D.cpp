#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1005;
mt19937 rng(time(0));

int T, n, m;
char s[N][N];
int v[N];
int stk[N], top;
vector<int> cyc;
int rk[N];

void dfs(int x) {
    v[x] = 1;
    stk[++top] = x;
    rep(i, 1, n) if (s[x][i] == 'a') {
        if (!v[i])
            dfs(i);
        else if (v[i] == 1) {
            int j = top;
            while (j >= 0 && stk[j] != i) {
                cyc.PB(stk[j]);
                j--;
            }
            assert(j >= 0);
            cyc.PB(i);
            reverse(cyc.begin(), cyc.end());
            rep(j, 1, n) v[j] = 2;
        }
    }
    --top;
    v[x] = 2;
}

int main() {
    cin >> T;
    rep(cas, 1, T) {
        scanf("%d%d\n", &n, &m);
        rep(i, 1, n) scanf("%s\n", s[i] + 1);
        //case1: m is odd
        if (m % 2 == 1) {
            printf("YES\n");
            rep(i, 1, m + 1) printf("%d ", i % 2 ? 1 : 2);
            printf("\n");
            continue;
        }

        //case2: s[i][j]==s[j][i]
        int x = 0, y = 0;
        rep(i, 1, n) rep(j, 1, i - 1) if (s[i][j] == s[j][i]) x = i, y = j;
        if(x){
            printf("YES\n");
            rep(i, 1, m + 1) printf("%d ", i % 2 ? x : y);
            printf("\n");
            continue;
        }

        //case3: have cycles
        memset(v, 0, sizeof v);
        top = 0, cyc.clear();
        rep(i, 1, n) if (!v[i]) dfs(i);
        if (cyc.size()) {
            printf("YES\n");
            int k = cyc.size();
            rep(i, 1, m + 1) printf("%d ", cyc[i % k]);
            printf("\n");
            continue;
        }

        //case4: no cycles
        if (n == 2)
            printf("NO\n");
        else {
            memset(rk, 0, sizeof rk);
            rep(i, 1, n) rep(j, 1, n) rk[i] += s[i][j] == 'a';
            int x, y, z;
            rep(i, 1, n) if (rk[i] == 0) x = i;
            rep(i, 1, n) if (rk[i] == 1) y = i;
            rep(i, 1, n) if (rk[i] == 2) z = i;
            if (m % 4 == 0) {
                printf("YES\n%d ", y);
                rep(i, 1, m / 4) printf("%d %d %d %d ", x, y, z, y);
                printf("\n");
            } else {
                printf("YES\n%d %d %d ", z, y, x);
                rep(i, 1, (m - 2) / 4) printf("%d %d %d %d ", y, z, y, x);
                printf("\n");
            }
        }
    }
    return 0;
}