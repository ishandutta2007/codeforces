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
    ll a1,a2,b1,b2,l,r;
    cin>>a1>>b1>>a2>>b2>>l>>r;
    ll d = gcd(a1,a2);
    if((b1-b2)%d != 0) {
        cout<<0;
        return 0;
    }
    ll x = (b1%d + d)%d;
    b1-=x;
    b2-=x;
    l-=x;
    r-=x;
    if(b1<0) {
        b2-=b1;
        l-=b1;
        r-=b1;
        b1=0;
    }
    if(b2<0) {
        b1-=b2;
        l-=b2;
        r-=b2;
        b2=0;
    }
    if(r<0) {
        cout << 0;
        return 0;
    }
    if(l<0) l = 0;
    r-=r%d;
    if(l%d!=0) l = l+d-l%d;
    a1/=d;
    a2/=d;
    b1/=d;
    b2/=d;
    l/=d;
    r/=d;
    ll nlo1 = ((b2-b1)%a2 + a2) % a2;
    ll k1 = (nlo1 * invmod(a1, a2)) % a2;
    ll nlo2 = ((b1-b2)%a1 + a1) % a1;
    ll l1 = (nlo2 * invmod(a2, a1)) % a1;
    ll st = max(a1*k1 + b1, a2*l1+b2);
    ll step = a1*a2;
    if(st < l) {
        st += step * ((l-st)/step);
    }
    if(st<l) st+=step;
    if(st<l) st+=step;
    if(st>r) {
        cout<<0;
        return 0;
    }
    cout << 1 + (r-st)/step;
    
    
}