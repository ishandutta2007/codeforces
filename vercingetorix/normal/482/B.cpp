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
const int MAXN = 100009;
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
        t[v] = t[v]|add;
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
        return t[v] | get (v*2, tl, tm, pos);
    else
        return t[v] | get (v*2+1, tm+1, tr, pos);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi a(n,0);
    build(a.data(),1,0,n-1);
    int l,r,q;
    vpi seg;
    vi res;
    forn(i,0,m) {
        cin>>l>>r>>q;
        l--;
        r--;
        seg.pb(mp(l,r));
        res.pb(q);
        update(1, 0, n-1, l, r, q);
    }
    vi ans(n);
    forn(i,0,n) ans[i]=get(1,0,n-1,i);
    int deg2=1;
    forn(i,0,30) {
        vi chsum;
        int sum = 0;
        forn(j,0,n) {if(ans[j]&deg2) sum++; chsum.pb(sum);}
        forn(k,0,m) {
            if(res[k]&deg2) continue;
            int cnt = chsum[seg[k].second];
            if(seg[k].first>0) cnt-=chsum[seg[k].first - 1];
            if(cnt == seg[k].second - seg[k].first + 1) {
                cout<<"NO";
                return 0;
            }
        }
        deg2*=2;
    }
    cout<<"YES"<<endl;
    for(auto x: ans) cout<<x<<" ";
}