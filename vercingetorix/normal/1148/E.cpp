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



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    readv(b,n);
    set<pi> x;
    set<pi> y;
    ll sa = 0;
    ll sb = 0;
    forn(i,0,n) {
        sa += a[i];
        sb+=b[i];
        x.insert(mp(a[i], i));
        y.insert(mp(b[i], i));
    }
    if(sa!=sb) {
        cout<<"NO\n";
        exit(0);
    }
    sort(all(b));
    int pt = 0;
    set<pi> tor, tol;
//    vpi tor, tol;
    set<pi> gl, gr;
//    vi gl, gr;
    for(auto v : x) {
        if(v.first < b[pt]) {
            tor.insert(v);
            gr.insert(mp(b[pt], pt));
//            tor.pb(v);
//            gr.(b[pt]);
        }
        else if(v.first > b[pt]){
            tol.insert(v);
            gl.insert(mp(b[pt], pt));
//            tol.pb(v);
//            gl.pb(b[pt]);
        }
        pt++;
    }
    vpi ans;
    vi s;
//    while(!tol.empty() && !tor.empty()) {
//        auto sx =
//    }
    while(tor.size() > 0) {
        auto it1 = tor.end(); it1--;
        auto rx = *it1;
        tor.erase(it1);
        auto it2 = gr.end(); it2--;
        auto rg = *it2;
        gr.erase(it2);
        
        auto it3 = tol.end(); it3--;
        auto lx = *it3;
        tol.erase(it3);
        auto it4 = gl.end(); it4--;
        auto lg = *it4;
        gl.erase(it4);
        
        if(rx.first > rg.first || lx.first < lg.first || rg.first > lg.first) {
            cout<<"NO\n";
            exit(0);
        }
        int shift = min(rg.first - rx.first, lx.first - lg.first);
        if(shift > 0) {
            ans.pb(mp(rx.second + 1, lx.second + 1));
            s.pb(shift);
        }
        if(rx.first + shift != rg.first) {
            tor.insert(mp(rx.first+shift, rx.second));
            gr.insert(rg);
        }
        if(lx.first - shift != lg.first) {
            tol.insert(mp(lx.first - shift, lx.second));
            gl.insert(lg);
        }
    }
    
    
    
//    while(x.size() > 1) {
//        auto it1 = x.begin();
//        auto sx = *it1;
//        x.erase(it1);
//        auto it2 = x.end();
//        it2--; auto tx = *it2;
//        x.erase(it2);
//        auto it3 = y.begin();
//        auto sy = *it3;
//        y.erase(it3);
//        auto it4 = y.end();
//        it4--; auto ty = *it4;
//        y.erase(it4);
//        if(sx.first > sy.first || tx.first < ty.first) {
//            cout<<"NO\n";
//            exit(0);
//        }
//        int shift = min(sy.first - sx.first, tx.first - ty.first);
//        if(shift > 0) {
//            ans.pb(mp(sx.second + 1, tx.second + 1));
//            s.pb(shift);
//        }
//        if(sx.first + shift != sy.first) {
//            x.insert(mp(sx.first + shift, sx.second));
//            y.insert(sy);
//        }
//        if(tx.first - shift != ty.first) {
//            x.insert(mp(tx.first - shift, tx.second));
//            y.insert(ty);
//        }
//    }
    printf("YES\n");
    printf("%d\n", ans.size());
    forn(i,0, ans.size()) {
        printf("%d %d %d\n", ans[i].first, ans[i].second, s[i]);
    }
    
    
}