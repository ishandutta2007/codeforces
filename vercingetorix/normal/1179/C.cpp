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
        if (tl == tr)
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
    int n,m;
    scanf("%d %d", &n, &m);
    readv(a,n);
    readv(b,m);
    stree st;
    int A = 1000000;
    st.build(A+1, 1, 0, A);
    forn(i,0,n) {
//        st.update(1, 0, A, a[i], A, 1);
        st.update(1, 0, A, 0, a[i], 1);
//        st.go(1,0,A);
//        cout<<endl;
    }
    forn(i,0,m) {
        st.update(1, 0, A, 0, b[i], -1);
//        st.go(1,0,A);
//        cout<<endl;
    }
//    st.go(1,0,A);
//    cout<<endl;
    int q;
    read(q);
    forn(i,0,q) {
        int tp,ind,x;
        scanf("%d %d %d", &tp, &ind, &x);
        ind--;
        if (tp == 1) {
            if(x > a[ind]) {
                st.update(1, 0, A, a[ind]+1, x, 1);
//                st.update(1, 0, A, a[ind], x-1, -1);
            }
            else if(a[ind] > x) {
                st.update(1, 0, A, x+1, a[ind], -1);
//                st.update(1, 0, A, x, a[ind]-1, 1);
            }
            a[ind] = x;
        }
        else if (tp == 2) {
            if(x > b[ind]) {
                st.update(1, 0, A, b[ind]+1, x, -1);
            }
            else if(b[ind] > x) {
                st.update(1, 0, A, x+1, b[ind], 1);
            }
            b[ind] = x;
        }
        printf("%d\n", st.getr(1, 0, A));
//        st.go(1,0,A);
//        cout<<endl;
    }
    
}