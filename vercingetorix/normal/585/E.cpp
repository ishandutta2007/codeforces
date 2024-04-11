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
const int N = 10000001;
int mindiv[N+1];

vi ss;

int num[N];
int suml[N];

vi getdivs(int m) {
    if(m == 1) return vi(1,1);
    vi ret  = getdivs(m/mindiv[m]);
    int l = ret.size();
    forn(i,0,l) ret.pb(ret[i]*mindiv[m]);
    return ret;
}

vll d2(1,1);

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,1e6) {
        d2.pb(d2.back()*2);
        if(d2.back() >= mod) d2.back() -= mod;
    }
    vector<int> pr;
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    num[1] = 1;
    forn(i,2,N) {
        int m = i/mindiv[i];
        if(m%mindiv[i] == 0) num[i] = num[m];
        else num[i] = num[m]*mindiv[i];
        if(num[i] == i) ss.pb(i);
    }
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) a[i] = num[a[i]];
    forn(i,0,N) num[i] = 0;
    forn(i,0,n) num[a[i]]++;
    forn(i,2,N) if(num[i] > 0) for(auto x : getdivs(i)) if(x!=i) num[x] += num[i];
    forn(i,2,N) if(num[i] > 0) {
        suml[i] = ll(num[i]) * d2[num[i]-1]%mod;
        num[i] = d2[num[i]]-1;
    }
    ll ans = n;
    for(int i = N-1; i>= 2; i--) {
        if(num[i] > 0) {
            ans = (ans +  ll(n)*num[i] + 2*mod - 2*suml[i]) % mod;
            for(auto x : getdivs(i)) {
                num[x] -= num[i];
                suml[x] -= suml[i];
                if(num[x] < 0) num[x]+=mod;
                if(suml[x] < 0) suml[x]+=mod;
            }
        }
    }
    cout<<ans;
    
}