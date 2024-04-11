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

const long long mod = 1000000007;

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

ll invmod(ll a, ll modulo) {
    ll x, y;
    gcd(a, modulo, x, y);
    return (x+modulo*modulo)%modulo;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int k;
    scanf("%d", &k);
    ll curd = 2;
    bool even = false;
    bool one = true;
    forn(i,0,k) {
        ll a;
        scanf("%lld", &a);
        if(a%2 == 0) even = true;
        if(a>1) one = false;
        curd = powM(curd, a, mod);
    }
    if(one) {
        cout<<"0/1";
        return 0;
    }
    if(curd%2 ==0) curd/=2;
    else curd = (curd+mod)/2;
    //curd 2^{k-1}
    ll p = curd;
    if(even) p++;
    else p--;
    ll q = curd;
    p = (p+mod)%mod;
    p = (p*invmod(3, mod))%mod;
    q = (q+mod)%mod;
    cout << p<<'/' << q;
    
}