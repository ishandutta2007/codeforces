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
vi pts;
vi l;
vi r;
int n;
const int INF = 1e9;
int get(int k, int to, bool can) {
    if(32*k > r[to] * n) {
        int nq = (32*k-n*r[to] + r[to]-1)/r[to];
        return nq;
    }
    else if(32*k <= l[to] * n) {
        if(to == 5) return 0;
        if(!can) return INF;
        return (l[to] * n -32*k + 32-l[to])/(32-l[to]);
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    vi a(5), b(5);
    vi cnt(5,0);
    forn(i,0,5) {
        read(a[i]);
        if(a[i] >= 0) cnt[i] ++;
    }
    forn(i,0,5) {
        read(b[i]);
        if(b[i] >= 0) cnt[i] ++;
    }
    forn(i,2,n) {
        forn(j,0,5) {
            int x;
            read(x);
            if(x >= 0) cnt[j]++;
        }
    }
    
    pts.pb(500);
    pts.pb(1000);
    pts.pb(1500);
    pts.pb(2000);
    pts.pb(2500);
    pts.pb(3000);
    
    for(int i = 4; i>=0; i--) {
        l.pb(1<<i);
        r.pb(1<<(i+1));
    }
    l.pb(0);
    r.pb(1);
    
    int ans = INF;
    vi tr;
    tr.pb(0);
    forn(i,0,5) forn(to,0,6) {
        tr.pb(get(cnt[i],to,(a[i] >= 0)));
    }
    // forn(i,0,500) tr.pb(i);
    sort(all(tr));
    int last = -1;
    for(auto add : tr) {
        if(add == last) continue;
        last = add;
        if(add == INF) break;
        forn(uki,0,6*6*6*6*6) {
            int x = uki;
            vi diap;
            forn(i,0,5) {
                diap.pb(x%6);
                x/=6;
            }
            int ap = 0;
            int bp = 0;
            forn(i,0,5) if(a[i]>=0) ap += pts[diap[i]]-a[i]*pts[diap[i]]/250;
            forn(i,0,5) if(b[i]>=0) bp += pts[diap[i]]-b[i]*pts[diap[i]]/250;
            if(ap<=bp) continue;
            bool poss = true;
            forn(i,0,5) {
                int mn = cnt[i];
                int mx = cnt[i];
                if(a[i] >= 0) mx += add;
                if(32*mn > r[diap[i]] * (n+add)) poss = false;
                if(32*mx <= l[diap[i]] * (n+add)) {
                    if(diap[i] != 5) poss = false;
                }
            }
            if(poss) {
                cout<<add;
                return 0;
            }
        }
    }
    cout<<-1;
    
}