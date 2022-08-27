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

void mul(vi & a, int k) {
    vi b(k,0);
    for(auto x : a) b.pb(x);
    forn(i,0,a.size()) b[i] = (b[i] + mod-a[i])%mod;
    a.resize(b.size() - 1);
    for(int i = b.size() - 1; i > 0; i--) {
        a[i-1] = b[i];
        b[i-1] = (b[i] + b[i-1])%mod;
    }
}
vi c, b;
int n;
int get(int x) {
    vi p(1,1);
    int sb = 0;
    int sbt = 0;
    int add = 0;
    forn(i,0,n) {
        mul(p, c[i]+1);
        int cur = x*(i+1) + sbt - add;
        if(cur > (int)p.size()) {
            return 0;
        }
        if(cur>0) {
            forn(j,0,p.size() - cur) p[j] = p[j + cur];
            p.resize(p.size() - cur);
            add += cur;
        }
        
        sb+=b[i];
        sbt+=sb;
    }
    ll ans = 0;
    forn(i,0,p.size()) ans = ans+p[i];
    return ans % mod;
}
set<int> cool;
int death = 1000;

void getcool() {
    int sb = 0;
    int sbt = 0;
    int dp = 0;
    forn(i,0,n) {
        dp += c[i];

        forn(x,-sbt/(i+1),(dp-sbt)/(i+1)+2) {
            int cur = x*(i+1) + sbt;
            if(cur >0 && cur <= dp) {
                cool.insert(x);
            }
            else if(cur > dp) {
                death = min(death, x);
            }
        }
        sb+=b[i];
        sbt+=sb;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
//    readv(c,n);
//    readv(b,n-1);
    c.resize(n);
    b.resize(n-1);
    forn(i,0,n) scanf("%d", &c[i]);
    forn(i,0,n-1) scanf("%d", &b[i]);
    int q;
    read(q);
    getcool();
    map<int, int> ans;
    for(auto x : cool) {
        if(x < death) ans[x] = get(x);
        else ans[x] = 0;
    }
    ll full = 1;
    forn(i,0,n) full = (full * (c[i]+1))%mod;

    while(q--) {
        int x;
        read(x);
        if(cool.find(x) != cool.end()) printf("%d\n", ans[x]);
        else if(x >= death) printf("0\n");
        else printf("%d\n", full);
    }
    
}