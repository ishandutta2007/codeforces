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
const int A = 200;
ll c[A][A];
ll out[A][A];
pll d[A][A];
int ans[A];
//ll sum = 0;

void go(int l, int r, int par) {
    if(l>r) return;
    int m = d[l][r].second;
//    sum += d[l][r].first;
    ans[m] = par;
    go(l,m-1,m);
    go(m+1,r,m);
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    forn(i,0,n) forn(j,0,n) cin>>c[i][j];
    forn(l,0,n) {
        ll cur = 0;
        forn(r,l,n) {
            forn(p,l,r) cur -= c[r][p];
            forn(p,0,l) cur += c[r][p];
            forn(p,r+1,n) cur += c[r][p];
            out[l][r] = cur;
        }
    }
    forn(len,1,n+1) {
        forn(r,len-1,n) {
            int l = r-len+1;
            pll best = mp(1e18, 1);
            forn(m,l,r+1) {
                pll cand = mp(out[l][r], m);
                if(m<r) cand.first += d[m+1][r].first;
                if(l<m) cand.first += d[l][m-1].first;
                best = min(best, cand);
            }
            d[l][r] = best;
        }
    }
    go(0,n-1,-1);
    forn(i,0,n) printf("%d ", ans[i]+1);
//    cout<<'\n'<<sum;
    
    
}