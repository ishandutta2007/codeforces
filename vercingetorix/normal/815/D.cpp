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
    int n,p,q,r;
    scanf("%d %d %d %d", &n, &p, &q, &r);
    vll xby(p, -1);
    vll ybx(q, -1);
    vll cbx(p, 0);
    vll cby(q, 0);
    vvll ubx(r), uby(r);
    forn(i,0,n) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        
        a--; b--; c--;
        xby[a] = max(xby[a], (ll)b);
        ybx[b] = max(ybx[b], (ll)a);
        cbx[a]++;
        cby[b]++;
        ubx[c].pb(a);
        uby[c].pb(b);
    }
    for(int i = p - 1; i > 0; i--) {
        xby[i-1] = max(xby[i-1], xby[i]);
    }
    for(int i = q - 1; i > 0; i--) {
        ybx[i-1] = max(ybx[i-1], ybx[i]);
    }
    ll ans = 0;
    ll cx = p;
    ll cy = q;
    ll cs = 0;
    forn(z,0,r) {
        while(cx > 0 && cbx[cx-1] == 0) {
            cx--;
            cs += q - max(xby[cx]+1, cy);
        }
        while(cy > 0 && cby[cy-1] == 0) {
            cy--;
            cs += p - max(ybx[cy]+1, cx);
        }
        for(auto it : ubx[z]) cbx[it]--;
        for(auto it : uby[z]) cby[it]--;
        ans += cs;
    }
    cout<<ans;
}