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

const int MAXN = 1000009;
int t[4*MAXN];
void build (int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = t[v*2]^t[v*2+1];
    }
}

void setv(int v, int tl, int tr, int pos, int val) {
    if (tl == tr)
        t[v] ^= val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) setv(v*2, tl, tm, pos, val);
        else setv(v*2+1, tm+1, tr, pos, val);
        t[v] = t[v*2]^t[v*2+1];
    }
}

int get (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return t[v];
    else {
        int tm = (tl + tr) / 2;
        return get(v*2, tl, tm, l, min(r,tm)) ^ get(v*2+1, tm+1, tr, max(l,tm+1), r);
    }
}

vi lfor[1000000];
int a[1000000];
vi ans[1000000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
//    vi a(n);
    forn(i,0,n) scanf("%d",&a[i]);
//    build(a, 1, 0, n-1);
    int m;
    scanf("%d", &m);
    vpi q;
//    map<pi,int> ans;
//    map<pi,int> was;
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x,&y);
        x--;
        y--;
        q.pb(mp(x,y));
//        if(was[mp(x,y)] == 0) {
//            was[mp(x,y)] = 1;
            lfor[y].pb(x);
//            ans[mp(x,y)] = get(1,0,n-1,x,y);
//        }
    }
    
    vi kek(n,0);
    build(kek.data(), 1, 0, n-1);
    map<int, int> lastocc;
    forn(i,0,n) {
        int last = lastocc[a[i]] - 1;
        if(last >= 0) {
            setv(1,0,n-1,last,a[i]);
        }
//        setv(1, 0,n-1,i,a[i]);
        lastocc[a[i]] = i + 1;
        sort(all(lfor[i]));
        for(auto l : lfor[i]) {
            ans[i].pb(get(1,0,n-1,l,i));
        }
    }
    
    forn(i,0,m) {
//        printf("%d\n", ans[q[i]]);
        int r = q[i].second;
        int l = q[i].first;
        int pos = lower_bound(all(lfor[r]), l) - lfor[r].begin();
        printf("%d\n", ans[r][pos]);
    }
    
    
    
}