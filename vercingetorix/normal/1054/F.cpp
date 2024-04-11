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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int n1, n2;
vector < vector<int> > g;
vector < vector<int> > grev;
vector<int> mt, ml;
vector<char> used;

bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

vi visl, visr;
void dfsr(int v) {
    visr[v] = 1;
    for(auto u : g[v]) {
        if(!visr[mt[u]]) {
            dfsr(mt[u]);
        }
    }
}

void dfsl(int v) {
    visl[v] = 1;
    for(auto u : grev[ml[v]]) {
        if(!visl[u]) {
            dfsl(u);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    vi x(n), y (n);
    map<pi, int> spark;
    forn(i,0,n) {
        cin>>x[i]>>y[i];
        spark[mp(x[i], y[i])] = 1;
    }
    map<int, vpi> vx, vy;
    forn(i,0,n) {
        vx[x[i]].pb(mp(y[i], i));
        vy[y[i]].pb(mp(x[i], i));
    }
    vector<pair<int, pi>> h, v;
    for(auto x : vx) {
        sort(all(x.second));
        const vpi & d = x.second;
        int l = d.size();
        forn(i,0,l-1) {
            v.pb(mp(x.first, mp(d[i].first, d[i+1].first)));
        }
    }
    for(auto x : vy) {
        sort(all(x.second));
        const vpi & d = x.second;
        int l = d.size();
        forn(i,0,l-1) {
            h.pb(mp(x.first, mp(d[i].first, d[i+1].first)));
        }
    }
    
    n1 = v.size();
    n2 = h.size();
    g.resize(n1);
    grev.resize(n2);
    forn(i,0,n1) forn(j,0,n2) {
        if(v[i].first >= h[j].second.first && v[i].first <= h[j].second.second && h[j].first >= v[i].second.first && h[j].first <= v[i].second.second && !spark[mp(v[i].first, h[j].first)]) {
            g[i].pb(j);
            grev[j].pb(i);
        }
    }
    mt.assign (n2, -1);
    ml.assign(n1, -1);
    for (int v=0; v<n1; ++v) {
        used.assign (n1, false);
        try_kuhn (v);
    }
    
    for (int i=0; i<n2; ++i)
        if (mt[i] != -1){
            ml[mt[i]] = i;
//            printf ("%d %d\n", mt[i]+1, i+1);
        }
    visl = vi(n1, 0);
    visr = vi(n1, 0);
    forn(i,0,n1) {
        if(ml[i] == -1) {
            dfsr(i);
        }
    }
    forn(i,0,n2) {
        if(mt[i] == -1) {
            for(auto u : grev[i]) {
                dfsl(u);
            }
        }
    }
    map<pi, int> hbr, vbr;
    forn(i,0,n1) {
        if(ml[i] != -1) {
            if(visl[i] && visr[i]) {
                cout<<-1;
                return 0;
            }
            if(visl[i]) vbr[mp(v[i].first, v[i].second.first)] = 1;
            else hbr[mp(h[ml[i]].second.first, h[ml[i]].first)] = 1;
        }
    }
    vector<pair<int, pi>> hc, vc;
    for(auto x : vx) {
        sort(all(x.second));
        const vpi & d = x.second;
        int l = d.size();
        forn(i,0,l) {
            if(i==0 || vbr[mp(x.first, d[i-1].first)]) vc.pb(mp(x.first, mp(d[i].first, d[i].first)));
            else vc.back().second.second = d[i].first;
        }
    }
    for(auto x : vy) {
        sort(all(x.second));
        const vpi & d = x.second;
        int l = d.size();
        forn(i,0,l) {
            if(i==0 || hbr[mp(d[i-1].first, x.first)]) hc.pb(mp(x.first, mp(d[i].first, d[i].first)));
            else hc.back().second.second = d[i].first;
        }
    }
    cout << hc.size() <<endl;
    for(auto x : hc) {
        cout<<x.second.first << ' '<<x.first <<' '<<x.second.second<<' '<<x.first<<endl;
    }
    cout << vc.size() <<endl;
    for(auto x : vc) {
        cout<<x.first << ' '<<x.second.first <<' '<<x.first<<' '<<x.second.second<<endl;
    }
}