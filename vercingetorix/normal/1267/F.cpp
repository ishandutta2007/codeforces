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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,kn,km;
    scanf("%d %d %d %d", &n, &m, &kn, &km);
    readv(a,kn);
    readv(b,km);
    forn(i,0,kn) a[i]--;
    forn(i,0,km) b[i]--;
    vi deg(n+m,1);
    for(auto x : a) deg[x]++;
    for(auto x : b) deg[x]++;
    int sa = n+kn;
    int sb = m+km;
    if(sa > n+m-1 || sb > n+m-1) {
        printf("No\n");
        exit(0);
    }
    while(a.size() < m-1) {
        a.pb(n-1);
        deg[n-1]++;
    }
    while(b.size() < n-1) {
        b.pb(n);
        deg[n]++;
    }
    int pta = 0;
    int ptb = 0;
    set<int> kill;
    forn(x,0,n+m) if(deg[x] == 1) kill.insert(x);
    printf("Yes\n");
    forn(it,0,n+m-2) {
        int v = *kill.begin();
        kill.erase(kill.begin());
        if(v < n) {
            int u = b[ptb++];
            deg[u]--;
            if(deg[u] == 1) kill.insert(u);
            printf("%d %d\n", v+1, u+1);
        }
        else {
            int u = a[pta++];
            deg[u]--;
            if(deg[u] == 1) kill.insert(u);
            printf("%d %d\n", u+1, v+1);
        }
        deg[v]--;
    }
    int l = 0;
    int r = n+m-1;
    while(deg[l] == 0) l++;
    while(deg[r] == 0) r--;
    printf("%d %d\n", l+1, r+1);
    
    
}