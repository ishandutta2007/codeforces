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
const int MAXN = 400009;
int n, t[4*MAXN];
void build (int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
    }
}

void update (int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        t[v] += add;
    else {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), add);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
    }
}

int get (int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get (v*2, tl, tm, pos);
    else
        return t[v] + get (v*2+1, tm+1, tr, pos);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    //string s;
   // ll ans = 0;
    scanf("%d", &n);
    vector<pair<pi,int>> otr;
    map<int,int> ind;
    vi kon;
    forn(i,0,n) {
        int l,r;
        scanf("%d %d", &l,&r);
        otr.pb(mp(mp(l,r),i));
        kon.pb(l);
        kon.pb(r);
    }
    sort(all(otr));
    reverse(all(otr));
    sort(all(kon));
    forn(i, 0, 2*n) {
        ind[kon[i]] = i;
    }
    vi dm(2*n, 0);
    vi ans(n);
    build(dm.data(), 1, 0, 2*n-1);
    for(auto seg:otr) {
        int l = ind[seg.first.first];
        int r = ind[seg.first.second];
        ans[seg.second] = get(1, 0, 2*n-1, r);
        update(1, 0, 2*n-1, r, 2*n-1, 1);
    }
    forn(i,0,n) {
        printf("%d\n", ans[i]);
    }
    // cout<<ans;
}