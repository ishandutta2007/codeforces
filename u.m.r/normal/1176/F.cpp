#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
const ll INF = 1ll << 60;

int n, m;
ll f[100];
ll g[100];

void maxi(ll &x, ll y) {
    x = max(x, y);
}

void solve(int casi){
    scanf("%d", &n);
    for (int i = 0; i < 10; i++) {
        f[i] = -INF;
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        vector<ll> p[4];
        for (int j = 1; j <= m; j++) {
            int cost, dam;
            scanf("%d%d", &cost, &dam);
            p[cost].push_back(dam);
        }
        for (int j = 1; j <= 3; j++) {
            sort(p[j].begin(), p[j].end());
            reverse(p[j].begin(), p[j].end());
            int sz = (j == 1 ? 3 : 1);
            while (p[j].size() < sz) p[j].push_back(-INF);
            p[j].resize(sz);
        }
        ll p11 = p[1][0], p12 = p[1][1], p13 = p[1][2];
        ll p2 = p[2][0], p3 = p[3][0];
        for (int k = 0; k < 10; k++) {
            g[k] = f[k];
        }
        for (int k = 0; k < 10; k++) {
            if (k < 9) maxi(g[k + 1], f[k] + p11); else maxi(g[0], f[k] + 2 * p11);
            if (k < 9) maxi(g[k + 1], f[k] + p2); else maxi(g[0], f[k] + 2 * p2);
            if (k < 9) maxi(g[k + 1], f[k] + p3); else maxi(g[0], f[k] + 2 * p3);
            if (k < 8) maxi(g[k + 2], f[k] + p11 + p2); else maxi(g[(k + 2) % 10], f[k] + p11 + p2 + max(p11, p2));
            if (k < 8) maxi(g[k + 2], f[k] + p11 + p12); else maxi(g[(k + 2) % 10], f[k] + p11 * 2 + p12);
            if (k < 7) maxi(g[k + 3], f[k] + p11 + p12 + p13); else maxi(g[(k + 3) % 10], f[k] + p11 * 2 + p12 + p13);
        }
        for (int k = 0; k < 10; k++) {
            f[k] = g[k];
        }
    }
    ll ans = -INF;
    for (int k = 0; k < 10; k++)
        ans = max(ans, f[k]);
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}