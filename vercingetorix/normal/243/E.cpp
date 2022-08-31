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

const long long mod = 998244353 ;
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
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}
vvi g;
vvi a;
vi vis;
vvi comp;
vvi compv;
vvi touched;

void dfs(int v) {
    vis[v] = 1;
    comp.back().pb(v);
    for(auto u : g[v]) {
        if(!vis[u]) dfs(u);
    }
}
vi hp;
vi ts;
int curpart = 1;
vvi b;
vvi kaka;
int n;
void split(int u, int v) {
    kaka= vvi(3);
    forn(i,0,n) {
        if(a[u][i] == 1) {
            if(a[v][i] == 0) kaka[0].pb(i);
            else kaka[1].pb(i);
        }
        else if(a[v][i] == 1) kaka[2].pb(i);
    }
}
int can;

void addkaka(int v) {
    vi ina(n,0);
    forn(i,0,n) if(a[v][i]) ina[i] = 1;
    int l = kaka.size();
    vvi ka1(l), ka2(l);
    vi per;
    forn(i,0,kaka.size()) {
        for(auto x : kaka[i]) {
            ina[x] = 0;
            if(a[v][x]) ka1[i].pb(x);
            else ka2[i].pb(x);
        }
        if(ka1[i].size() > 0) per.pb(i);
    }
    int y = per.size();
    forn(i,0,y-1) if(per[i]+1 != per[i+1]) {
        can = 0;
        return;
    }
    forn(i,1,y-1) if(ka2[per[i]].size() > 0) {
        can = 0;
        return;
    }
    vi xtra;
    forn(i,0,n) {
        if(ina[i]) xtra.pb(i);
    }
    if(xtra.size() > 0) {
        if(per[0] == 0 && (per.size() == 1 || ka2[0].size() == 0)) {
            kaka.clear();
            kaka.pb(xtra);
            forn(i,0,l) {
                if(ka1[i].size() > 0) kaka.pb(ka1[i]);
                if(ka2[i].size() > 0) kaka.pb(ka2[i]);
            }
        }
        else if(per.back() == l-1 && (per.size() == 1 || ka2[l-1].size() == 0)) {
            kaka.clear();
            forn(i,0,l) {
                if(ka2[i].size() > 0) kaka.pb(ka2[i]);
                if(ka1[i].size() > 0) kaka.pb(ka1[i]);
            }
            kaka.pb(xtra);
        }
        else {
            can = 0;
            return;
        }
    }
    else {
        kaka.clear();
        forn(i,0,l) {
            if(i<=per[0]) {
                if(ka2[i].size() > 0) kaka.pb(ka2[i]);
                if(ka1[i].size() > 0) kaka.pb(ka1[i]);
            }
            else {
                if(ka1[i].size() > 0) kaka.pb(ka1[i]);
                if(ka2[i].size() > 0) kaka.pb(ka2[i]);
            }
        }
    }
}

vi ans;
bool used[500];
int ed[500][500];
int red[500][500];

void dfsts (int v) {
    used[v] = true;
    forn(to,0,n) if(ed[v][to])
        if (!used[to])
            dfsts (to);
    ans.push_back(v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfsts (i);
    reverse (ans.begin(), ans.end());
}

const int A = 500;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d\n", &n);
    a = vvi (n, vi(n,0));
    b.resize(n);
    char c[1000];
    vi vale(n,0);
    forn(i,0,n) make_set(i);
    forn(i,0,n) {
        scanf("%s", c);
        forn(j,0,n) {
            if(c[j] == '1') {
                vale[i] = 1;
                b[i].pb(j);
                a[i][j] = 1;
            }
        }
        forn(j,1,b[i].size()) union_sets(b[i][j], b[i][j-1]);
    }
    vi ao;
    g.resize(n);
    forn(i,0,n) forn(j,i+1,n) {
        int can1 = 0, can2 = 0, can3 = 0;
        forn(k,0,n) {
            if(a[i][k] > a[j][k]) can1 = 1;
            if(a[i][k] < a[j][k]) can2 = 1;
            if(a[i][k] * a[j][k] == 1) can3 = 1;
        }
        if(can1 + can2 + can3 == 3) {
            g[i].pb(j);
            g[j].pb(i);
        }
    }
    vis = vi(n, 0);
    forn(i,0,n) if(!vis[i] && vale[i]) {
        comp.pb(vi());
        dfs(i);
    }
    int k = comp.size();
    compv.resize(k);
    //    vpi cord;
    vector<pair<pi, int>> cord;
    forn(i,0,k) {
        vi tk(n,0);
        for(auto x : comp[i]) {
            forn(j,0,n) tk[j] |= a[x][j];
        }
        int sum = 0;
        for(auto x : tk) sum+=x;
        cord.pb(mp(mp(sum, -(int)comp[i].size()), i));
        forn(j,0,n) {
            if(tk[j]) compv[i].pb(j);
        }
    }
    srtrev(cord);
    hp = vi(n,0);
    ts = vi(1005000, 0);
    ts[0] = n;
    vector<pair<int, vi>> kakas;
    vector<pair<int, vi>> ggs;
    set<vi> danger;
    for(auto cc : cord) {
        int ind = cc.second;
        int prt = hp[compv[ind][0]];
        int clen = cc.first.first;
        forn(i,1,clen) if(hp[compv[ind][i]] != prt) {
            printf("NO\n");
            exit(0);
        }
        ggs.pb(mp(compv[ind].size(), compv[ind]));
        if(comp[ind].size() == 1) {
            kakas.pb(mp(compv[ind].size(), compv[ind]));
            for(auto x : compv[ind]) hp[x] = curpart;
            ts[curpart] = (int)compv[ind].size();
            curpart++;
            continue;
        }
        can = 1;
        split(comp[ind][0], comp[ind][1]);
        forn(i,2,comp[ind].size()) {
            addkaka(comp[ind][i]);
            if(can == 0) break;
        }
        if(can == 0) {
            printf("NO\n");
            exit(0);
            
        }
        forn(i,1,kaka.size()) {
            for(auto x : kaka[i-1]) for(auto y : kaka[i]) ed[x][y] = 1;
        }
        for(auto x : kaka) {
            kakas.pb(mp(x.size(), x));
            danger.insert(x);
            for(auto y : x) hp[y] = curpart;
            ts[curpart] = x.size();
            curpart++;
        }
        
    }
//    forn(i,0,n) ggs.pb(mp(1, vi(1,i)));
    vi full;
    forn(i,0,n) full.pb(i);
    kakas.pb(mp(n, full));
    forn(i,0,kakas.size()) srt(kakas[i].second);
    srt(kakas);
    kakas.erase(std::unique(kakas.begin(), kakas.end()), kakas.end());
//    forn(i,0,ggs.size()) {
//        forn(j,0,kakas.size()) if(ggs[i] == kakas[j]) {
//            swap(ggs[i], ggs.back());
//            ggs.pop_back();
//            i--;
//            break;
//        }
//    }
    srt(ggs);
    ggs.erase(std::unique(ggs.begin(), ggs.end()), ggs.end());
    vector<bitset<500>> kbs(kakas.size());
    vector<bitset<500>> gbs(ggs.size());
    forn(i,0,kakas.size()) {
        for(auto j : kakas[i].second) kbs[i][j] = 1;
//        forn(j,0,n) cout<<kbs[i][j]; cout<<'\n';
    }
    forn(i,0,ggs.size()) {
        for(auto j : ggs[i].second) gbs[i][j] = 1;
    }
    vvi ch(kakas.size());
    int ks = kakas.size();
    int gs = ggs.size();
    forn(i,0,gs) forn(j,0,ks) {
        if(kakas[j].first > ggs[i].first && (kbs[j]&gbs[i])==gbs[i]) {
            ch[j].pb(i);
            break;
        }
        else if(kbs[j] == gbs[i] && danger.find(ggs[i].second) != danger.end()) break;
    }
    ch[ks-1].clear();
    forn(i,0,gs) {
        int good = 1;
        forn(j,i+1,gs) {
            if((gbs[j]&gbs[i])==gbs[i]) {
                good = 0;
                break;
            }
        }
        if(good) ch[ks-1].pb(i);
    }
//    forn(i,0,n) {
//        forn(j,0,n) cout<<ed[i][j]; cout<<'\n';
//    }
    forn(i,0,ks) {
//        srt(ch[i]);
        if(ch[i].size() >= 1) {
            vi ch2;
            forn(j,0,ch[i].size()) {
                int bad = 0;
                forn(k,j+1,ch[i].size()) {
                    if((gbs[ch[i][j]] & gbs[ch[i][k]]) == gbs[ch[i][j]]) {
                        bad = 1;
                        break;
                    }
                }
                if(bad == 0) ch2.pb(ch[i][j]);
            }
            ch[i] = ch2;
            bitset<500> left = kbs[i];
            for(auto j : ch[i]) left ^= gbs[j];
            forn(j,0,n) if(left[j]) for(auto x : ggs[ch[i].back()].second) ed[x][j] = 1;
            
            
//            for(auto x : kakas[i].second) printf("%d",x); printf(" lol\n");
//            for(auto y : ch[i]) {
//                for(auto x : ggs[y].second) printf("%d",x); printf("\n");
//            }
            forn(j,1,ch[i].size()) {
                int p = ch[i][j-1];
                int q = ch[i][j];
                for(auto x : ggs[p].second) for(auto y : ggs[q].second) ed[x][y] = 1;
            }
        }
    }
//    forn(i,0,n) {
//        forn(j,0,n) cout<<ed[i][j]; cout<<'\n';
//    }
    topological_sort();
    vi rans;
//    forn(i,0,n) cout<<find_set(i)<<' '; cout<<'\n';
    forn(it,0,n) forn(i,0,n) if(find_set(ans[i]) == it) rans.pb(ans[i]);
    printf("YES\n");
//    ans  = {1,5,4,9,6,3,8,0,2,7};
//    ans = {1,2,3,5,7,8,9};
//    ans = {9,2,4,7,3,5,1,6,8, 0};
    forn(i,0,n) {
        string cur;
        for(auto j : ans) cur.pb('0'+a[i][j]);
        printf("%s\n", cur.c_str());
    }
    
    
}