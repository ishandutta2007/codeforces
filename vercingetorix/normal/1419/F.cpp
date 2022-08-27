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

const int A = 1000;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}
vi x, y;
int n;
map<int, vpi> r,c;
vector<vpi> add;
int to[A];
bool test(int m) {
    forn(i,0,n) make_set(i);
    for(auto & v : r) {
        forn(i,1,v.second.size()) {
            if(v.second[i].first - v.second[i-1].first <= m) union_sets(v.second[i].second, v.second[i-1].second);
        }
    }
    for(auto & v : c) {
        forn(i,1,v.second.size()) {
            if(v.second[i].first - v.second[i-1].first <= m) union_sets(v.second[i].second, v.second[i-1].second);
        }
    }
    vi fr;
    forn(i,0,n) if(find_set(i) == i) fr.pb(i);
    if(fr.size()>4) return false;
    if(fr.size() == 1) return true;
    if(fr.size() == 2) {
        for(auto & v : r) {
            forn(i,1,v.second.size()) {
                if(find_set(v.second[i].second) != find_set(v.second[i-1].second) && v.second[i].first - v.second[i-1].first <= 2*m) return true;
            }
        }
        for(auto & v : c) {
            forn(i,1,v.second.size()) {
                if(find_set(v.second[i].second) != find_set(v.second[i-1].second) && v.second[i].first - v.second[i-1].first <= 2*m) return true;
            }
        }
    }
    vi done(fr.size(), 0);
    forn(i,0,fr.size()) to[fr[i]] = i;
    for(auto & un : add) {
        forn(i,0,fr.size()) done[i] = 0;
        for(auto pp : un) if(pp.first <= m) done[to[find_set(pp.second)]] = 1;
        int can = 1;
        forn(i,0,fr.size()) if(done[i] == 0) can = 0;
        if(can) return true;
    }

    return false;
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
        c[x[i]].pb(mp(y[i], i));
        r[y[i]].pb(mp(x[i], i));
    }
    for(auto & v : r) srt(v.second);
    for(auto & v : c) srt(v.second);
    for(auto & vr : r) {
        for(auto & vc : c) {
            int nx = vc.first;
            int ny = vr.first;
            vpi cand;
            int ptx = lower_bound(all(vr.second), mp(nx,0)) - vr.second.begin();
            if(ptx < vr.second.size()) cand.pb(mp(vr.second[ptx].first - nx, vr.second[ptx].second));
            if(ptx > 0) cand.pb(mp(nx-vr.second[ptx-1].first, vr.second[ptx-1].second));
            int pty = lower_bound(all(vc.second), mp(ny,0)) - vc.second.begin();
            if(pty < vc.second.size()) cand.pb(mp(vc.second[pty].first - ny, vc.second[pty].second));
            if(pty > 0) cand.pb(mp(ny-vc.second[pty-1].first, vc.second[pty-1].second));
            if(cand.size() > 1) add.pb(cand);
        }
    }
    int l = 0;
    int r = 2000000000;
    if(test(r) == false) {
        cout<<-1;
        exit(0);
    }
    while(r-l > 1) {
        int m = (r+l)/2;
        if(test(m)) r = m;
        else l = m;
    }
    cout<<r;
    
    
    
    
}