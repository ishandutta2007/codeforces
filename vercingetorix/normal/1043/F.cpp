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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 300000;
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    vi simp(N+1,0);
    vi odd(N+1,0);
    vvi divs(N+1);
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    simp[1] = 1;
    forn(i,2,N+1) {
        int m = i/mindiv[i];
        if(m%mindiv[i] == 0) simp[i] = simp[m];
        else simp[i] = simp[m] * mindiv[i];
    }
    divs[1].pb(1);
    forn(i,2,N+1) if(simp[i] == i) {
        odd[i] = 1- odd[i/mindiv[i]];
        int m = i/mindiv[i];
        for(auto x : divs[m]) divs[i].pb(x);
        for(auto x : divs[m]) divs[i].pb(x*mindiv[i]);
    }
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) a[i] = simp[a[i]];
    srt(a);
    vi b = a;
    a.clear();
    forn(i,0,n) if(i == 0 || b[i] != b[i-1]) a.pb(b[i]);
    n = a.size();
    int d = 0;
    forn(i,0,n) d= gcd(d, a[i]);
    if(d>1) {
        cout<<-1;
        exit(0);
    }
    if(a[0] == 1) {
        cout<<1;
        exit(0);
    }
    vi nd(N+1, 0);
    for(auto x : a) nd[x]++;
    forn(i,1,N+1) {
        for(int j = 2*i; j<=N; j+=i) nd[i] += nd[j];
    }
    vi freecost(N+1,100);
    freecost[1] = 0;
    forn(m,1,N+1) {
        if(simp[m] == m) {
            int cnt = 0;
            for(auto x : divs[m]) {
                if(odd[x]) cnt+=nd[x];
                else cnt-=nd[x];
            }
            if(cnt<0) {
                freecost[m] = 1;
            }
        }
    }
    forn(m,1,N+1) {
        if(simp[m] == m) {
            if(m == mindiv[m]) freecost[m] = 1;
            else for(auto q : divs[m]) {
                freecost[m] = min(freecost[m], freecost[q] + freecost[m/q]);
            }
        }
    }
    int ans = 10;
    forn(i,0,n) ans = min(ans, 1+freecost[a[i]]);
    cout<<ans;
   
    
}