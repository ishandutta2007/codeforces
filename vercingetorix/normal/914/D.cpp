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

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

class stree {
public:
    vi t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = gcd(t[v*2], t[v*2+1]);
        }
    }
    
    void set (int v, int tl, int tr, int pos, int val) {
        if (pos == tl && tr == pos) {
            t[v] = val;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos, val);
            else set(v*2+1, tm+1, tr, pos, val);
            t[v] = gcd(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return gcd(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
    
    int tor(int v, int tl, int tr, int pos, int x) {
        if(pos > tr) return tr;
        if(t[v] % x == 0) return tr;
        if(tl == tr) return tr - 1;
        int tm = (tl + tr) / 2;
        int torl = tor(v*2, tl, tm, pos, x);
        if(torl < tm) return torl;
        return tor(v*2+1, tm+1, tr, pos, x);
    }
    
    int tol(int v, int tl, int tr, int pos, int x) {
        if(pos < tl) return tl;
        if(t[v] % x == 0) return tl;
        if(tl == tr) {
            return tr + 1;
        }
        int tm = (tl + tr) / 2;
        int tolr = tol(v*2+1, tm+1, tr, pos, x);
        if(tolr > tm+1) return tolr;
        int toll = tol(v*2, tl, tm, pos, x);
        return toll;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    readv(a,n);
    stree st;
    st.build(a, 1, 0, n-1);
    int q;
    scanf("%d", &q);
    forn(affa,0,q) {
        int t;
        scanf("%d", &t);
        if(t==2) {
            int i, y;
            scanf("%d %d", &i, &y);
            st.set(1, 0, n-1, i-1, y);
        }
        else {
            int l,r,x;
            scanf("%d %d %d", &l, &r, &x);
            l--, r--;
            int il = st.tor(1, 0, n-1, l, x);
            int ir = st.tol(1, 0, n-1, r, x);
            if(ir - il > 2) printf("NO\n");
            else printf("YES\n");
        }
    }
    
}