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


set<pi> e;
map<pi, char> val;
ll c1 = 0;
ll c2 = 0;

map<pi, int> ae[200500];

void addf(int v, pi x) {
    if(x.first == x.second) c1++;
//    pi ix(x.second, x.first);
//    c2 += ae[v][x];
    ae[v][x]++;
}

void remf(int v, pi x) {
    if(x.first == x.second) c1--;
//    pi ix(x.second, x.first);
    ae[v][x]--;
//    c2 -= ae[v][x];
}

void add(int u, int v, int c) {
    e.insert(mp(u, v));
    val[mp(u,v)] = c;
    if(e.find(mp(v, u)) != e.end()) {
        int d = val[mp(v, u)];
        addf(v, mp(d, c));
        addf(u, mp(c, d));
        c2++;
    }
}

void rem(int u, int v) {
    int c = val[mp(u,v)];
    e.erase(mp(u, v));
    if(e.find(mp(v, u)) != e.end()) {
        int d = val[mp(v, u)];
        remf(v, mp(d, c));
        remf(u, mp(c, d));
        c2--;
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    char c;
    forn(i,0,m) {
        scanf("\n%c ", &c);
        if(c == '?') {
            int k;
            scanf("%d", &k);
            if(k%2 == 0) {
                if(c1 > 0) printf("YES\n");
                else printf("NO\n");
            }
            else {
                if(c2 > 0) printf("YES\n");
                else printf("NO\n");
            }
        }
        else {
            int u, v;
            scanf("%d %d", &u, &v);
            if(c == '-') rem(u,v);
            else {
                scanf(" %c", &c);
                add(u, v, int(c-'a'));
            }
        }
    
    }
    
    
}