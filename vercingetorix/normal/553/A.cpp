#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long c_n_k(ll n, ll k){
    ll ans =1;
    for (int i=n-k+1; i<=n; i++) ans=(ans*i)%mod;
    for (int i=1; i<=k; i++) {
        ll x, y;
        ll d = gcd(i, mod, x, y);
        ans=(ans*(x+mod))%mod;
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll n,k;
    cin>>k;
    //for(int i=0; i<n; i++) 
    vll a(k);
    fo(i,0,k) cin>>a[i];
    ll s=a[0];
    ll spos=1;
    fo(i,1,k) {
        spos = spos * c_n_k(s+a[i]-1, a[i]-1);
        spos=spos%mod;
        s+=a[i];
    }
    cout<<spos;
}