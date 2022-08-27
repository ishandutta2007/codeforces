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
const int N = 200001;
int gr[N];
int d2[32];
//int h[N];
int cmv = 0;
int mv[N];
bitset<N> h[50];
bitset<N> pmv;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    // PRIMES
    
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int cnt = 0;
    int n,f;
    scanf("%d %d", &n, &f);
    forn(i,2,N+1) {
        if(isp[i] || isp[i/mindiv[i]]) if(i!=f) mv[cmv++] = i;
    }
    forn(i,0,cmv) pmv.set(mv[i]);
    gr[1] = 1;
    gr[2] = 1;
    map<int, int> togr;
    forn(i,0,31) togr[1<<i] = i;
    d2[0] = 1;
    forn(i,1,31) d2[i] = d2[i-1]*2;
    vi proc;
    forn(i,0,n) {
        int r,w,b;
        scanf("%d %d %d", &r, &w,&b);
        proc.pb(b-w);
        proc.pb(w-r);
    }
    int m = 0;
    for(auto y : proc) m = max(m,y);
    forn(i,1,N+1) {
        int pt = 0;
        while(h[pt][i]) pt++;
        gr[i] = pt;
        h[pt] |= pmv<<i;
    }
//    forn(i,1,m+1) {
//        int ck = ((h[i] ^ (h[i]+1)) + 1)/2;
//        gr[i] = ck;
//        int l = lower_bound(mv, mv+cmv, m+1-i) - mv;
//        forn(j,0,l) {
//            h[i+mv[j]] |= gr[i];
//        }
//    }
    ll x = 0;
    for(auto y : proc) {
        x  ^= gr[y];
    }
    if(x==0) {
        printf("Bob\n");
        printf("Alice\n");
    }
    else {
        printf("Alice\n");
        printf("Bob\n");
    }
    

}