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
    int n,m;
    scanf("%d %d", &n, &m);
    readv(a,n);
    readv(k,m);
    set<int> q;
    forn(i,0,n) q.insert(i);
    vll pref(n);
    pref[0] = a[0];
    forn(i,1,n) pref[i] = pref[i-1] + a[i];
    set<pll> ev;
    forn(i,0,n-1) {
        ev.insert(mp(1-a[i], i));
    }
    int cur = 0;
    vi ans(m);
    vi done(n,0);
    for(int i = m-1; i>=0; i--) {
        int l = k[i];
        while(!ev.empty() && -ev.begin()->first >= l) {
            int f = ev.begin()->second;
            ev.erase(ev.begin());
            if(done[f]) continue;
            auto it = q.lower_bound(f);
            it++;
            it++;
            int to = n-1;
            if(it!=q.end()) to = *it - 1;
            it--;
            done[*it] = 1;
            q.erase(it);
            cur = max(cur, to-f);
            if(to != n-1) {
                ll sum = pref[to];
                if(f > 0) sum -= pref[f-1];
                int len = to-f+1;
                ll kneed = (sum -1)/len;
                ev.insert(mp(-kneed, f));
            }
        }
        ans[i] = cur;
    }
    forn(i,0,m) printf("%d ", ans[i]);
    
    
}