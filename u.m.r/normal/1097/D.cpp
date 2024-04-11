#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int k;

ll f[10010][100];
ll g[10010][100];

ll gao(ll p, int d) {
    //cout << p << ' ' << d << " ===============" <<endl;
    p %= MM;
    f[0][0] = g[0][0] = 1;
    for (int i = 1; i <= d; i++){
        f[0][i] = f[0][i-1] * p % MM;
        g[0][i] = (g[0][i-1] + f[0][i]) % MM;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= d; j++) {
            f[i][j] = g[i-1][j] * pw(j + 1, MM - 2) % MM;
        }
        g[i][0] = f[i][0];
        for (int j = 1; j <= d; j++)
            g[i][j] = (g[i][j-1] + f[i][j]) % MM;
    }
    return f[k][d] % MM;
}

void solve(int casi){
    //printf("Case #%d:", casi);
    ll n;
    scanf("%lld%d", &n, &k);
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            ans = ans * gao(i, cnt) % MM;
        }
    }
    if (n != 1)
        ans = ans * gao(n, 1) % MM;
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}