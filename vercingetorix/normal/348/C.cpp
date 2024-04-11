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
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    scanf("%d %d %d\n", &n,&m,&q);
    vll a(n);
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    scanf("\n");
    const int ksize =320;
    vvi id(m);
    vll md(m,0);
    vi large;
    vi islarge(m,0);
    vi tolarge(m);
    vll defans(m,0);
    vvi mn(n);
    vvi mn2(n);
    forn(i,0,m) {
        int l;
        scanf("%d", &l);
        id[i].resize(l);
        forn(j,0,l) scanf("%d", &id[i][j]);
        forn(j,0,l) id[i][j]--;
        if(id[i].size() > ksize) {
            for(auto u : id[i]) mn[u].pb(large.size());
            large.pb(i);
            islarge[i] = 1;
        }
        else {
            for(auto u : id[i]) mn2[u].pb(i);
        }
        for(auto u : id[i]) defans[i] += a[u];
        scanf("\n");
    }
    forn(i,0,large.size()) {
        tolarge[large[i]] = i;
    }
    vvi per(n, vi(large.size(), 0));
    forn(i,0,n) {
        int k = mn[i].size();
        forn(x,0,k) {
            forn(y,0,k) {
                per[large[mn[i][x]]][mn[i][y]]++;
            }
        }
        for(auto u : mn[i]) {
            for(auto v : mn2[i]) {
                per[v][u]++;
            }
        }
    }
    forn(i,0,q) {
        char c;
        scanf("%c", &c);
        if(c=='+') {
            int k,xx;
            scanf("%d %d\n", &k, &xx);
            ll x = xx;
            k--;
            if (islarge[k]) {
                md[k]+=x;
            }
            else {
                for(auto u : id[k]) a[u]+=x;
                forn(i,0,large.size()) {
                    defans[large[i]] += x * per[k][i];
                }
            }
        }
        else if(c=='?') {
            int k;
            scanf("%d\n", &k);
            k--;
            ll ans = 0;
            forn(i,0,large.size()) {
                ans += md[large[i]] * per[k][i];
            }
            if(islarge[k]) {
                ans += defans[k];
            }
            else {
                for(auto u:id[k]) ans += a[u];
            }
            printf("%lld\n", ans);
        }
    }
    
}