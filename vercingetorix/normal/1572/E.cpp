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
typedef std::vector<vpll> vvpll;

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
vi x,y;
ll s32(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

ll s3(int i, int j, int k) {
    return s32(x[i], y[i], x[j], y[j], x[k], y[k]);
}

bool cw(int i, int j, int k) {
    return s3(i,j,k) < 0;
}

bool ccw(int i, int j, int k) {
    return s3(i,j,k) > 0;
}

ll v3s[200][200][200];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
    }
    forn(i,0,n) forn(j,0,n) forn(k,0,n) v3s[i][j][k] = s3(i, j, k);
    ll l = 0;
    ll r = 1e18;
    while(r-l > 1) {
        ll m = (r+l)/2;
//        pll d[n][n];
        vvpll d(n, vpll(n, mp(0,0)));
        forn(l,2,n) {
            forn(s,0,n-l) {
                int e = s + l;
                forn(f,s+1,e) {
                    pll cand = mp(d[s][f].first+d[f][e].first, d[s][f].second + d[f][e].second + v3s[s][f][e]);
                    if(cand.second >= m) {
                        cand.first ++;
                        cand.second = 0;
                    }
                    d[s][e] = max(d[s][e], cand);
                }
            }
        }
        if(d[0][n-1].first >= k+1) l = m;
        else r = m;
    }
    cout<<l;
    
    
}