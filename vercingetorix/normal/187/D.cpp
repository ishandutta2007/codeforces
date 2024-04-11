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

//const long long mod = 1000000007;
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
const int A = 100500;
ll ans[A];
int parent[A];
vi ver[A];
ll add[A];
int t[A];

void make_set (int v) {
    parent[v] = v;
    ver[v].pb(v);
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (ver[a].size() < ver[b].size())
            swap (a, b);
        for(auto v : ver[b]) {
            ans[v] += add[b]-add[a];
            parent[v] = a;
            ver[a].pb(v);
        }
        ver[b].clear();
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,g,r;
    scanf("%d %d %d", &n, &g, &r);
    readv(len, n+1);
    ll sum = 0;
    int mod = g+r;
    int k;
    scanf("%d", &k);
    forn(i,0,k) scanf("%d", &t[i]);
//    vll ans(k, 0);
    forn(i,0,k) {
        ans[i] = t[i];
        t[i] %= mod;
//        ans[i] -= t[i];
    }
    forn(i,0,k) make_set(i);
    set<pi> q;
    forn(i,0,k) q.insert(mp(t[i], i));
    forn(i,0,n) {
        sum += len[i];
        int rs = (g + mod - sum%mod)%mod;
        int re = rs+r;
        vpi todel;
        auto it = q.lower_bound(mp(rs,0));
        while(it!=q.end() && it->first <= re) {
            todel.pb(*it);
            add[it->second] += re - it->first;
            it++;
        }
        re -= mod;
        if(re >= 0) {
            it = q.begin();
            while(it!=q.end() && it->first <= re) {
                todel.pb(*it);
                add[it->second] += re - it->first;
                it++;
            }
        }
        for(auto x : todel) q.erase(x);
        forn(i,1,todel.size()) union_sets(todel[i].second, todel[i-1].second);
        if(!todel.empty()) {
            int v = find_set(todel[0].second);
//            ll curt = (sum + t[v] + add[v])%mod;
//            add[v] += (mod-curt)%mod;
            q.insert(mp((re+mod)%mod, v));
        }
    }
    sum += len[n];
    
    forn(i,0,k) for(auto v : ver[i]) ans[v] += sum + add[i];
    forn(i,0,k) printf("%lld\n", ans[i]);
}