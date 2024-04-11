#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int MAXN = 1000;
vector<int> lst[MAXN];
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        
    }
}

bool is2(ll n) {
    ll l = 1;
    ll r = 1000000001;
    while(r-l>1) {
        ll m = (r+l)/2;
        if(m*m > n) r=m;
        else l=m;
    }
    return l*l == n;
}


ll mul(ll a, ll b) {
    return a*b % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vvll cnk(401, vll(401, 0));
    forn(i,0,401) cnk[i][0] = 1;
    forn(i,1,401) {
        forn(j,1,i+1) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    int n;
    scanf("%d", &n);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    forn(i,0,n) make_set(i);
    forn(i,0,n) forn(j,i+1,n) {
        if(is2(a[i]*a[j])) union_sets(i, j);
    }
    vi cnt;
    forn(i,0,n) if(lst[i].size() != 0) cnt.pb(lst[i].size());
    
    vll f(400,0);
    f[0] = 1;
    
    int tot = 0;
//    reverse(all(cnt));
    for(auto K : cnt) {
        vll nf(400,0);
        forn(z, 0, tot+1) {
            if (f[z] == 0) continue;
            ll w = tot+1 - z;
            forn(g, 1, K+1) {
                forn(l, 0, g+1) {
                    if (l <= z && l <= g && g-l <= w) {
                        ll ways = cnk[K-1][g-1];
                        ways = mul(ways, cnk[z][l]);
                        ways = mul(ways, cnk[w][g-l]);
                        ways = mul(ways, f[z]);
                        
                        int y = z - l + K - g;
                        
                        nf[y] = (nf[y]+ways)%mod;
                    }
                }
            }
        }
        
        tot += K;
        f = nf;
    }
    for(auto k : cnt) {
        forn(i,1,k+1) f[0] = (f[0] * (ll)i)%mod;
    }
//    for(auto x : cnt) cout<<x<<' ';
    cout<<f[0];
    
    
    
}