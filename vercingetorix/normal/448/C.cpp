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
const int MAXN = 5001;
pair<int,int> t[4*MAXN];

pair<int,int> combine (pair<int,int> a, pair<int,int> b) {
    if (a.first < b.first)
        return a;
    if (b.first < a.first)
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
const int INF = 1000000005;
pair<int,int> get_min (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair (INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine (
                    get_min (v*2, tl, tm, l, min(r,tm)),
                    get_min (v*2+1, tm+1, tr, max(l,tm+1), r)
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
    int n;
    vi a;
int go(int l, int r, int cut) {
    if(l>r) return 0;
    int minv = get_min(1, 0, n-1, l, r).first;
    int pos;
    forn(i,l,r+1) {
        if(a[i]==minv) {
            pos = i;
            break;
        }
    }
    int ans = r-l+1;
    int lbest = go(l,pos-1,minv);
    int rbest = go(pos+1,r,minv);
    ans = min(ans, lbest + rbest + minv-cut);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> n;
    a.resize(n);
    forn(i,0,n) cin>>a[i];
    build(a.data(), 1,0,n-1);
    cout<<go(0, n-1, 0);
}