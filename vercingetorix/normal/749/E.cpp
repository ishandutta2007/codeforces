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


const int MAXN = 100009;
int n;
ll t[4*MAXN];
void build (vi & a, int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update (int v, int tl, int tr, int l, int r, ll add) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        t[v] += add;
    else {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), add);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        t[v] = t[v*2]+t[v*2+1];
    }
}



ll get (int v, int tl, int tr,  int l, int r) {
    if (l>r) return 0;
    if (tl == l && tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    return get (v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
}

int t2[4*MAXN];
void build2 (vi & a, int v, int tl, int tr) {
    if (tl == tr)
        t2[v] = 0;
    else {
        int tm = (tl + tr) / 2;
        build2 (a, v*2, tl, tm);
        build2 (a, v*2+1, tm+1, tr);
        t2[v] = 0;
    }
}

void update2 (int v, int tl, int tr, int l, int r, ll add) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        t2[v] = 1;
    else {
        int tm = (tl + tr) / 2;
        update2 (v*2, tl, tm, l, min(r,tm), add);
        update2 (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        t2[v] = t2[v*2]+t2[v*2+1];
    }
}


int get2 (int v, int tl, int tr,  int l, int r) {
    if (l>r) return 0;
    if (tl == l && tr == r)
        return t2[v];
    int tm = (tl + tr) / 2;
    return get2 (v*2, tl, tm, l, min(r,tm)) + get2(v*2+1, tm+1, tr, max(l,tm+1), r);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi init(n,0);
    build(init,1,0,n-1);
    build2(init,1,0,n-1);
    vi a(n);
    vi w(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
        a[i]--;
//        a[i]=n-1-i;
//        a[i]=i;
        w[a[i]] = i;
    }
    ld invsum = 0;
    ll invnum = 0;
    forn(i,0,n) {
        ll x = w[i];
        ll sumr = get(1,0,n-1,x+1,n-1);
        invnum += get2(1,0,n-1,x+1,n-1);
        invsum += (ld)((x+1) * sumr);
        update(1, 0, n-1, x, x, n-x);
        update2(1, 0, n-1, x, x, 1);
    }
    ll tot = ((ll)n*((ll)n+1))/2;
    ld ans= (ld)invnum - (ld)invsum/(ld)tot;
    ld totpr = 0;
    forn(i,1,n+1) {
        ll len =i;
        ll kol = n-len+1;
        totpr += (ld)((kol*len*(len-1))/2);
    }
    ans += totpr/(ld)((ll)n*((ll)n+1));
    printf("%.14lf", (double)ans);
}