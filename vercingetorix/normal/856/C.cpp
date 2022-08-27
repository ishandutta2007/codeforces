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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vvll cnk(4001, vll(4001, 0));
    forn(i,0,4001) cnk[i][0] = 1;
    forn(i,1,4001) {
        forn(j,1,i+1) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    int t;
    read(t);
    vll fac(1,1);
    for(ll i = 1; i <= 10000; i++) fac.pb(fac.back()*i%mod);
    forn(aag,0,t) {
        int n;
        read(n);
        vvi cnt(2, vi(11,0));
        forn(i,0,n) {
            int x;
            scanf("%d", &x);
            int x11= x%11;
            int dn = 0;
            while(x > 0) {
                dn++;
                x/=10;
            }
            cnt[dn%2][x11]++;
        }
        int c1 = 0;
        vvll d(11, vll(n+1,0));
        d[0][0] = 1;
        forn(i,0,11) {
            vvll nd(11, vll(n+1,0));
            int cur = cnt[1][i];
            c1 += cnt[1][i];
            forn(j,0,cur+1) {
                int dif = (i*j + (11-i)*(cur-j))%11;
                forn(was,0,11) {
                    int rnow = (was+dif)%11;
                    forn(nwas,0,n+1-cur) {
                        nd[rnow][nwas + j] = (nd[rnow][nwas+j] + cnk[cur][j]*d[was][nwas]) % mod;
                    }
                }
            }
            d = nd;
        }
        int need = (c1+1)/2;
        vll odd(11);
        forn(i,0,11) odd[i] = d[i][need];
        ll nfac = 1;
        for(ll k=1; k<= need; k++) nfac = (nfac*k)%mod;
        for(ll k=1; k<= c1-need; k++) nfac = (nfac*k)%mod;
        forn(i,0,11) {
            odd[i] = (odd[i]*nfac)%mod;
        }
        
        d = vvll(11, vll(n+1,0));
        forn(i,0,11) d[i][0] = odd[i];
        forn(i,0,11) {
            vvll nd(11, vll(n+1,0));
            int cur = cnt[0][i];
            forn(j,0,cur+1) {
                int dif = (i*j + (11-i)*(cur-j))%11;
                forn(was,0,11) {
                    int rnow = (was+dif)%11;
                    forn(nwas,0,n+1-cur) {
                        nd[rnow][nwas + j] = (nd[rnow][nwas+j] + cnk[cur][j]*d[was][nwas]) % mod;
                    }
                }
            }
            d = nd;
        }
        ll ans = 0;
        int pos0 = (c1+2)/2;
        int pos1 = (c1+1) - pos0;
        forn(i,0,n-c1+1) {
            ll cur = d[0][i];
            cur = (cur * fac[i]) % mod;
            cur = (cur * fac[n-c1-i]) % mod;
            cur = (cur * cnk[i+pos0-1][pos0-1]) % mod;
            int j = n-c1-i;
            if(j>0 && pos1 == 0) cur = 0;
            else if(j>0) {
                cur = (cur * cnk[j + pos1 - 1][pos1 - 1]) % mod;
            }
            ans = (ans+cur) % mod;
        }
        printf("%lld\n", ans);
    }
    
    
}