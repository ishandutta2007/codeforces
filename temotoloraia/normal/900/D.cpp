#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const ll MOD = 1e9 + 7;
ll POWER (ll X){
    ll P = 1, Q = 2, T = 1;
    while (T <= X){
        if (T & X)
            P = P * Q % MOD;
        T *= 2;
        Q = Q * Q % MOD;
    }
    return P;
}
map < ll, ll > M, F;
ll datvla (ll n){
    if (n <= 2)
        return 1;
    if (n <= 1e9){
        if (F[n])
            return M[n];
        F[n] = 1;
    }
    ll ans = POWER (n - 1);
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0){
            ans = (ans - datvla (i) + MOD) % MOD;
            if (n != i * i)
                ans = (ans - datvla (n / i) + MOD) % MOD;
        }
    ans = (ans - 1 + MOD) % MOD;
    if (n <= 1e9)
        M[n] = ans;
    return ans;
}
int main() {
    ll n, m;
    m = 1;
    n = 1e9;
    cin>>m>>n;
    if (n % m){
        cout<<0<<endl;
        return 0;
    }
    n /= m;
    cout<<datvla (n)<<endl;
    return 0;
}