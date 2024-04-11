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
const int N = 1e5 + 5;

int n;
vector < int > g[N];
ll s[N];
ll S;
bool ok;

void dfs (int k, ll sum){
    if (s[k] != -1){
        S += s[k] - sum;
        for (int i = 0; i < (int)g[k].size(); i++)
            dfs (g[k][i], s[k]);
        return;
    }
    ll x = MOD;
    for (int i = 0; i < (int)g[k].size(); i++)
        x = min (x, s[g[k][i]]);
    if (x == MOD)
        x = sum;
    if (x < sum){
        ok = 1;
        return;
    }
    S += x - sum;
    for (int i = 0; i < (int)g[k].size(); i++)
        dfs (g[k][i], x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 2; i <= n; i++){
        int u;
        cin>>u;
        g[u].pb (i);
    }
    for (int i = 1; i <= n; i++)
        cin>>s[i];
    dfs (1, 0);
    if (ok)
        S = -1;
    cout<<S<<endl;
    return 0;
}