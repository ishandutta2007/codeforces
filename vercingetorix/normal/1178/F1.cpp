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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(c,m);
    vvi a(n);
    vi nc;
    forn(i,0,m) {
        if(i==0 || c[i]!=c[i-1]) nc.pb(c[i]);
    }
    c = nc;
    m = nc.size();
    forn(i,0,m) {
        c[i] -- ;
        a[c[i]].pb(i);
    }
    
    vi isl(m,0);
    vi isr(m,0);
    forn(i,0,n) {
        isl[a[i][0]] = 1;
        isr[a[i].back()] = 1;
    }
    int bad = 0;
    forn(i,0,n) forn(j,i+1,n) {
        int l1 = a[i][0];
        int r1 = a[i].back();
        int l2 = a[j][0];
        int r2 = a[j].back();
        if(r2>l1 && l2<r1 && (l2<l1 || r2>r1)) bad = 1;
    }
    set<int> op;
    forn(i,0,m) {
        if(!op.empty() && -(*(op.begin())) > c[i]) bad = 1;
        if(c[i] == a[c[i]][0]) op.insert(-c[i]);
        if(c[i] == a[c[i]].back()) op.erase(-c[i]);
    }
    if(bad==1) {
        cout<<0;
        exit(0);
    }
    vvll d(n, vll(n,0));
    for(int i = n-1; i>=0; i--) {
        deque<int> q;
        q.pb(i);
        int l = a[i][0];
        int r = a[i].back();
        vi qin;
        ll inans = 1;
        forn(j,l+1,r) {
            if(j == a[c[j]][0]) qin.pb(c[j]);
            if(c[j] == i) {
                if(!qin.empty()) inans = d[qin[0]][qin.back()] * inans % mod;
                qin.clear();
            }
        }
        if(!qin.empty()) inans = d[qin[0]][qin.back()] * inans % mod;
        //        if(qin.empty()) d[i][i] = 1;
        //        else d[i][i] = d[qin[0]][qin.back()];
        d[i][i] = inans;
        while(l-1 >= 0 && c[l-1] > i) {
            q.push_front(c[l-1]);
            l = a[c[l-1]][0];
        }
        while(r+1<m && c[r+1] > i) {
            q.pb(c[r+1]);
            r = a[c[r+1]].back();
        }
        
        int k = q.size();
        int w = 0;
        while(q[w] != i) w++;
        vll dwas(k,0);
//        dwas[w] = d[i][i];
        dwas[w] = 1;
        forn(pr,w+1,k) {
            ll tot = 0;
            forn(pr2,w,pr+1) {
                ll cur = 1;
                if(pr2>w) cur = d[q[w+1]][q[pr2]];
                if(pr2 < pr) cur = cur*d[q[pr2+1]][q[pr]]%mod;
                tot = (tot+cur)%mod;
            }
            dwas[pr] = tot;
        }
        for(int pl = w-1; pl>=0; pl--) {
            ll tot = 0;
            for(int pl2 = w; pl2 >= pl; pl2--) {
                ll cur = 1;
                if(pl2<w) cur = d[q[pl2]][q[w-1]];
                if(pl2 > pl) cur = cur*d[q[pl]][q[pl2-1]]%mod;
                tot = (tot+cur)%mod;
            }
            dwas[pl] = tot;
        }
        dwas[w] = 1;
        forn(pl,0,w+1) forn(pr,w,k) {
            d[q[pl]][q[pr]] = dwas[pl]*d[i][i]%mod*dwas[pr]%mod;
        }
    }
    cout<<d[c[0]][c.back()]<<endl;
    
}