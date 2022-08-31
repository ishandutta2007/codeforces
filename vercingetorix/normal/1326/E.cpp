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
const int INF =1e9;
class stree {
public:
    vi t;
    vi pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vi(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v] += pp[v];
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
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        //        if(tl!=tr) {
        push(v, tl, tr);
        //        }
        if (l>r) return -INF;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int ret =  max(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = max(t[v*2], t[v*2+1]);
        return ret;
    }
    
    int getr(int v, int tl, int tr) {
        push(v, tl, tr);
        if (t[v] <= 0) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int vr = getr(v*2+1,tm+1,tr);
        if (vr >= 0) return vr;
        return getr(v*2,tl,tm);
    }
    
    void go(int v, int tl, int tr) {
        push(v, tl, tr);
        if (tl==tr) {
            cout<<t[v]<<' ';
            return;
        }
        int tm = (tl + tr) / 2;
        go(v*2,tl,tm);
        go(v*2+1,tm+1,tr);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(p,n);
    readv(q,n);
    stree st;
    st.build(n, 1, 0, n-1);
    vi w(n,0);
    int curmax = n;
    forn(i,0,n) w[p[i] - 1] = i;
//    st.update(1, 0, n-1, w[n-1], n-1, 1);
    forn(i,0,n) {
        while(st.get(1, 0, n-1, 0, n-1) <= 0) {
            curmax--;
            st.update(1, 0, n-1, 0,w[curmax], 1);
        }
        printf("%d ", curmax+1);
        st.update(1, 0, n-1, 0, q[i]-1, -1);
    }

}