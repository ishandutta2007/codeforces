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
typedef std::vector<ld> vd;
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

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ld len(int x, int y) {
    return sqrt(ld(ll(x)*x+ll(y)*y));
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vector<pair<pi, int>> q;
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        if(x==0 && y==0) continue;
        int d = gcd(abs(x), abs(y));
        q.pb(mp(mp(x/d, y/d), d));
    }
    srt(q);
    vd un;
    vvi ind;
    forn(i,0,q.size()) {
        if(i==0 || q[i].first != q[i-1].first) {
            un.pb(len(q[i].first.first, q[i].first.second));
            ind.pb(vi(1, q[i].second));
        }
        else ind.back().pb(q[i].second);
    }
    ld ans = 0;
    forn(i,0,un.size()) {
        if((n - ind[i].size())*2 <= k) {
            forn(j,0,un.size()) {
                if(j!=i) {
                    int l = ind[j].size();
                    forn(f,0,l) {
                        ans += un[j]*ind[j][f]*(k - 2*l + 2*f + 1);
                    }
                }
                else {
                    vi to;
                    int tot = k - (n-ind[i].size());
                    forn(y,0,tot-k/2) to.pb(ind[i][y]);
                    forn(y,ind[i].size() - k/2,ind[i].size()) to.pb(ind[i][y]);
                    int l = to.size();
                    forn(f,0,l) {
                        ans += un[j]*to[f]*(k - 2*l + 2*f + 1);
                    }
                }
            }
            printf("%.10lf", (double) ans);
            exit(0);
        }
    }
    set<pair<ld, int>> e;
    vi taken(un.size(), 0);
    e.insert(mp(0,-1));
    forn(i,0,un.size()) {
        int l = ind[i].size();
        ld cur = un[i]*(ll(k-1)*ind[i][l-1-taken[i]] - 2*taken[i]);
        e.insert(mp(-cur, i));
    }
    forn(iqef,0,k) {
        auto it = e.begin();
        ans -= it->first;
        int i = it->second;
        e.erase(it);
        if(i == -1) continue;
        taken[i]++;
        if(taken[i] < ind[i].size()) {
            int l = ind[i].size();
            ld cur = un[i]*ind[i][l-1-taken[i]]*(ll(k-1) - 2*taken[i]);
            e.insert(mp(-cur, i));
        }
    }
    printf("%.10lf", (double) ans);
    
}