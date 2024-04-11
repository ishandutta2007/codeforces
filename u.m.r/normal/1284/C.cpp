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

ll f[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    ll n;
    ll m;
    cin >> n >> m;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] * i % m;
    }
    ll ans = 0;
    for (int l = 1; l <= n; l++) {
        ll pos = n - l + 1;
        pos = pos * pos % m;
        ans += (pos * f[l] % m * f[n - l]) % m;
        ans %= m;
    }
    cout << (ans % m + m) % m << endl;
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}