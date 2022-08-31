#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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

const long long mod = 998244353;
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
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(a,n);
    readv(w,n);
    int s[2];
    s[0] = 0;
    s[1] = 0;
    forn(i,0,n) {
        s[a[i]] += w[i];
    }
    vll pf(m+1,0);
    pf[0] = 1;
    forn(l,1,m+1) {
        vll np(m+1,0);
        forn(b,0,l) {
            int s0 = s[0] - (l-1-b);
            int s1 = s[1] + b;
            if(s0 < 0) continue;
            np[b+1] = (np[b+1] + pf[b]*s1%mod*invmod(s1+s0, mod))%mod;
            np[b] = (np[b] + pf[b]*s0%mod*invmod(s1+s0, mod))%mod;
        }
        pf = np;
    }
    forn(i,0,n) {
        if(a[i] == 1) {
            ll res = 0;
            vll p(m+1,0);
            p[0] = 1;
            forn(l,0,m+1) {
//                if(pf[l] == 0) continue;
                forn(j,0,l+1) res = (res + pf[l]*(w[i]+j)%mod*p[j])%mod;
                if(l!= m) {
                    vll np(m+1,0);
                    forn(b,0,l+1) {
                        np[b+1] = (np[b+1] + p[b]*(w[i]+b)%mod*invmod(s[1]+l, mod))%mod;
                        np[b] = (np[b] + p[b]*(s[1] + l - w[i] - b)%mod*invmod(s[1]+l, mod))%mod;
                    }
                    p = np;
                }
            }
            printf("%lld\n", res);
        }
        else {
            ll res = 0;
            vll p(m+1,0);
            p[0] = 1;
            forn(l,0,m+1) {
//                if(pf[m-l] == 0) continue;
                forn(j,0,l+1) res = (res + pf[m-l]*(w[i]-j)%mod*p[j])%mod;
                if(l!= m) {
                    vll np(m+1,0);
                    forn(b,0,l+1) {
                        np[b+1] = (np[b+1] + p[b]*(w[i]-b)%mod*invmod(s[0]-l, mod))%mod;
                        np[b] = (np[b] + p[b]*(s[0] - l - w[i] + b)%mod*invmod(s[0]-l, mod))%mod;
                    }
                    p = np;
                }
            }
            printf("%lld\n", res);
        }
    }
    
    
    
}