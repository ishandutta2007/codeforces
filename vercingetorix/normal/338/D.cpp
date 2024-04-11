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
    return (x%modulo+modulo)%modulo;
}

void mulmod(ll & a, ll b, ll mod) {
    ll wasa = a;
    if(b==0) {
        a = 0;
        return;
    }
    mulmod(a, b/2, mod);
    a = 2*a;
    if(b%2) a += wasa;
    a%=mod;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 1000000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    ll n,m;
    int k;
    cin>>n>>m>>k;
    vll a(k);
    forn(i,0,k) cin>>a[i];
    ll nok = 1;
    forn(i,0,k) {
        ll d = gcd(nok, a[i]);
        double u = a[i] / d;
        if(u * (double) nok > (double)2*n) {
            cout<<"NO";
            return 0;
        }
        nok = nok*(a[i] / d);
        if(nok > n) {
            cout<<"NO";
            return 0;
        }
    }
    vll pr;
    vll pd;
    vll res;
    ll cur = nok;
    for(auto x : p) {
        if(cur%x==0) {
            pr.pb(x);
            pd.pb(1);
            while(cur%x==0) {
                cur/=x;
                pd.back() *= x;
            }
        }
    }
    if(cur > 1) {pr.pb(cur); pd.pb(cur);}
    int l = pr.size();
    forn(j,0,l) {
        forn(i,0,k) {
            if(a[i] % pd[j] == 0) {
                res.pb((pd[j] - (ll)i%pd[j]) % pd[j]);
                break;
            }
        }
    }
    cur = 1;
    ll q = 0;
    forn(j,0,l) {
        ll np = pd[j];
        ll r = res[j];
        ll rt = (r+np - q%np)%np;
        mulmod(rt, invmod(cur%np, np), np);
        ll nq = rt*cur + q;
        q = nq;
        cur *= np;
    }
    if(q==0) q=cur;
    if(q + k - 1 > m) {
        cout<<"NO";
        return 0;
    }
    forn(i,0,k) {
        if(gcd(nok, q+i) != a[i]) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}