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
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if(l>r) return 999999999;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return min(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
};

class stree2 {
public:
    vi t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    void push(int v) {
        if (t[v] != 0 and v < 2*s) {
            t[2*v] = t[v];
            t[2*v+1] = t[v];
            t[v] = 0;
        }
    }
    
    void set (int v, int tl, int tr, int l, int r, int to) {
        if(tl!=tr) push(v);
        if(l>r) return;
        if (tl == l && tr == r) {
            t[v] = to;
            return;
        }
        int tm = (tl + tr) / 2;
        set (v*2, tl, tm, l, min(r,tm), to);
        set (v*2+1, tm+1, tr, max(l,tm+1), r, to);
    }

    int get(int v, int tl, int tr, int x) {
        if(tl == tr) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        if(x <= tm) return get (v*2, tl, tm, x);
        else return get(v*2+1, tm+1, tr, x);   
    }
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
    int can = 0;
    forn (i,0,n) if(a[i] == 0 or a[i] == q) can = 1;
    if (can == 0){
        cout<<"NO";
        return 0;
    }
    forn(i,0,n) if (a[i] == 0) a[i] = q+1;
    // forn(i,0,n) cout<<a[i]; cout<<endl;
    vvi d(q+2);
    forn(i,0,n) d[a[i]].pb(i);
    stree st;
    stree2 ans;
    st.build(a,1,0,n-1);
    ans.build(a,1,0,n-1);
    forn(i,1,q+1) {
        sort(all(d[i]));
        if (i==1) {
            ans.set(1,0,n-1,0,n-1,1);
        }
        if(d[i].size() == 0) continue;
        int l = d[i][0];
        int r = d[i].back();
        int f = st.get(1,0,n-1,l,r);
        // cout<<i<<l<<r<<f<<endl;
        if (f < i) {
            printf("NO");
            return 0;
        }
        if (i==1) {
            ans.set(1,0,n-1,0,n-1,1);
        }
        else ans.set(1,0,n-1,l,r,i);
        // cout<<i<<endl;
        // forn(i,0,4*n) {
        //     cout<<ans.t[i];
        // }
        // cout<<endl;
    }
    printf("YES\n");
    if (d[q].size() == 0) {
        forn(i,0,n) if(a[i] == q+1) {
            ans.set(1,0,n-1,i,i,q);
            break;
        }
    }
    forn(i,0,n) {
        printf("%d ", ans.get(1,0,n-1,i));
    } 
}