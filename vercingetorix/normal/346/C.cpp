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
//int t[4000000];
//int lazy[4000000];

//class stree {
//public:
//    int s;
//    void build (vi & a, int v, int tl, int tr) {
//        if(v==1) {
//            s = a.size();
//        }
//        if (tl == tr) {
//            t[v] = tl+1;
//            lazy[v] = 0;
//        }
//        else {
//            int tm = (tl + tr) / 2;
//            build (a, v*2, tl, tm);
//            build (a, v*2+1, tm+1, tr);
//            lazy[v] = 0;
//            t[v] = max(t[v*2], t[v*2 + 1]);
//        }
//    }
//    
//    void push(int v) {
//        if (lazy[v] == 0) return;
//        t[v] = max(t[v], lazy[v]);
//        if(v<2*s) {
//            lazy[v*2] = max(lazy[v], lazy[v*2]);
//            lazy[v*2 + 1] = max(lazy[v], lazy[v*2+1]);
//        }
//        lazy[v] = 0;
//    }
//    
//    void update (int v, int tl, int tr, int l, int r, int add) {
//        push(v);
//        if (l > r)
//            return;
//        if (l == tl && tr == r) {
//            lazy[v] = max(add, lazy[v]);
//            push(v);
//        }
//        else {
//            int tm = (tl + tr) / 2;
//            update (v*2, tl, tm, l, min(r,tm), add);
//            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
//            t[v] = max(t[v*2], t[v*2 + 1]);
//        }
//    }
//    
//    int gmax (int v, int tl, int tr, int l, int r) {
//        push(v);
//        if (l > r)
//            return 0;
//        if (l == tl && tr == r) {
//            return t[v];
//        }
//        else {
//            int tm = (tl + tr) / 2;
//            int ret = max(gmax(v*2, tl, tm, l, min(r,tm)),
//                         gmax(v*2+1, tm+1, tr, max(l,tm+1), r));
//            t[v] = max(t[v*2], t[v*2 + 1]);
//            return ret;
//        }
//    }
//};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi x(n);
    forn(i,0,n) scanf("%d", &x[i]);
    sort(all(x));
    int a,b;
    scanf("%d %d", &a,&b);
    vi y;
    forn(i,0,n) {
        if(i==0 || x[i]!=x[i-1]) y.pb(x[i]);
    }
    n = a-b+1;
//    vi def(n,0);
    vi smax(n,0);
    forn(i,0,n) smax[i] = i+1;
//    st.build(def, 1, 0, n-1);
    for(auto p : y) {
        int s = (b/p)*p;
        while(s<a) {
            if(s>=b) smax[s-b] = max(smax[s-b], s+p-1-b);//st.update(1, 0, n-1, s-b, s-b, s+p-1-b);
            s+=p;
        }
    }
    int ans =0;
    int cur = 0;
    int pt = -1;
    while(cur < a-b) {
        ans++;
        int curwas = cur;
        while(pt<curwas) {
            pt++;
            cur=max(cur,smax[pt]);
        }
//        cur = st.gmax(1, 0, n-1, 0, cur);
    }
    cout<<ans;

}