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
const ll N = 300005;
ll n, x, y;
pair < ll, ll > P[N];
ll dp[N], I[N];
int main()
{
    cin>>n>>x>>y;
    for (ll i = 1; i <= n; i++){
        cin>>P[i].F;
        P[i].S = i;
    }
    sort (P + 1, P + n + 1);
    for (ll i = n; i >= 1; i--)
        if (dp[i + 1] > P[i].F * (n - i + 1)){
            dp[i] = dp[i + 1];
            I[i] = I[i + 1];
        }
        else {
            dp[i] = P[i].F * (n - i + 1);
            I[i] = i;
        }
    for (ll i = 1; i <= n; i++){
        ll p = (x - 1) / P[i].F + 1;
        if (i + p > n)
            continue;
        if (dp[i + p] < y)
            continue;
        cout<<"Yes\n";
        cout<<p<<" "<<n - I[i + p] + 1<<endl;
        for (ll j = i; j < i + p; j++)
            cout<<P[j].S<<" ";
        cout<<endl;
        for (ll j = I[i+p]; j <= n; j++)
            cout<<P[j].S<<" ";
        cout<<endl;
        return 0;
    }
    swap (x, y);
    for (ll i = 1; i <= n; i++){
        ll p = (x - 1) / P[i].F + 1;
        if (i + p > n)
            continue;
        if (dp[i + p] < y)
            continue;
        cout<<"Yes\n";
        cout<<n - I[i + p] + 1<<" "<<p<<endl;
        for (ll j = I[i+p]; j <= n; j++)
            cout<<P[j].S<<" ";
        cout<<endl;
        for (ll j = i; j < i + p; j++)
            cout<<P[j].S<<" ";
        cout<<endl;
        return 0;
    }
    cout<<"No\n";
    return 0;
}