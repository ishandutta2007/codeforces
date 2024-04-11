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

const long long mod = 1000000007;
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

int ddcount(const vpi & f, ll cur, ll to, int pos) {
    if(cur > to) return 0;
    if(pos == f.size()) return 1;
    int ret = 0;
    ll dp = 1;
    forn(i,0,f[pos].second+1) {
        ret += ddcount(f, cur*dp, to, pos+1);
        dp*=f[pos].first;
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    // PRIMES
    const int N = 1000100;
    //int mindiv[N+1];
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        map<int, int> n,m,s;
        ll nv = 1, mv = 1, sv = 1;
        forn(i,0,3) {
            int x;
            scanf("%d", &x);
            nv*=x;
            while(x != 1) {
                n[mindiv[x]]++;
                x /= mindiv[x];
            }
        }
        forn(i,0,3) {
            int x;
            scanf("%d", &x);
            mv*=x;
            while(x != 1) {
                m[mindiv[x]]++;
                x /= mindiv[x];
            }
        }
        forn(i,0,3) {
            int x;
            scanf("%d", &x);
            sv*=x;
            while(x != 1) {
                s[mindiv[x]]++;
                x /= mindiv[x];
            }
        }
        s[2]++;
        vll rem;
        for(auto pr : n) {
            if(n[pr.first] > s[pr.first]) {
                ll d = pr.first;
                forn(i,0,s[pr.first]) d *= pr.first;
                rem.pb(d);
            }
        }
        ll ans = mv;
        forn(mask,1,1<<rem.size()) {
            int sg = 1;
            ll v = 1;
            forn(bit,0,rem.size()) {
                if(mask & (1<<bit)) {
                    v*=rem[bit];
                    sg = -sg;
                }
            }
            ans += sg*(mv/v);
        }
        vpi sd;
        for(auto pr : s) {
            if(pr.second > 0) {
                sd.pb(pr);
            }
        }
        cout<<ans+ddcount(sd, 1, nv, 0)<<'\n';
        
    }
    
    
}