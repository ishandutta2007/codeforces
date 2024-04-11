#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 998244353;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

ll f[MAXN];
int n;

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % MM;
    ll ans = f[n];
    ll now = n;
    ll sm = n;
    for (int i = 1; i <= n; i++) {
        ans += (f[n] - sm);
        now--;
        sm = sm * now % MM;
        ans %= MM;
    }
    printf("%lld\n", (ans % MM + MM) % MM);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}