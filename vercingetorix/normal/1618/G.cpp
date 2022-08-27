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

const int A = 400500;
int parent[A];
ll pref[A];
int rk[A];
int my[A];
int mx[A];
ll curans = 0;

void make_set (int v, int im) {
    parent[v] = v;
    rk[v] = 0;
    my[v] = im;
    mx[v] = v;
    if(im == 1) {
        curans += pref[v];
        if(v>0) curans -= pref[v-1];
    }
}

ll get(int v) {
    ll ret = pref[mx[v]];
    if(my[v] <= mx[v]) ret -= pref[mx[v] - my[v]];
    return ret;
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
        curans -= get(a);
        curans -= get(b);
        mx[a] = max(mx[a], mx[b]);
        my[a] += my[b];
        curans += get(a);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,qn;
    scanf("%d %d %d", &n, &m, &qn);
    readv(a,n);
    readv(b,m);
    readv(q,qn);
    vpi d;
    forn(i,0,n) d.pb(mp(a[i], i));
    forn(i,0,m) d.pb(mp(b[i], i+n));
    vpi rq;
    forn(i,0,qn) rq.pb(mp(q[i], i));
    srt(rq);
    vll ans(qn, 0);
    srt(d);
    ll sum = 0;
    forn(i,0,n+m) {
        sum += d[i].first;
        pref[i] = sum;
    }
    forn(i,0,n+m) {
        if(d[i].second < n) make_set(i, 1);
        else make_set(i, 0);
    }
    vpi ev;
    forn(i,1,n+m) {
        ev.pb(mp(d[i].first - d[i-1].first, i));
    }
    srt(ev);
    int pt = 0;
    forn(i,0,qn) {
        while(pt<ev.size() && ev[pt].first <= rq[i].first) {
            union_sets(ev[pt].second, ev[pt].second - 1);
            pt++;
        }
        ans[rq[i].second] = curans;
    }
    forn(i,0,qn) printf("%lld\n", ans[i]);
    
    
    
}