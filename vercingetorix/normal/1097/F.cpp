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

const int A = 7001;
bitset<A> init[A];
bitset<A> rinit[A];
bitset<A> a[100500];


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 10000;
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    vi issqf(N+1,0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    vi sqf;
    sqf.pb(1);
    issqf[1] = 1;
    forn(i,2,N) {
        if(i/mindiv[i] % mindiv[i] != 0 && issqf[i/mindiv[i]]) {
            issqf[i] = 1;
            sqf.pb(i);
        }
    }
    init[0].set(0);
    forn(i,1,A) {
        for(int j = i; j < A; j+=i) init[j].set(i);
        for(auto x : sqf) {
            if(x*i >= A) break;
            rinit[i].set(x*i);
        }
    }
    int n,q;
    scanf("%d %d", &n, &q);
    forn(i,0,q) {
        int tp, x,y,z,v;
        scanf("%d %d", &tp, &x);
        x--;
        if(tp == 1) {
            scanf("%d", &v);
            a[x] = init[v];
        }
        else if(tp == 2) {
            scanf("%d %d", &y, &z);
            y--; z--;
            a[x] = a[y]^a[z];
        }
        else if(tp==3) {
            scanf("%d %d", &y, &z);
            y--; z--;
            a[x] = a[y]&a[z];
        }
        else {
            int v;
            scanf("%d", &v);
            if((a[x]&rinit[v]).count() % 2 == 0) printf("0");
            else printf("1");
        }
        
    }
    
    
}