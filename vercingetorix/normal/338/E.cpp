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

class stree {
public:
    pi t[600000];
    int lazy[600000];
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            s = a.size();
        }
        if (tl == tr) {
            t[v] = mp(a[tl], tl);
            lazy[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            lazy[v] = 0;
            t[v] = min(t[v*2], t[v*2 + 1]);
        }
    }
    
    void push(int v) {
        if (lazy[v] == 0) return;
        t[v].first += lazy[v];
        if(v<2*s) {
            lazy[v*2] += lazy[v];
            lazy[v*2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int add) {
        push(v);
        if (l > r)
        return;
        if (l == tl && tr == r) {
            lazy[v] += add;
            push(v);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            t[v] = min(t[v*2], t[v*2 + 1]);
        }
    }
    const int INF = 1000000;
    pi gmin (int v, int tl, int tr, int l, int r) {
        push(v);
        if (l > r)
        return mp(INF, 0);
        if (l == tl && tr == r) {
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            pi ret = min(gmin(v*2, tl, tm, l, min(r,tm)),
                         gmin(v*2+1, tm+1, tr, max(l,tm+1), r));
            t[v] = min(t[v*2], t[v*2 + 1]);
            return ret;
        }
    }
};

int n,l,h;
stree st;
void br(int ind) {
    int lt = ind - l + 1;
    int rt = ind;
    lt = max(lt,0);
    rt = min(rt,n-l);
    st.update(1, 0, n-l, lt, rt, -1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &l, &h);
    vi b(l);
    forn(i,0,l) scanf("%d", &b[i]);
    vi a(n);
    vpi as;
    forn(i,0,n) {
        scanf("%d", &a[i]);
        as.pb(mp(a[i], i));
    }
    sort(all(as));
    sort(all(b));
    reverse(all(b));
    int ans = n-l+1;
    vi low(n-l+1, 0);
    
    st.build(low, 1, 0, n-l);
    int pt = 0;
    forn(i,0,l) {
        while(pt < n && as[pt].first + b[i] < h) {
            br(as[pt].second);
            pt++;
        }
        while(1) {
            auto x = st.gmin(1, 0, n-l, 0, n-l);
            if(x.first < 0) {
                ans--;
                st.update(1, 0, n-l, x.second, x.second, l);
            }
            else break;
        }
        st.update(1, 0, n-l, 0, n-l, 1);
    }
    cout<<ans;
}