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

#define pb push_back
#define mp make_pair
const int MAXN = 100001;
const int A = 100;
int cnt[MAXN];
int mv[3*MAXN];
int ans[3*MAXN];

int diff[A][A];
int mx[A][A];
int mn[A][A];
int sa[A];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    vpi ai;
    forn(i,0,n) ai.pb(mp(a[i], i));
    sort(all(ai));
    int qn;
    scanf("%d", &qn);
    vi l(qn), r(qn);
    forn(i,0,qn) {
        scanf("%d %d", &l[i], &r[i]);
        l[i]--; //r[i]--;
    }
    int s = 0;
    const int INF = 1000000000;
    forn(i,0,qn) ans[i] = INF;
    forn(i,0,qn) mv[i] = -INF;
    while(s < n) {
        forn(i,0,n+1) cnt[i] = 0;
        vi ind;
        forn(i,s,min(s+A,n)) ind.pb(ai[i].second);
        int k = ind.size();
        for(auto x : ind) cnt[x+1] = 1;
        forn(i,0,n) cnt[i+1] += cnt[i];
        sort(all(ind));
        forn(i,0,k) sa[i] = a[ind[i]];
        forn(i,0,A) forn(j,i,A) diff[i][j] = INF;
        forn(i,0,A) forn(j,i,A) mx[i][j] = -INF;
        forn(i,0,A) forn(j,i,A) mn[i][j] = INF;
        forn(s,0,A) {
            set<int> vals;
            vals.insert(sa[s]);
            int res = INF;
            int resmx = sa[s];
            int resmn = sa[s];
            mx[s][s] = resmx;
            mn[s][s] = resmn;
            forn(e,s+1,A) {
                int x = sa[e];
                auto it = vals.lower_bound(x);
                if (it != vals.end()) res = min(res, *it-x);
                if (it != vals.begin()) {
                    it--;
                    res = min(res, x-*it);
                }
                vals.insert(x);
                diff[s][e] = res;
                resmx = max(resmx, x);
                resmn = min(resmn, x);
                mx[s][e] = resmx;
                mn[s][e] = resmn;
            }
        }
        forn(i,0,qn) {
            int cr = cnt[r[i]];
            int cl = cnt[l[i]];
            if (cr > cl) {
                cr--;
//                ans[i] = min(ans[i], diff[cl][cr]);
                ans[i] = min(ans[i], min(mn[cl][cr] - mv[i], diff[cl][cr]));
                mv[i] = mx[cl][cr];
            }
        }
        s += A;
    }
    forn(i,0,qn) printf("%d\n", ans[i]);
    
}