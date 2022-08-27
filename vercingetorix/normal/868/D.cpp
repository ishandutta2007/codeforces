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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

vi a[201][20];
string l[201];
string r[201];
const int INF = 1e9;
void mer(vi & a, vi & b, vi & c, vi & to) {
    int pta=0, ptb=0, ptc=0;
    a.pb(INF);
    b.pb(INF);
    c.pb(INF);
    while(1) {
        if(a[pta] <= b[ptb] && a[pta] <= c[ptc]) {
            if(a[pta] == INF) break;
            to.pb(a[pta]);
            if(b[ptb] == a[pta]) ptb++;
            if(c[ptc] == a[pta]) ptc++;
            pta++;
        }
        else if(b[ptb] <= a[pta] && b[ptb] <= c[ptc]) {
            to.pb(b[ptb]);
            if(b[ptb] == a[pta]) pta++;
            if(c[ptc] == b[ptb]) ptc++;
            ptb++;
        }
        else {
            to.pb(c[ptc]);
            if(c[ptc] == a[pta]) pta++;
            if(c[ptc] == b[ptb]) ptb++;
            ptc++;
        }
    }
    a.pop_back();
    b.pop_back();
    c.pop_back();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    forn(i,0,n) {
        string s;
        cin>>s;
        l[i] = s;
        r[i] = s;
        forn(st,0,s.size()) forn(en,st,s.size()) {
            if(en-st+1 >= 20) continue;
            int cur = 0;
            forn(j,st,en+1) {
                cur = cur*2 + (s[j]-'0');
            }
            a[i][en-st+1].pb(cur);
        }
        forn(j,0,20) {
            vi fil = a[i][j];
            sort(all(fil));
            a[i][j].clear();
            forn(k,0,fil.size()) if(k==0 || fil[k]!=fil[k-1]) a[i][j].pb(fil[k]);
        }
    }
    forn(i,0,n) {
        if(l[i].size() > 20) l[i] = l[i].substr(0,20);
        if(r[i].size() > 20) r[i] = r[i].substr(r[i].size() - 20);
    }
    int m;
    cin>>m;
    forn(it,0,m) {
        int x,y;
        cin>>x>>y;
        x--; y--;
        l[n+it] = l[x];
        if(l[n+it].size() < 20) l[n+it]+=l[y];
        if(l[n+it].size() > 20) l[n+it] = l[n+it].substr(0,20);
        r[n+it] = r[y];
        if(r[n+it].size() < 20) r[n+it]=r[x]+r[n+it];
        if(r[n+it].size() > 20) r[n+it] = r[n+it].substr(r[n+it].size() - 20);
        int sl = r[x].size();
        int sr = l[y].size();
        forn(len,1,20) {
            vi addgr;
            forn(tl, 1, len) {
                int tr = len - tl;
                if(tl>sl || tr > sr) continue;
                string p = r[x].substr(sl-tl) + l[y].substr(0, tr);
                int cur = 0;
                for(auto cx : p) cur = cur*2 + (cx-'0');
                addgr.pb(cur);
            }
            sort(all(addgr));
            vi add;
            forn(i,0,addgr.size()) if(i==0 || addgr[i]!=addgr[i-1]) add.pb(addgr[i]);
            mer(a[x][len], a[y][len], add, a[n+it][len]);
        }
        int k = 1;
        while(a[n+it][k].size() == (1<<k)) k++;
        printf("%d\n", k-1);
    }
}