#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
const int L = 26;

const ll P1 = 998246177;
const ll P2 = 998246519;
const ll M1 = 1000001957;
const ll M2 = 1000002821;

ll pw1[MAXN], ipw1[MAXN];
ll pw2[MAXN], ipw2[MAXN];
ll iP1, iP2;

ll pw(ll p, ll q, ll MOD) {
    ll ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p % MOD;
        p = p * p % MOD;
    }
    return ret;
} 

int n, Q;
char s[MAXN];
int f[MAXN][L];
int g[L][MAXN];
// int g2[L][MAXN];

PII U[L], V[L];

void solve(int casi){
    scanf("%d%d", &n, &Q);
    scanf("%s", s + 1);
    for (int j = 0; j < L; j++) {
        f[n + 1][j] = n + 1;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < L; j++) {
            f[i][j] = f[i + 1][j];
        }
        f[i][s[i] - 'a'] = i;
    }
    iP1 = pw(P1, M1 - 2, M1);
    iP2 = pw(P2, M2 - 2, M2);
    pw1[0] = ipw1[0] = pw2[0] = ipw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw1[i] = (pw1[i - 1] * P1) % M1;
        pw2[i] = (pw2[i - 1] * P2) % M2;
        ipw1[i] = (ipw1[i - 1] * iP1) % M1;
        ipw2[i] = (ipw2[i - 1] * iP2) % M2;
    }
    for (int j = 0; j < L; j++) {
        g[j][0] = 0;
        // g2[j][0] = 0;
        for (int i = 1; i <= n; i++) {
            g[j][i] = (g[j][i - 1] * P1 + ((s[i] - 'a') == j) + 1) % M1;
            // g2[j][i] = (g2[j][i] * P2 + ((s[i] - 'a') == j) + 1) % M2;
        }
    }
    while (Q--) {
        int x, y, l;
        scanf("%d%d%d", &x, &y, &l);
        for (int i = 0; i < L; i++) {
            U[i] = PII(min(l + 1, f[x][i] - x + 1), i);
            V[i] = PII(min(l + 1, f[y][i] - y + 1), i);
        }
        sort(U, U + L);
        sort(V, V + L);
        int flag = 1;
        for (int i = 0; i < L; i++) {
            if (U[i].first != V[i].first) {
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < L && flag; i++) {
            if (U[i].first != l + 1) {
                ll eli = (g[U[i].second][x + l - 1] - g[U[i].second][x - 1] * pw1[l]) % M1;
                ll umi = (g[V[i].second][y + l - 1] - g[V[i].second][y - 1] * pw1[l]) % M1;
                if ((eli + M1) % M1 != (umi + M1) % M1) flag = 0;
                // eli = (g2[U[i].second][x + l - 1] - g2[U[i].second][x - 1] * pw2[l]) % M2;
                // umi = (g2[V[i].second][y + l - 1] - g2[V[i].second][y - 1] * pw2[l]) % M2;
                // if ((eli + M2) % M2 != (umi + M2) % M2) flag = 0;
            }
        }
        puts(flag ? "YES" : "NO");
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}