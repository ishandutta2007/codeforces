#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 urng(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int mod = 1e9+7;
ll fib[1000005];
int main()
{
    int n,m;
    cin>>n>>m;
    fib[1] = 2, fib[2] = 4;
    for(int i=3;i<=max(n,m);++i)
        fib[i]=(fib[i-2]+fib[i-1])%mod;
    ll ans = fib[n] + fib[m] - 2;
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}