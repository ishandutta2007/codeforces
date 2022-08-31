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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
ll curd[80000];
ll last[80000];
ll dd[80000];
const int LIMIT = 1000000;
vb isp(LIMIT+1, true);
vi mindiv(LIMIT+1, 0);
vi p;
vpi pinc[80000];
int cnt;
ll k;
ll cur;
set<pll> lft;
ll dest[80000];
void recount() {
    forn(i,0,cnt) {
        dd[i] = 0;
        if(curd[i] > 0) {
            dd[i]--;
            for(auto x : pinc[i]) dd[x.first] += x.second;
        }
    }
    
}

void reb() {
    forn(i,0,cnt) {
        if(curd[i] == 0) continue;
        if(dd[i] < 0) dest[i] = cur - curd[i];
        else dest[i] = 0;
        lft.insert(mp(-dest[i], i));
    }
}

void bump(int i) {
    curd[i] += dd[i] * (last[i] - cur);
    last[i] = cur;
}

void upd(int i) {
    lft.erase(mp(-dest[i], i));
    if(dd[i] >= 0) dest[i] = 0;
    else dest[i] = cur-curd[i];
    if(curd[i] > 0) lft.insert(mp(-dest[i], i));
}

void rem(int i) {
    bump(i);
    dd[i]++;
    upd(i);
    for(auto x : pinc[i]) {
        bump(x.first);
        dd[x.first] -= x.second;
        upd(x.first);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    vi pnum(1000000);
    forn(i,0,p.size()) pnum[p[i]] = i;
    cnt = p.size();
    forn(i,0,cnt) {
        int x = p[i]-1;
        vi lol;
        while(x > 1) {
            lol.pb(pnum[mindiv[x]]);
            x /= mindiv[x];
        }
        int pt = 0;
        while(pt < lol.size()) {
            int pr = pt + 1;
            while(pr < lol.size() && lol[pr] == lol[pt]) pr++;
            pinc[i].pb(mp(lol[pt], pr-pt));
            pt = pr;
        }
    }
    
    int m;
    scanf("%d", &m);
    forn(i,0,m) {
        int p;
        ll d;
        scanf("%d %lld", &p, &d);
        curd[pnum[p]] += d;
    }
    
    scanf("%lld", &k);
    
    forn(i,0,20) {
        if(k==0) break;
        recount();
        forn(i,0,cnt) curd[i] += dd[i];
        k--;
    }
    cur = k;
    forn(i,0,cnt) last[i] = cur;
    recount();
    reb();
    lft.insert(mp(1,-1));
    while(1) {
        if(cur == 0) break;
        auto x = *lft.begin();
        ll nt = -x.first;
        if(nt <= 0) break;
        cur = nt;
        rem(x.second);
    }
    vpll ans;
    cur = 0;
    forn(i,0,cnt) {
        bump(i);
        if(curd[i] > 0) ans.pb(mp(p[i], curd[i]));
    }
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%lld %lld\n", x.first, x.second);
    
}