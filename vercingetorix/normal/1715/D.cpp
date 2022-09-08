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
    int n,q;
    scanf("%d %d", &n, &q);
    vi need1(n,0);
    vi need0(n,0);
    vi u(q), v(q), a(q);
    vvi to(n);
    forn(i,0,q) {
        scanf("%d %d %d", &u[i], &v[i], &a[i]);
        --u[i]; --v[i];
        if(v[i] < u[i]) swap(u[i], v[i]);
        if(u[i] == v[i]) need1[u[i]] |= a[i];
        else to[u[i]].pb(i);
        forn(bit,0,30) if((a[i]&(1<<bit))==0) {
            need0[u[i]] |= 1<<bit;
            need0[v[i]] |= 1<<bit;
        }
        
    }
    forn(i,0,n) {
        for(auto j : to[i]) {
            forn(bit,0,30) if(a[j]&(1<<bit)) {
                if((need0[v[j]]&(1<<bit))) need1[i] |= 1<<bit;
            }
        }
        for(auto j : to[i]) {
            forn(bit,0,30) if(a[j]&(1<<bit)) {
                if((need1[i]&(1<<bit))==0) need1[v[j]] |= 1<<bit;
            }
        }
        printf("%d ", need1[i]);
    }
    
}