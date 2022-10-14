//Solution By SlavicG
#include "bits/stdc++.h"
using namespace std;

#define        ll                   long long

#define  forn(i,n)                  for(int i=0;i<n;i++)
#define     all(v)                  v.begin(), v.end()
#define    rall(v)                  v.rbegin(),v.rend()

#define            pb                push_back
#define          sz(a)               (int)a.size()
#define         fastio               ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll pw(ll n, ll pow, ll m){
    if(pow == 0) return 1;
    if(pow%2 == 0)
    {
        ll x = pw(n, pow/2, m);
        return (x*x)%m;
    }
    else return (pw(n, pow-1, m)*n)%m;
}
ll gcd(ll a, ll b) {
    if (!b)return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
int fact(ll n, int mod) {
    if (n > 1)
        return (n * fact(n - 1, mod)) % mod;
    else
        return 1;
}
bool isPrime(ll n) {
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (ll i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    int cnt = 0;
    for(int i= 0; i< n;i++)
        cin >> a[i];

    ll mn = LLONG_MAX;
    ll tot = 0;
    ll lst = mn;
    for(int i= 0 ;i < n;i++)
    {
        a[i]-=tot;
        if(a[i] < 0){
            cout << "NO\n";
            return;
        }
        if(lst > a[i]){
            mn = min(mn,a[i]);
        }else if(lst < a[i]){
            tot += a[i] - lst;
            a[i] = lst;
        }
        lst = a[i];
    }
    cout << "YES\n";
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}