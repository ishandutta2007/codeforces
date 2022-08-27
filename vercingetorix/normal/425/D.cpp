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

const ll A = 100500;
const int B = 320;
int bbig[2*A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    unordered_map<ll, int> pt;
    int n;
    read(n);
    vi x(n), y(n);
    forn(i,0,n) scanf("%d %d", &x[i], &y[i]);
    forn(i,0,n) pt[x[i]*A+y[i]]++;
    map<int, vi> sum, dif;
    forn(i,0,n) sum[x[i] + y[i]].pb(i);
    forn(i,0,n) dif[x[i] - y[i]].pb(i);
    vi bs, bd;
    ll ans = 0;
    for(auto cc : sum) {
        if(cc.second.size() >= B) bs.pb(cc.first);
        else forn(pi,0,cc.second.size()) {
            forn(pj,pi+1,cc.second.size()) {
                int i = cc.second[pi];
                int j = cc.second[pj];
                int px1 = max(x[i], x[j]);
                int py1 = max(y[i], y[j]);
                int px2 = min(x[i], x[j]);
                int py2 = min(y[i], y[j]);
                if(pt[px1*A + py1] && pt[px2*A + py2]) ans++;
            }
        }
    }
    for(auto x : bs) bbig[x] = 1;
    
    for(auto cc : dif) {
        if(cc.second.size() >= B) bd.pb(cc.first);
        else forn(pi,0,cc.second.size()) {
            forn(pj,pi+1,cc.second.size()) {
                int i = cc.second[pi];
                int j = cc.second[pj];
                int px1 = max(x[i], x[j]);
                int py1 = min(y[i], y[j]);
                int px2 = min(x[i], x[j]);
                int py2 = max(y[i], y[j]);
                if(bbig[px1 + py1] == 0) continue;
                if(pt[px1*A + py1] && pt[px2*A + py2]) ans++;
            }
        }
    }
    
    vi cnt(2*A, 0);
    for(auto pi : bs) for(auto pj : bd) {
        int x2 = pi + pj;
        for(auto i : sum[pi]) cnt[abs(x2-2*x[i])]++;
        for(auto i : dif[pj]) {
            cnt[abs(x2-2*x[i])]++;
            if(cnt[abs(x2-2*x[i])] == 4) ans++;
        }
        for(auto i : sum[pi]) cnt[abs(x2-2*x[i])]--;
        for(auto i : dif[pj]) cnt[abs(x2-2*x[i])]--;
    }
    cout<<ans;
}