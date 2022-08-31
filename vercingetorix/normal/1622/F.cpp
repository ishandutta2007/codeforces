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

void go(int n, vi kill) {
    printf("%d\n", n-kill.size());
    vi tk(n+1,1);
    for(auto x : kill) tk[x] = 0;
    forn(i,1,n+1) if(tk[i]) printf("%d ", i);
    exit(0);
}
const int N = 1000002;
int state[N];
vi mindiv(N+1, 0);

int cur;

void proc(int m) {
    while(m!=1) {
        int p = mindiv[m];
        cur -= state[p];
        state[p] ^= 1;
        cur += state[p];
        m /= p;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    // PRIMES
    
    //int mindiv[N+1];
    
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
    
    int n;
    read(n);
    
    vi fl(N,0);
    if((n/2)%2) state[2] ^= 1;
    forn(i,1,N) {
        int m = i;
        while(m!=1) {
            int p = mindiv[m];
            fl[p] ^= 1;
            m /= p;
        }
        if(i == n/2) {
            forn(j,0,N) state[j] ^= fl[j];
        }
        if(n%2==1 && i==n) {
            forn(j,0,N) state[j] ^= fl[j];
        }
    }
    forn(i,0,N) cur+=state[i];
    if(cur == 0) go(n, {});
    int curwas = cur;
    
    forn(i,0,N) fl[i] = state[i];
    forn(i,1,n+1) {
        int m = i;
        while(m!=1) {
            int p = mindiv[m];
            cur -= fl[p];
            fl[p] ^= 1;
            cur += fl[p];
            m /= p;
        }
        if(cur == 0) go(n, {i});
    }
    
    if(n%2 == 0) {
        go(n, {n/2, 2});
    }
    if((n/2)%2 == 0) go(n, {n,n/2});
    forn(i,0,N) state[i] = 0;
    state[2] = 1;
    cur = 1;
    
    int cur1 = n;
    int cur2 = n/2;
    for(int r=n; r>=n-1200; r--) {
        if(r < 1) break;
        forn(l,n/2 - 1200, n/2+1200) {
            if(l<1 || l> n) continue;
            while(cur1 > r) proc(cur1--);
            while(cur1 < r) proc(++cur1);
            while(cur2 > l) proc(cur2--);
            while(cur2 < l) proc(++cur2);
            if(cur == 0) go(n, {cur1, cur2});
        }
    }
    go(n, {n,n/2,2});
    
    
//    int mx = 0;
    
//    cout<<mx;
//    cout<<pr.size();
    
}