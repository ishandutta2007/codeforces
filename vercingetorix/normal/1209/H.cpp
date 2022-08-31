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
typedef std::vector<ld> vd;
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
    int n, L;
    scanf("%d %d", &n, &L);
    vi l(n),r(n);
    vector<double> s2(n);
    forn(i,0,n) scanf("%d %d %lf", &l[i], &r[i], &s2[i]);
    vi e;
    vd s;
    int pos = 0;
    forn(i,0,n) {
        if(pos<l[i]) {
            e.pb(l[i]-pos);
            s.pb(0);
        }
        e.pb((r[i]- l[i]));
        s.pb(s2[i]);
        pos = r[i];
    }
    if(pos < L) {
        e.pb(L-pos);
        s.pb(0);
    }
    ld eps = 1e-12;
    vd v(e.size(), 2);
    set<pair<ld, int>> tra;
    ld nrg = 0;
    forn(i,0,e.size()) {
        ld t = e[i]/(s[i] + 2);
        tra.insert(mp(-s[i], i));
        nrg -= t;
        while(nrg < -eps) {
            auto it = tra.begin();
            int ind = it->second;
            ld nrgboost = -2*nrg;
            ld sp = v[ind];
            ld cs = s[ind];
            ld d = e[ind];
            if(cs > eps) nrgboost = d/cs - d*(1-sp)/(cs+sp);
            if(nrgboost + nrg < eps) {
                nrg += nrgboost;
                v[ind] = 0;
                tra.erase(it);
            }
            else {
                ld A = d*(1-sp)/(cs+sp) - nrg;
                ld nv = (d-cs*A)/(A+d);
                nrg= 0;
                v[ind] = nv;
            }
        }
    }
    ld ans = 0;
    forn(i,0,e.size()) {
        ans += e[i]/(s[i] + v[i]);
    }
    printf("%.12lf", (double) ans);
    
    
}