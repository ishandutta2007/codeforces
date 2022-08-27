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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

const int mil = 1000000;
const int mil15 = mil*3/2;
int has[mil15];
int did[mil15];

int t[mil15*4 + 1000];
class stree {
public:
    void build (int v, int tl, int tr) {
        if (tl == tr)
            t[v] = tl;
        else {
            int tm = (tl + tr) / 2;
            build (v*2, tl, tm);
            build (v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    void set (int v, int tl, int tr, int pos) {
        if (tl == tr) {
            t[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos <= tm) set (v*2, tl, tm, pos);
            else set (v*2+1, tm+1, tr, pos);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return max(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
};

class stree2 {
public:
    void build (int v, int tl, int tr) {
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build ( v*2, tl, tm);
            build ( v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    void set (int v, int tl, int tr, int pos) {
        if (pos == tl && tr == pos) {
            t[v] = 1;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos);
            else set(v*2+1, tm+1, tr, pos);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return get (v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
    }
};



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    stree st;
    st.build(1, 0, mil15);
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) {
        int pos = st.get(1, 0, mil15, 0, a[i]+mil);
        a[i] = pos;
        has[pos] = 1;
        st.set(1, 0, mil15, pos);
//        cout<<a[i]-mil<<endl;
    }
    int curp = 0;
    int curl = 0;
    stree2 st2;
    st2.build(1, 0, mil15);
    forn(i,0,n) {
        did[a[i]] = 1;
        if(a[i] < curp+mil) curl++;
        st2.set(1, 0, mil15, a[i]);
        while(curl - did[curp-1+mil] +curp > 0) {
            curl -= did[curp-1+mil];
            curp--;
        }
        int pos = st2.get(1, 0, mil15, mil+curp, mil15);
        int neg = i+1-pos;
        if(did[curp+mil] && curp == -curl) neg++;
        printf("%d\n", pos-neg);
    }
    
    
    
}