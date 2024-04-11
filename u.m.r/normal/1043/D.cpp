#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e5 + 10;
const int MM = 1e9 + 7;
const int P1 = 1101725029;
const int P2 = 1101538897;
const int M1 = 1101581983;
const int M2 = 1101853603;

typedef pair<ll, ll> PLL;

ll pw2[MAXN], pw1[MAXN];

struct maki{
    int a[MAXN];
    ll u[MAXN], v[MAXN];
    int b[MAXN];
    void init(int n){
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            b[a[i]] = i;
        }
        for (int i = 1; i <= n; i++){
            u[i] = (u[i-1] * P1 + a[i]) % M1;
            //v[i] = (v[i-1] * P2 + a[i]) % M2;
        }
    }
    ll get(int l, int r){
        int len = r - l + 1;
        ll p = u[r] - u[l - 1] * pw1[len] % M1;
        //ll q = v[r] - v[l - 1] * pw2[len] % M2;
        if (p < 0) p += M1;
        //if (q < 0) q += M2;
        return p;//PLL(p, q);
    }
} nico[11];

int n, m;

int query(int u, int p, int v, int q){
    int l = 0, r = min(n - p, n - q) + 1;
    while (l + 1 < r){
        int mid = (l + r) / 2;
        if (nico[u].get(p, p + mid) == nico[v].get(q, q + mid))
            l = mid;
        else
            r = mid;
    }
    return l + 1;
}

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d%d", &n, &m);
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; i++){
        pw1[i] = pw1[i-1] * P1 % M1;
        //pw2[i] = pw2[i-1] * P2 % M2;
    }
    for (int j = 1; j <= m; j++){
        nico[j].init(n);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        int len = (n - i + 1);
        int now = nico[1].a[i];
        for (int j = 2; j <= m; j++){
            int npo = nico[j].b[now];
            len = min(len, query(1, i, j, npo));
        }
        ans += len;
    }
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}