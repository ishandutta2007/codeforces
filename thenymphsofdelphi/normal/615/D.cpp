#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const ll MOD = (ll)1e9 + 7;

ll binPow(ll a, ll q){
    a %= MOD;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2)) % MOD;
}

int main(){
    int n;
    scanf("%d", &n);
    map <int,int> cnt;
    while (n--){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    ll d = 1;
    ll ans = 1;
    for (auto x : cnt){
        ll cnt = x.se;
        ll p = x.fi;
        ll fp = binPow(p, (cnt + 1) * cnt / 2);
        ans = binPow(ans, (cnt + 1)) * binPow(fp, d) % MOD;
        d = d * (x.se + 1) % (MOD - 1);
    }
    cout << ans << endl;
    return 0;
}