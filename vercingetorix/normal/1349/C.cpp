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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,t;
    scanf("%d %d %d\n", &n, &m, &t);
    const ll INF = 2e18;
    vvll l(n, vll(m, INF));
    vs a;
    char c[10040];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    vpi dir;
    dir.pb(mp(1,0)); dir.pb(mp(-1,0));
    dir.pb(mp(0,1)); dir.pb(mp(0,-1));
    forn(i,0,n) {
        forn(j,0,m) {
            for(auto x : dir) {
                int i2 = i + x.first;
                int j2 = j + x.second;
                if(i2>=0 && j2>=0 && i2<n && j2<m && a[i][j] == a[i2][j2]) l[i][j] = 0;
            }
        }
    }
    deque<pi> q;
    forn(i,0,n) forn(j,0,m) if(l[i][j] == 0) q.pb(mp(i,j));
    while(!q.empty()) {
        auto xx = q.front();
        int i = xx.first;
        int j = xx.second;
        q.pop_front();
        for(auto x : dir) {
            int i2 = i + x.first;
            int j2 = j + x.second;
            if(i2>=0 && j2>=0 && i2<n && j2<m && l[i2][j2] == INF) {
                l[i2][j2] = l[i][j] + 1;
                q.pb(mp(i2,j2));
            }
        }
    }
    while(t--) {
        int i,j;
        ll p;
        scanf("%d %d %lld", &i, &j, &p);
        i--; j--;
        if(p<=(ll)l[i][j]) printf("%c\n", a[i][j]);
        else {
            int to = a[i][j] - '0';
            if((p-l[i][j])%2) to = 1-to;
            printf("%d\n", to);
        }
    }
    
    
    
    
}