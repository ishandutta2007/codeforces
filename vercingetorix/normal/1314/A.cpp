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

set<pi> q;

int getr(int v) {
    auto it = q.lower_bound(mp(v+1,0));
    if(it == q.begin()) return v;
    it--;
    if(it->second < v) return v;
    else return it->second+1;
}

void add(int v) {
    pi cur = mp(v,v);
    q.insert(cur);
    auto it = q.find(cur);
    if(it!=q.begin()) {
        it--;
        if(it->second == v-1) {
            pi ncur = mp(it->first, v);
            q.erase(it);
            q.erase(cur);
            q.insert(ncur);
            cur = ncur;
        }
    }
    it = q.find(cur);
    it++;
    if(it != q.end()) {
        if(it->first == v+1) {
            pi ncur = mp(cur.first, it->second);
            q.erase(it);
            q.erase(cur);
            q.insert(ncur);
        }
    }
    
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    readv(t,n);
    vpi ord;
    forn(i,0,n) {
        ord.pb(mp(t[i], i));
    }
    srtrev(ord);
    ll ans = 0;
    forn(i,0,n) {
        int v = ord[i].second;
        int pos = getr(a[v]);
        ans += (ll)t[v] * (pos-a[v]);
        add(pos);
    }
    cout<<ans;
    
    
}