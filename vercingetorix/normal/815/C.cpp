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
int n,b;
const ll INF = 2e9;
vll mer(vll d1, vll d2) {
//    int pt1 = 0;
//    int pt2 = 0;
//    while(pt1<n && d1[pt1] < INF) pt1++;
//    while(pt2<n && d2[pt2] < INF) pt2++;
//    if(pt1 > )
    vll d(n+1, INF);
    forn(j,0,n+1) {
        if(d2[j] >= INF) continue;
        forn(i,0,n+1) {
            if(i+j < n+1) d[i+j] = min(d[i+j], d1[i] + d2[j]);
        }
    }
    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &b);
    vi c(n), d(n);
    vi p(n);
    vvi ch(n);
    vi ss(n,0);
    forn(i,0,n) {
        scanf("%d %d", &c[i], &d[i]);
        if(i>0) {
            scanf("%d", &p[i]);
            p[i] --;
            ch[p[i]].pb(i);
        }
    }
    
    vvll a(n, vll(n+1, INF));
    vvll dc(n, vll(n+1, INF));
    for(int s = n-1; s >= 0; s--) {
        a[s][0] = 0;
        dc[s][0] = 0;
        ss[s] = 1;
        int bu = -1;
        for(auto u : ch[s]) {
            ss[s] += ss[u];
            if(bu == -1 || ss[u] > ss[bu]) bu = u;
        }
        if(bu != -1) {
            dc[s] = dc[bu];
            a[s] = a[bu];
        }
        for(auto u : ch[s]) {
            if(u==bu) continue;
            a[s] = mer(a[s], a[u]);
            dc[s] = mer(dc[s], dc[u]);
        }
        for(int i = n; i >= 1; i--) {
            a[s][i] = min(a[s][i], a[s][i-1] + c[s]);
            dc[s][i] = min(a[s][i], dc[s][i-1] + c[s] - d[s]);
        }
        dc[s][0] = 0;
    }
    int ans = 0;
    forn(i,0,n+1) {
        if(dc[0][i] <= b) ans = max(ans, i);
        if(a[0][i] <= b) ans = max(ans, i);
    }
    cout<<ans;
    
}