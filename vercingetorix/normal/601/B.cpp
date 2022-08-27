#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <list>
#include <map>
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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

pair<int,int> t[4*100001];

pair<int,int> combine (pair<int,int> a, pair<int,int> b) {
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    return make_pair (a.first, a.second + b.second);
}

void build (int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = make_pair (a[tl], 1);
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = combine (t[v*2], t[v*2+1]);
    }
}

pair<int,int> get_max (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair (-9999999999, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine (
                    get_max (v*2, tl, tm, l, min(r,tm)),
                    get_max (v*2+1, tm+1, tr, max(l,tm+1), r)
                    );
}

void update (int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        t[v] = make_pair (new_val, 1);
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine (t[v*2], t[v*2+1]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,q;
    string s;
    ll ans = 0;
    scanf("%d %d", &n, &q);
    vi a(n);
    
    forn(i,0,n) {
        scanf("%d", &a[i]);
    }
    vi b(n-1);
    vpi so;
    forn(i,0,n-1) {
        b[i] = abs(a[i]-a[i+1]);
     //   so.pb(b[i], i);
    }
    deque<pi> val;
    val.pb(mp(b[0], 0));
    vi nx(n-1);
    vi px(n-1);
    forn(i, 1, n-1) {
        while((val.size()>0)&&(val.back().first < b[i])) {
            nx[val.back().second] = i;
            val.pop_back();
        }
        val.pb(mp(b[i],i));
    }
    while(val.size()>0) {
        nx[val.back().second] = n-1;
        val.pop_back();
    }
    val.pb(mp(b[n-2], n-2));
    for(int i = n-3; i>=0; i--) {
        while((val.size()>0)&&(val.back().first <= b[i])) {
            px[val.back().second] = i;
            val.pop_back();
        }
        val.pb(mp(b[i],i));
    }
    while(val.size()>0) {
        px[val.back().second] = -1;
        val.pop_back();
    }

 //   return 0;
    build(b.data(), 1, 0, n-2);
    forn(i,0,q) {
        int x,y;
        scanf("%d %d", &x,&y);
        x--;
        y--;
        //y--;
        vpi si;
        ll ans = 0;
        forn(j,x,y) {
            ans += 1ll * b[j] * (j - max(x-1, px[j])) * (min(y, nx[j]) - j);
        }
        /*forn(j,x,y) si.pb(mp(b[j], j));
        sort(all(si));
        set<int> ogr;
        ogr.insert(x-1);
        ogr.insert(y);
        for(int j = si.size() - 1; j>=0; j--) {
            auto it = ogr.lower_bound(si[j].second);
            auto it2 = it;
            it2--;
            ans+=1ll * si[j].first * (*it - si[j].second) * (si[j].second - *it2);
            ogr.insert(si[j].second);
        }
         */
        printf("%I64d\n", ans);
    }
    //cout<<ans;
}