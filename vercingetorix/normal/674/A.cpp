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

const int INF = -9999999;
const int MAXN = 5000;
pair<int,int> t[4*MAXN];
int n;
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
        return make_pair (-INF, 0);
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
    int n;
    cin>>n;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    //set<pi> q;
    vi num(n+1,0);
    vi ans(n+1,0);
    forn(l, 0, n) {
        forn(i,0,n+1) num[i] = 0;
        //q.clear();
        //forn(i,1,n+1) q.insert(mp(0, i));
        //q.erase(mp(-num[a[l]], a[l]));
        num[a[l]]++;
        int ind = a[l];
        int best = 1;
        //q.insert(mp(-num[a[l]], a[l]));
        ans[a[l]]++;
        forn(i,l+1,n) {
            num[a[i]]++;
            if (num[a[i]] > best || (num[a[i]] == best && a[i] < ind)) {
                best = num[a[i]];
                ind = a[i];
            }
            ans[ind]++;
        }
    }
    forn(i,1,n+1) cout<<ans[i]<<" ";
}