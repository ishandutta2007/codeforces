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

const long long mod = 1000000007;
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
int n,k;
int x[100500];
int y[100500];
ld d[100500];
ld ang[100500];
const ld PI = acos(ld(-1));
const ld eps = 0;

bool bet(ld x, pair<ld, ld> e) {
    if(x+eps>=e.first && x-eps<=e.second) return true;
    if(x+2*PI+eps>=e.first && x+2*PI-eps<=e.second) return true;
    if(x-2*PI+eps>=e.first && x-2*PI-eps<=e.second) return true;
    return false;
}
bool bets(ld x, pair<ld, ld> e) {
    return bet(x, mp(e.second, e.first));
}
#ifdef LOCAL
const int lnum =4;
int st[lnum][50];
#else
const int lnum = 18;
int st[lnum][200500];
#endif

bool can(ld m) {
    if(n==1) return true;
    vector<pair<ld, ld>> e;
    forn(i,0,n) {
        ld a = acos(m/d[i]);
        ld a1 = ang[i] - a;
        ld a2 = ang[i] + a;
        if(a1<0) a1+=2*PI;
        if(a2>=2*PI) a2 -= 2*PI;
//        if(a2 < a1) e.pb(mp(a1,a2+2*PI));
//        else e.pb(mp(a1,a2));
                if(a2 < a1) e.pb(mp(a2, a1-2*PI));
                else e.pb(mp(a2,a1));
    }
    srt(e);
    int best = k+1;
    int r = 0;
    forn(l,0,n) {
        if(r==l) r = r+1;
//        while(r!=l+n && bet(e[r%n].first, e[l])) r++;
//        while(r!=l+n && e[r%n].second < e[l].first) r++;
        while(r!=l+n && bets(e[l].first, e[r%n])) r++;
        if(r==l+n) return true;
        st[0][l] = r;
        st[0][l+n] = min(r+n, 2*n-1);
    }
    forn(lev,1,lnum) forn(i,0,2*n) st[lev][i] = st[lev-1][st[lev-1][i]];
    forn(s,0,n) {
        int cand = 1;
        int cur = s;
        for(int i = lnum-1; i>=0; i--) {
            if(st[i][cur] < s+n) {
                cur = st[i][cur];
                cand += 1<<i;
            }
        }
        best = min(best, cand);
    }
//    forn(s, 0, n) {
//        if(vis[s] == 0) {
//            vis[s] = 1;
//            int l = s;
//            int r = (s+1)%n;
//            int cand = 1;
//            while(r != s) {
//                if(bet(e[r].first, e[l])) r = (r+1)%n;
//                else {
//                    vis[l] = 1;
//                    l = r;
//                    cand++;
//                    r = (r+1)%n;
//                }
//            }
//            best = min(cand, best);
//        }
//    }
    if(best <= k) return true;
    else return false;
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &k);
    ld l = 0;
    ld r = 200500;
    int z = 0;
    set<pi> taken;
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
        if(taken.find(mp(x[i], y[i])) != taken.end()) {
            n--;
            i--;
            continue;
        }
        else taken.insert(mp(x[i], y[i]));
        d[i] = sqrt(ld(ll(x[i])*x[i] + ll(y[i])*y[i]));
        r = min(r, d[i]);
        if(x[i] == 0 && y[i] == 0) {
            z = 1;
        }
        else {
            ang[i] = atan2((ld)y[i], (ld)x[i]);
            if(ang[i] < 0) ang[i] += 2*PI;
        }
    }
    if(z) {
        cout<<0;
        exit(0);
    }
    
    forn(it,0,100) {
        ld m = (l+r)/2;
        if(can(m)) l = m;
        else r = m;
    }
    printf("%.10lf", (double)l);
    
    
}