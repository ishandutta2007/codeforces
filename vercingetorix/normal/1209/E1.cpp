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
int cur[2001];
vvi a;
int n,m;

int best(int col, int mask) {
    int sum = 0;
    forn(s,0,n) {
        int cand = 0;
        forn(i,0,n) {
            if(mask & (1<<i)) cand += a[(i+s)%n][col];
        }
        sum = max(sum, cand);
    }
    return sum;
}

int bn[12];

void up(int ind) {
    for(int i = 0; i < n; i++) {
        if(bn[i] == -1 || cur[bn[i]] < cur[ind]) {
            for(int j = n-1; j > i; j--) bn[j] = bn[j-1];
            bn[i] = ind;
            return;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        
        scanf("%d %d", &n, &m);
        a = vvi(n, vi(m));
        forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
        vi d(1<<n, 0);
        vvpi upmask(m);
        forn(mask,0,1<<12) {
            forn(j,0,12) bn[j] = -1;
            forn(i,0,m) {
                cur[i] = best(i, mask);
                up(i);
            }
            forn(i,0,n) if(bn[i] != -1) upmask[bn[i]].pb(mp(mask, cur[bn[i]]));
        }
        forn(i,0,m) {
            if(upmask[i].empty()) continue;
            vi nd = d;
            for(auto go : upmask[i]) {
                for(int mask = (1<<n)-1; mask >= 0; mask--) if((mask&go.first) == go.first) {
                    nd[mask] = max(nd[mask], d[mask^go.first] + go.second);
                }
            }
            d = nd;
        }
        cout<<d[(1<<n) - 1]<<endl;
        
    }
    
    
}