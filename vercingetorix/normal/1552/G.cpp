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
 
const long long mod = 998244353;
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
// vvi a;
vi a[10];
// vi b;
int b[50];
int c[50];
int was[10][50];
vvi nw;
int n,k;
int can = 1;
void test() {
    // can++;
    // vi c = b;
    // forn(i,0,n) c[i] = b[i];
    // forn(i,0,k) {
    //     int c1 = 0;
    //     for(auto x : a[i]) c1 += c[x];
    //     int c0 = a[i].size() - c1;
    //     forn(j,0,c0) c[a[i][j]] = 0;
    //     forn(j,c0,a[i].size()) c[a[i][j]] = 1;
    // }
    forn(i,0,n-1) if(b[i] > b[i+1]) can = 0;
}
 
void go(int i) {
    if (i  ==  k) {
        test();
        return;
    }
    // vi was;
    int c1 = 0;
    for(auto x : a[i]) {
        was[i][x] = b[x];
        // was.pb(b[x]);
        c1 += b[x];
    }
    int c0 = a[i].size()-c1;
    c0 -= nw[i].size();
    forn(j,0,c0) {
        b[a[i][j]] = 0;
    }
    forn(j,c0,a[i].size()) {
        b[a[i][j]] = 1;
    }
    go(i+1);
    forn(j,0,nw[i].size()) {
        b[a[i][c0 + j]] = 0;
        go(i+1);
    }
    // for(auto x : nw[i]) b[x] = 0;
    // forn(j,0,was.size()) b[a[i][j]] = was[j];
    for(auto x : a[i]) b[x] = was[i][x];
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
 
    scanf("%d %d", &n, &k);
    // a = vvi (k);
    nw = vvi (k);
    vi used(n,0);
    forn(i,0,k) {
        int q;
        scanf("%d", &q);
        a[i].resize(q);
        forn(j,0,q) scanf("%d", &a[i][j]);
        // forn(j,0,q) a[i][j] = j;
        forn(j,0,q) a[i][j] -- ;
        forn(j,0,q) {
            if(used[a[i][j]] == 0) {
                nw[i].pb(a[i][j]);
                used[a[i][j]] = 1;
            }
        }
    }
 
    // b = vi(n,0);
    go(0);
    forn(i,0,n) if(used[i] == 0 && n!=1) can = 0;
    if(can) printf("ACCEPTED\n");
    else printf("REJECTED\n");
    // cout<<can;
    
    
}