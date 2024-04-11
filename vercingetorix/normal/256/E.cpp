#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 777777777;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int A = 80000;
ll d[3][3][A];
int n;
int a[A];

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
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

ll solvelr(int l, int r);
ll solvel(int l, int r);
ll solver(int l, int r);

ll solve(int l, int r) {
    if(a[l]==0) {
        if(a[r] == 0) return solvelr(l, r);
        else return solvel(l,r);
    }
    else if(a[r] == 0) return solver(l,r);
    return d[a[l]-1][a[r]-1][r-l];
}

ll solvel(int l, int r) {
    if(r-l == 1) return 1;
    ll ret = 0;
    forn(tr,1,4) {
        a[l+1] = tr;
        ret += solve(l+1,r);
    }
    a[l+1] = 0;
    return ret%mod;
}

ll solver(int l, int r) {
    if(r-l == 1) return 1;
    ll ret = 0;
    forn(tr,1,4) {
        a[r-1] = tr;
        ret += solve(l,r-1);
    }
    a[r-1] = 0;
    return ret%mod;
}

ll solvelr(int l, int r) {
    if(r-l==1) return 1;
    else if(r-l==2) return 3;
    else {
        ll ret = 0;
        forn(tl,1,4) forn(tr,1,4) {
            a[l+1] = tl;
            a[r-1] = tr;
            ret += solve(l+1, r-1);
        }
        a[l+1] = 0;
        a[r-1] = 0;
        return ret%mod;
    }
}

int z = 0;
int d3,d7,d37,d333667;
ll ans = 1;

void add(int m) {
    if(m == 0) {
        z++;
        return;
    }
    while(m%3 == 0) d3++, m/=3;
    while(m%7 == 0) d7++, m/=7;
    while(m%37 == 0) d37++, m/=37;
    while(m%333667 == 0) d333667++, m/=333667;
    ans = ans*m%mod;
}

void rem(int m) {
    if(m == 0) {
        z--;
        return;
    }
    while(m%3 == 0) d3--, m/=3;
    while(m%7 == 0) d7--, m/=7;
    while(m%37 == 0) d37--, m/=37;
    while(m%333667 == 0) d333667--, m/=333667;
    ans = ans*invmod(m,mod)%mod;
}

ll kpow(ll a, ll d) {
    if (d==0) return 1;
    ll x = kpow(a,d/2);
    x = x*x%mod;
    if (d%2==1) x*=a;
    return x%mod;
}

ll zcount() {
    if(z > 0) return 0;
    ll ret = ans;
    ret = ret*kpow(3, d3)%mod;
    ret = ret*kpow(7, d7)%mod;
    ret = ret*kpow(37, d37)%mod;
    ret = ret*kpow(333667, d333667)%mod;
    return ret;
}

set<int> q;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d %d", &n, &m);
    forn(i,0,3) forn(j,0,3) scanf("%lld", &d[i][j][1]);
    forn(k,1,A-1) {
        forn(i,0,3) forn(j,0,3) {
            forn(l,0,3) {
                d[i][j][k+1] += d[i][l][k]*d[l][j][1];
            }
            d[i][j][k+1] %= mod;
        }
    }
    
    q.insert(0);
    q.insert(n+1);
    add(solve(0,n+1));
    auto deg = zcount();
    while(m--) {
        int v,t;
        scanf("%d %d", &v, &t);
        if(a[v] == t) {
            
        }
        else if(a[v] > 0) {
            auto it = q.lower_bound(v);
            it--;
            int l = *it;
            it++; it++;
            int r = *it;
            rem(solve(l,v));
            rem(solve(v,r));
            a[v] = t;
            if(t == 0) {
                add(solve(l,r));
                q.erase(v);
            }
            else {
                add(solve(l,v));
                add(solve(v,r));
            }
        }
        else {
            auto it = q.lower_bound(v);
            int r = *it;
            it--;
            int l = *it;
            rem(solve(l,r));
            a[v] = t;
            add(solve(l,v));
            add(solve(v,r));
            q.insert(v);
        }
        printf("%lld\n", zcount());
    }
    
    
}