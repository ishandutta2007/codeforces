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
    vvi mv;
    mv.pb(vi({0,1,2}));
    mv.pb(vi({1,2,3}));
    mv.pb(vi({2,3,4}));
    mv.pb(vi({3,4,5}));
    mv.pb(vi({4,5,6}));
    forn(i,1,6) mv.pb(vi({i,6,12-i}));
    mv.pb(vi({0,2,4}));
    mv.pb(vi({1,3,5}));
    mv.pb(vi({0,3,6}));
    mv.pb(vi({1,4,7}));
    mv.pb(vi({2,5,8}));
    mv.pb(vi({1,5,9}));
    mv.pb(vi({0,4,8}));
    mv.pb(vi({0,5,10}));
    vi mvi;
    vvi mito3(64);
    for(auto x : mv) {
        int u = 0;
        for(auto y : x) if(y<6) u |= 1<<y;
        mvi.pb(u);
        mito3[u] = x;
    }
    vvi can(64);
    can[0] = vi();
    for(auto x : mvi) can[x] = vi({x});
    for(auto x : mvi) for(auto y : mvi) can[x^y] = vi({x,y});
//    forn(i,0,64) {
//        cout<<i<<endl;
//        forn(j,0,6) if(i&(1<<j)) cout<<1; else cout<<0; cout<<endl;
//        for(auto x : can[i]) {
//            string cx(13,'0');
//            for(auto y : mito3[x]) cx[y] = '1';
//            cout<<cx<<endl;
//        }
//        cout<<endl;
//    }
//    return 0;
//    forn(i,0,64) cout<<i<<' '<<can[i]<<endl;
    scanf("%d", &n);
    int nwas = n;
    readv(a,n);
    vvi q;
    while(n > 12) {
        int pos = 0;
        forn(i,0,6) pos|= a[n-1-i]*(1<<i);
        for(auto x : can[pos]) {
            auto m0 = mito3[x];
            q.pb(vi());
            forn(i,0,3) {
                a[n-1-m0[i]] = 1 - a[n-1-m0[i]];
                q.back().pb(n-m0[i]);
            }
//            forn(i,0,n) cout<<a[i]<<' '; cout<<endl;
        }
        n-=6;
    }
    while(n>2) {
        if(a[n-1] == 1) {
            if(n > 4 && a[n-2] == 0) {
                forn(i,0,3) a[n-1-2*i] = 1 - a[n-1-2*i];
                q.pb(vi({n,n-2,n-4}));
//                forn(i,0,n) cout<<a[i]<<' '; cout<<endl;
            }
            else {
                forn(i,0,3) a[n-1-i] = 1 - a[n-1-i];
                q.pb(vi({n,n-1,n-2}));
//                forn(i,0,n) cout<<a[i]<<' '; cout<<endl;
            }
        }
        n--;
    }
    if(a[1] == 1) {
        if(nwas < 8) {
            cout<<"NO";
            return 0;
        }
        else {
            q.pb(vi({2,5,8}));
            q.pb(vi({5,6,7}));
            q.pb(vi({6,7,8}));
        }
    }
    if(a[0]==1) {
        if(nwas < 7) {
            cout<<"NO";
            return 0;
        }
        else {
            q.pb(vi({1,4,7}));
            q.pb(vi({4,5,6}));
            q.pb(vi({5,6,7}));
        }
    }
//    if(a[0]==0 && a[1] == 0) {
        printf("YES\n");
        printf("%d\n", q.size());
        for(auto x : q) {
            printf("%d %d %d\n", x[0], x[1], x[2]);
        }
//    }
//    else cout<<"NO";
}