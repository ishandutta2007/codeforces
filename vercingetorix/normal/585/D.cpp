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
vvi a;
vll d3(1,1);
int n;


vector<pair<pi, pi>> get(int l, int r) {
    vector<pair<pi, pi>> ret2,ret;
    int len = r-l+1;
    vi sdef(3, 0);
    forn(i,l,r+1) forn(j,0,3) sdef[j] += a[i][j];
    forn(mask,0,d3[len]) {
        int m = mask;
        vi scur = sdef;
        forn(i,0,len) {
            int ind = m%3;
            m/=3;
            scur[ind] -= a[i+l][ind];
        }
        ret2.pb(mp(mp(scur[0]-scur[1], scur[1]-scur[2]), mp(scur[0], mask)));
    }
    srtrev(ret2);
    forn(i,0,ret2.size()) if(i==0 || ret2[i].first != ret2[i-1].first) ret.pb(ret2[i]);
    return ret;
}

void prnt(int mask, int len) {
    forn(i,0,len) {
        if(mask%3 == 0) {
            printf("MW\n");
        }
        else if(mask%3 == 1) {
            printf("LW\n");
        }
        else printf("ML\n");
        mask/=3;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(i,0,15) d3.pb(d3.back() * 3);
    read(n);
    a =vvi(n, vi(3));
    forn(i,0,n) forn(j,0,3) scanf("%d", &a[i][j]);
    auto l = get(0,n/2-1);
    auto r = get(n/2,n-1);
    forn(i,0,l.size()) l[i].first = mp(-l[i].first.first, -l[i].first.second);
    srtrev(l);
    int best  = -1e9;
    pi ans = mp(-1,-1);
    int pl = 0;
    int pr = 0;
    while(pl!=l.size() && pr!=r.size()) {
        if(l[pl].first > r[pr].first) pl++;
        else if(r[pr].first > l[pl].first) pr++;
        else {
            if(l[pl].second.first + r[pr].second.first > best) {
                best = l[pl].second.first + r[pr].second.first;
                ans = mp(l[pl].second.second, r[pr].second.second);
            }
            pl++;
            pr++;
        }
    }
    if(ans.first == -1) {
        cout<<"Impossible";
    }
    else {
        prnt(ans.first, n/2);
        prnt(ans.second, n-n/2);
    }
    
}