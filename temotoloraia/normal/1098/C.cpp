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

ll POWER (ll x, ll y, ll mod){
    ll ans = 1, c = x;
    while (y){
        if ((y & 1) == 1)
            ans = ans * c % mod;
        c = c * c % mod;
        y /= 2;
    }
    return ans;
}

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;

ll F (ll x, ll y){
    return (x - 1) * y + y * (y + 1) / 2;
}

ll n;
ll S;
ll p[N], D[N];
ll g[N];

bool check (ll P){
    for (ll i = 1; i <= n; i++){
        p[i] = 0;
        D[i] = 0;
        g[i] = 0;
    }
    D[1] = 1;
    ll I = 2, ind = 1;
    ll sum = 1;
    while (I <= n){
        ll t = ind;
        ind = I;
        p[I] = t;
        g[t]++;
        D[I] = D[t] + 1;
        sum += D[I];
        I++;
        if (g[t] == P)
            t++;
        while (I <= n && t < ind && sum + D[t] + 1 + F (D[t] + 2, n - I) >= S){
            p[I] = t;
            g[t]++;
            D[I] = D[t] + 1;
            sum += D[I];
            I++;
            if (g[t] == P)
                t++;
        }
    }
    if (sum == S)
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>S;
    ll I = n + 1;
    for (ll l = 19; l >= 0; l--){
        ll k = I - (1<<l);
        if (k <= 0)
            continue;
        if (check (k))
            I = k;
    }
    if (I == n + 1){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    check(I);
    for (ll i = 2; i <= n; i++)
        cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}