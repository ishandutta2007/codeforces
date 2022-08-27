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
const int A = 250;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vll x(m), y(m);
    forn(i,0,m) cin>>x[i]>>y[i];
    ll ans = 0;
    vvpi fun(n+1);
    forn(i,0,m) forn(j,i+1,m) {
        if(y[i] == y[j]) continue;
        ll y1 = y[i];
        ll y2 = y[j];
        ll x1 = x[i];
        ll x2 = x[j];
        if(y1 > y2) {
            swap(x1,x2);
            swap(y1,y2);
        }
        ll dy = y2-y1;
        ll dx = x1-x2;
        ll d = gcd(dy, abs(dx));
        dx/=d;
        dy/=d;
        if(y1 % dy != 0) continue;
        ll fin = x1 + y1/dy * dx;
        if(fin > 0 && fin <= n) fun[fin].pb(mp(i,j));
    }
    vi cnt(m,0);
    forn(i,1,n+1) {
        if(fun[i].empty()) ans++;
        else {
            forn(j,0,m) make_set(j);
            for(auto xx : fun[i]) union_sets(xx.first, xx.second);
            forn(j,0,m) cnt[j] = 0;
            forn(j,0,m) cnt[find_set(j)]++;
            int mx = 0;
            forn(j,0,m) mx = max(mx, cnt[j]);
            ans += mx;
        }
    }
    cout<<ans;
    
}