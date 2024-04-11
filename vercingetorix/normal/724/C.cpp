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
    int n,m,k;
    const ll INF = 1e18;
    scanf("%d %d %d", &n, &m, &k);
    ll m1 = n*2;
    ll m2 = m*2;
    ll d = gcd(m1,m2);
    ll m1d = m1/d;
    ll m2d = m2/d;
    ll r12 = invmod(m1d, m2d);
    forn(i,0,k) {
        int x,y;
        scanf("%d %d", &x,&y);
        ll best = INF;
        forn(i,0,2) {
            forn(j,0,2) {
                ll r1 =  x;
                if(i==1) r1 = m1-x;
                ll r2= y;
                if(j==1) r2=m2-y;
                if(r1 %d != r2 %d) continue;
                ll need_m1x = (r2-r1 + m1*m2)%m2;
                need_m1x /= d;
                ll xx = (r12 * need_m1x) % m2d;
                ll div = m1*xx + r1;
                best = min(div,best);
                
            }
        }
        if(best==INF) best = -1;
        printf("%lld\n", best);
        
    }
    
    
}