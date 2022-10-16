#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll pow_mod(ll a, int n)
{
    if(n==0) return 1;
    if(n%2==0) return pow_mod(a*a%MOD, n/2);
    return pow_mod(a*a%MOD, n/2)*a%MOD;
}
ll inv[50];
ll power_sum(ll k, ll e)
{
    if(e==0) return k+1;
    //if(e==1) return k*(k+1);
    if(e==2) return (k*(k+1)*(2*k+1)/6)%MOD;
    if(e==4) return (pow_mod(k, 5)*inv[5]%MOD+pow_mod(k, 4)*inv[2]%MOD+pow_mod(k, 3)*inv[3]%MOD-k*inv[30]%MOD)%MOD;
    if(e==6) return (pow_mod(k, 7)*inv[7]%MOD+pow_mod(k, 6)*inv[2]%MOD+pow_mod(k, 5)*inv[2]%MOD-pow_mod(k, 3)*inv[6]%MOD+k*inv[42]%MOD)%MOD;
}
int main()
{
    for(int i=1; i<50; ++i) inv[i] = pow_mod(i, MOD-2);
    ll m;
    scanf("%lld", &m);
    ll m1 = m%MOD;
    ll y=0;
    while(y*y<=m) ++y;
    ll res = 0;
    for(ll x=1; x*x<=m; ++x)
    {
        while(x*x+y*y>m) --y;
        ll k0 = y+1;
        ll k1 = (y+1)*x*x%MOD+power_sum(y, 2);
        ll k2 = (y+1)*pow_mod(x, 4)%MOD+2*pow_mod(x, 2)*power_sum(y, 2)%MOD+power_sum(y, 4);
        ll k3 = (y+1)*pow_mod(x, 6)%MOD+3*pow_mod(x, 4)*power_sum(y, 2)%MOD+3*pow_mod(x, 2)*power_sum(y, 4)%MOD+power_sum(y, 6);
        k0 %= MOD;
        k1 %= MOD;
        k2 %= MOD;
        k3 %= MOD;
        ll tmp = (pow_mod(m1, 3)*inv[6]%MOD+pow_mod(m1, 2)*inv[2]%MOD+m1*inv[3]%MOD)*k0%MOD;
        tmp += (m1*inv[2]%MOD+2*inv[3])*k1%MOD;
        tmp += (2*MOD-m1*inv[2]%MOD-1)*k2%MOD;
        tmp += (inv[3])*k3%MOD;
        tmp %= MOD;
        res = (res+tmp)%MOD;
    }
    res = (4*res)%MOD;
    res += (pow_mod(m1, 3)*inv[6]%MOD+pow_mod(m1, 2)*inv[2]%MOD+m1*inv[3]%MOD)%MOD;
    res %= MOD;
    printf("%lld\n", res);
}