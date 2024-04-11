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
const int N = 200500;

multiset<int> degs[N];
map<int, int> f[N];
ll d = 0;
int n,q;

void addp(int i, int p) {
    int was = 0;
    if(degs[p].size() == n) was = *degs[p].begin();
    if(f[i].count(p)) degs[p].erase(degs[p].find(f[i][p]));
    f[i][p]++;
    degs[p].insert(f[i][p]);
    if(degs[p].size() == n && *degs[p].begin() > was) d = d*p%mod;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    //int mindiv[N+1];
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
    
    scanf("%d %d", &n, &q);
    readv(a,n);
    
    forn(i,0,n) {
        d = gcd(a[i], d);
        int m = a[i];
        while(m!=1) {
            int p = mindiv[m];
            m/=p;
            int deg = 1;
            while(m%p==0) {
                m/=p;
                deg++;
            }
            f[i][p] = deg;
            degs[p].insert(deg);
        }
    }
    while(q--) {
        int i,x;
        scanf("%d %d", &i, &x);
        i--;
        while(x>1) {
            int p = mindiv[x];
            addp(i, p);
            x/=p;
        }
        printf("%lld\n", d);
    }
    
    
    
}