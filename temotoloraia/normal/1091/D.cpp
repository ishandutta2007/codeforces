#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

const ll N = 1e6 + 5, MOD = 998244353;

ll n;
ll f[N], F[N];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    F[1] = 1;
    f[1] = 1;
    for (ll i = 2; i <= n; i++){
        F[i] = i * ((f[i - 1] - 1 + F[i - 1] + MOD) % MOD) % MOD;
        f[i] = f[i - 1] * i % MOD;
    }
    cout<<F[n]<<endl;
    return 0;
}