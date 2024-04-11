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
const int A = 100500;
int up[31][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(p,n);
    forn(i,0,n) p[i]--;
    readv(a,n);
    forn(i,0,n) a[i]--;
    int mx = 0;
    forn(i,0,n) mx = max(a[i], mx);
    set<int> tof;
    for(auto x : p) tof.insert(x);
    int del = n - tof.size();
    int s = (mx - n+1)/del;
    vi vis(n,0);
    vi pred(n,0);
    forn(i,0,n) {
        up[0][i] = p[i];
    }
    forn(l,0,30) {
        forn(i,0,n) up[l+1][i] = up[l][up[l][i]];
    }
    forn(i,0,n) p[i] = i;
    for(int l = 30; l>=0; l--) {
        if(s>=(1<<l)) {
            s-=(1<<l);
            forn(i,0,n) p[i] = up[l][p[i]];
        }
    }
    vvi fin(n);
    forn(i,0,n) fin[p[i]].pb(i);
    vi ans(n, 0);
    set<int> left;
    forn(i,0,n) left.insert(i);
    vi done(n,0);
    forn(i,0,n) if(!fin[i].empty()) {
        for(auto ind : fin[i]) ans[ind] = a[i];
        left.erase(a[i]);
        done[fin[i][0]] = 1;
    }
    
    
    forn(i,0,n) if(!done[i]){
        auto it = left.lower_bound(ans[i]);
        ans[i] = *it;
        left.erase(it);
    }
    forn(i,0,n) printf("%d ", ans[i] + 1);
    
    
    
}