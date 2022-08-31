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
    int m;
    read(m);
    vvi a(m);
    map<int, vpi> w;
    forn(i,0,m){
        int n;
        scanf("%d", &n);
        a[i].resize(n);
        forn(j,0,n) scanf("%d", &a[i][j]);
        forn(j,0,n) {
            w[a[i][j]].pb(mp(i,j));
        }
    }
    int can = 1;
    for(auto & x : w) if(x.second.size() % 2) can = 0;
    if(can == 0) {
        cout<<"NO\n";
        exit(0);
    }
    int num = 0;
    vector<pair<pi, pi>> e;
    vvpi g(m);
    vs ans(m);
    forn(i,0,m) ans[i] = string(a[i].size(), '?');
    for(auto & x : w) {
        for(int j= 0; j<x.second.size(); j+=2) {
            if(x.second[j].first == x.second[j+1].first) {
                ans[x.second[j].first][x.second[j].second] = 'L';
                ans[x.second[j].first][x.second[j+1].second] = 'R';
            }
            else {
                e.pb(mp(x.second[j], x.second[j+1]));
                g[x.second[j].first].pb(mp(x.second[j+1].first, num));
                g[x.second[j+1].first].pb(mp(x.second[j].first, num));
                num++;
            }
        }
    }
    vi pt(m,0);
    vi done(num, 0);
    forn(i,0,m) {
        while(pt[i]<g[i].size()) {
            if(done[g[i][pt[i]].second]) pt[i]++;
            else {
                int v = i;
                while(1) {
                    while(done[g[v][pt[v]].second]) pt[v]++;
                    int en = g[v][pt[v]].second;
                    if(e[en].first.first != v) swap(e[en].first, e[en].second);
                    done[en] = 1;
                    ans[e[en].first.first][e[en].first.second] = 'L';
                    ans[e[en].second.first][e[en].second.second] = 'R';
                    v = e[en].second.first;
                    if(v==i) break;
                }
            }
        }
    }
    printf("YES\n");
    for(auto x : ans) printf("%s\n",x.c_str());
    
    
}