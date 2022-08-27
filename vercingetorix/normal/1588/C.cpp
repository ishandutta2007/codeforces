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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

class stree {
public:
    vi t;
//    vi pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
//            pp = vi(n*4,-1);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = -1;
        }
    }
    
    void push(int v, int tl, int tr) {
        if(tl == tr || t[v] == -1) return;
        t[2*v] = t[v];
        t[2*v+1] = t[v];
        t[v] = -1;
//        if(pp[v] == -1) return;
//        t[v] = pp[v];
//        if(tl != tr) {
//            pp[2*v] += pp[v];
//            pp[2*v+1] += pp[v];
//        }
//        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            t[v] = val;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr) {
            t[v] ++ ;
            return t[v] - 1;
        }
        int tm = (tl + tr) / 2;
        int ret =  get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        ll sum = 0;
        set<ll> comp;
        comp.insert(sum);
        forn(i,0,n) {
            if(i%2==0) sum += a[i];
            else sum -= a[i];
            comp.insert(sum);
        }
        map<ll, int> xcomp;
        int m = 0;
        for(auto x : comp) xcomp[x] = m++;
        stree st;
        ll ans = 0;
        
        st.build(m, 1, 0, m-1);
        st.get(1, 0, m-1, xcomp[0], xcomp[0]);
        sum = 0;
        forn(i,0,n) {
            if(i%2==0) sum += a[i];
            else sum -= a[i];
            int pos = xcomp[sum];
            ans += st.get(1, 0, m-1, pos, pos);
//            int v = st.get(1, 0, m-1, pos, pos);
            if(i%2==0) {
//                ans += v;
                st.update(1, 0, m-1, pos+1, m-1, 0);
            }
            else {
                st.update(1, 0, m-1, 0, pos-1, 0);
            }
        }
//        st.build(m, 1, 0, m-1);
//        st.get(1, 0, m-1, xcomp[0], xcomp[0]);
//        sum = 0;
//        forn(i,0,n) {
//            if(i%2==0) sum += a[i];
//            else sum -= a[i];
//            int pos = xcomp[sum];
//            int v = st.get(1, 0, m-1, pos, pos);
//            if(i%2==1) {
//                ans += v;
//                st.update(1, 0, m-1, 0, pos-1, 0);
//            }
//        }
        printf("%lld\n", ans);
        
    }
    
    
}