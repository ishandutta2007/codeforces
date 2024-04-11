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

vll pref;
int m,n;

ll get(int l, int r) {
    if(r > l) {
        return pref[r] - pref[l];
    }
    else return pref[r+2*n] - pref[l];
//    else return pref[r] + pref[2*n-1]-pref[l];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &m, &n);
    readv(a,n);
    readv(b,n);
    vpi q;
    forn(i,0,n) {
        q.pb(mp(a[i], i+1));
        q.pb(mp(b[i], -i-1));
    }
    
    srt(q);
    vi ans(n);
    int pos = -1;
    int cur = 0;
    map<int, vi> w;
    ll sum = 0;
    forn(i,0,2*n) {
        if(q[i].second > 0) sum+=q[i].first;
        else sum -= q[i].first;
        pref.pb(sum);
        if(q[i].second > 0) cur++;
        else cur--;
        w[cur].pb(i);
    }
    forn(i,0,2*n) {
        if(q[i].second > 0) sum+= m+q[i].first;
        else sum -= m+q[i].first;
        pref.pb(sum);
    }
    int ind = -1;
    ll best = 1e18;
    for(auto cut : w) {
        vi p = cut.second;
        ll cand = 0;
        forn(i,0,p.size()) {
            int s = p[i];
            int e = p[(i+1)%p.size()];
            cand += abs(get(s, e));
        }
        if(cand < best) {
            best = cand;
            ind = cut.first;
        }
    }
    printf("%lld\n", best);
    vi p = w[ind];
    
    forn(i,0,p.size()) {
        int s = p[i];
        int e = p[(i+1)%p.size()];
        vi ia;
        vi ib;
        int it = s;
        while(1){
            it = (it+1)%(2*n);
            if(q[it].second > 0) ia.pb(q[it].second - 1);
            else ib.pb(-q[it].second - 1);
            if(it == e) break;
        }
        forn(i,0,ia.size()) {
            ans[ia[i]] = ib[i] + 1;
        }
    }
    forn(i,0,n) printf("%d ", ans[i]);
    
    
    
}