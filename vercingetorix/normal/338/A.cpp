#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000009;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
ll powM(ll k, ll n, ll modulo) {
    if (n==0) return 1;
    if(n==1) return k;
    ll x = powM(k, n/2, modulo);
    return (((x*x)%modulo)*powM(k, n%2, modulo)) % modulo;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m,k;
    cin>>n>>m>>k;
    ll x = min(m/(k-1), n-m);
    ll ans = x*(k-1);
    n-=x*k;
    m-=x*(k-1);
    if (m<=k-1) {
        cout<<ans+m;
        return 0;
    }
    else {
        // n==m
        ans += m%k;
        n -= m%k;
        ll l = n/k;
        ll d2 = 1;
        d2=powM(2,l+1,mod);
        d2=(d2+mod-2)%mod;
        ll cand = (d2*k)%mod;
        cout<< (ans+cand)%mod;
    }
}