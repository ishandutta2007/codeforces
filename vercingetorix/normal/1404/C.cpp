#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int INF = 1e9;
//class streemin {
//public:
//    vpi t;
//    int s;
//    void build (vi & a, int v, int tl, int tr) {
//        if(v==1) {
//            int n = a.size();
//            t.resize(n * 4);
//            s = n;
//        }
//        if (tl == tr)
//            t[v] = mp(a[tl], tl);
//        else {
//            int tm = (tl + tr) / 2;
//            build (a, v*2, tl, tm);
//            build (a, v*2+1, tm+1, tr);
//            t[v] = min(t[v*2], t[v*2+1]);
//        }
//    }
//
//    pi get (int v, int tl, int tr, int l, int r) {
//        if (l > r)
//            return make_pair (INF, 0);
//        if (l == tl && r == tr)
//            return t[v];
//        int tm = (tl + tr) / 2;
//        return min (
//                        get (v*2, tl, tm, l, min(r,tm)),
//                        get (v*2+1, tm+1, tr, max(l,tm+1), r)
//                        );
//    }
//
//    void update (int v, int tl, int tr, int pos, int new_val) {
//        if (tl == tr)
//            t[v] = mp (new_val, tl);
//        else {
//            int tm = (tl + tr) / 2;
//            if (pos <= tm)
//                update (v*2, tl, tm, pos, new_val);
//            else
//                update (v*2+1, tm+1, tr, pos, new_val);
//            t[v] = min (t[v*2], t[v*2+1]);
//        }
//    }
//};

class stree {
public:
    vi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  (
                    get (v*2, tl, tm, l, min(r,tm)) +
                    get (v*2+1, tm+1, tr, max(l,tm+1), r)
                    );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
        }
    }
};

class streemin {
public:
    vpi t;
    vi pp;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            int n = a.size();
            t.resize(n * 4);
            pp = vi(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = mp(a[tl], tl);
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v].first += pp[v];
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        //        cout<<"UPD "<<tl<<' '<<tr<<' '<<l<<' '<<r<<' '<<val<<endl;
        if (l == tl && tr == r) {
            pp[v] += val;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        //            t[v] = max(t[v],val);
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    void update2 (int v, int tl, int tr, int l, int r, int val) {
        //        cout<<"UPD "<<tl<<' '<<tr<<' '<<l<<' '<<r<<' '<<val<<endl;
        if (l == tl && tr == r) {
            pp[v] = 0;
            t[v] = mp(val, tl);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        //            t[v] = max(t[v],val);
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update2 (v*2, tl, tm, l, min(r,tm), val);
            update2 (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        //        if(tl!=tr) {
        push(v, tl, tr);
        //        }
        if (l>r) return mp(INF, 0);
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        pi ret =  min(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = min(t[v*2], t[v*2+1]);
        return ret;
    }
    
//    int getr(int v, int tl, int tr) {
//        push(v, tl, tr);
//        if (t[v] <= 0) return -1;
//        if (tl == tr) return tl;
//        int tm = (tl + tr) / 2;
//        int vr = getr(v*2+1,tm+1,tr);
//        if (vr >= 0) return vr;
//        return getr(v*2,tl,tm);
//    }
//
//    void go(int v, int tl, int tr) {
//        push(v, tl, tr);
//        if (tl==tr) {
//            cout<<t[v]<<' ';
//            return;
//        }
//        int tm = (tl + tr) / 2;
//        go(v*2,tl,tm);
//        go(v*2+1,tm+1,tr);
//    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    readv(a,n);
    forn(i,0,n) a[i]--;
    vvpi req(n);
    forn(i,0,q) {
        int x,y;
        scanf("%d %d", &x,&y);
        int l = x;
        int r = n-1-y;
        req[l].pb(mp(r,i));
    }
    stree good;
    good.build(n, 1, 0, n-1);
    streemin st;
    vi b(n, INF);
    st.build(b, 1, 0, n-1);
    vi ans(q, -1);
    for(int l = n-1; l>=0; l--) {
        if(a[l] <= l) {
            st.update2(1, 0, n-1, l, l, l-a[l]);
        }
        while(1) {
            auto x = st.get(1, 0, n-1, l, n-1);
            if(x.first <= 0) {
                int pos = x.second;
                good.update(1, 0, n-1, pos, 1);
                st.update2(1, 0, n-1, pos, pos, INF);
                st.update(1, 0, n-1, pos, n-1, -1);
            }
            else break;
        }
        for(auto u : req[l]) ans[u.second] = good.get(1, 0, n-1, l, u.first);
    }
    for(auto x : ans) printf("%d\n", x);
    
}