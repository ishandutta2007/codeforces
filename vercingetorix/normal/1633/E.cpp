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
const int A = 50;
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
    scanf("%d %d", &n, &m);
    vi a(m), b(m);
    vi w(m);
    vpi ord;
    forn(i,0,m) {
        scanf("%d %d %d", &a[i], &b[i], &w[i]);
        a[i]--;
        b[i]--;
    }
    
    set<int> imp;
    const int INF = 1e9;
    imp.insert(INF);
    forn(i,0,m) imp.insert(w[i]);
    forn(i,0,m) forn(j,i+1,m) {
        imp.insert((w[i] + w[j])/2);
    }
    vi q;
    for(auto x : imp) q.pb(x);
    vll val;
    vll c;
    forn(it,0,q.size()) {
        int x = q[it];
        int coef = 0;
        ll cur = 0;
        vpi e;
        forn(i,0,m) {
            e.pb(mp(2*abs(x-w[i]) + (w[i]<x ? 0 : 1), i));
        }
        srt(e);
        forn(i,0,n) make_set(i);
        forn(i,0,m) {
            if(find_set(a[e[i].second]) != find_set(b[e[i].second])) {
                union_sets(a[e[i].second], b[e[i].second]);
                cur += e[i].first/2;
                int ind = e[i].second;
                if(w[ind] >= x) coef++;
                else coef--;
            }
        }
        val.pb(cur);
        c.pb(coef);
    }
    auto get = [&](int x) {
        int pos = lower_bound(all(q), x) - q.begin();
        int xto = q[pos];
        return val[pos] + ll(c[pos])*(xto-x);
    };
    int p,k,qa,qb,qc;
    scanf("%d %d %d %d %d", &p, &k, &qa, &qb, &qc);
    readv(qq, p);
    int last = -1;
    ll ans = 0;
    forn(i,0,k) {
        if(i<p) last = qq[i];
        else last = (ll(last)*qa+qb)%qc;
        ans ^= get(last);
//        printf("%lld\n", get(qq[i]));
    }
    cout<<ans;
    
    
}