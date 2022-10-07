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
const ll MAXN = 1000000, MOD = 1e9 + 7;
ll n, m, k;
int main(){
    cin>>n>>m>>k;
    if (k == -1 && (n + m) % 2 == 1){
        cout<<0<<endl;
        return 0;
    }
    n--;
    m--;
    if (n == 0 || m == 0){
        cout<<1<<endl;
        return 0;
    }
    //n += m;
    ll ans = 1, x = 2, y = 1;
    while (y <= n){
        if (y & n)
            ans = ans * x % MOD;
        x = x * x % MOD;
        y *= 2;
    }
    x = ans, y = 1;
    m--;
    while (y <= m){
        if (y & m)
            ans = ans * x % MOD;
        x = x * x % MOD;
        y *= 2;
    }
    cout<<ans<<endl;
    return 0;
}