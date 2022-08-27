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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi p(n), c(n);
    vvi w(m);
    forn(i,0,n) {
        scanf("%d %d", &p[i], &c[i]);
        w[p[i]-1].pb(c[i]);
    }
    ll ans = 1e18;
    forn(i,0,m) {
        srtrev(w[i]);
    }
    forn(win,1,n+1) {
        vi fr;
        ll cand = 0;
        int done = w[0].size();
        forn(i,1,m) {
            forn(j,0,min(win-1,(int)w[i].size())) fr.pb(w[i][j]);
            forn(j,win-1,w[i].size()) {
                cand += w[i][j];
                done++;
            }
        }
        srtrev(fr);
        while(done < win) {
            if(fr.empty()) break;
            cand+=fr.back();
            fr.pop_back();
            done++;
        }
        if(done >= win)
            ans = min(ans,cand);
    }
    cout<<ans;
    
    
}