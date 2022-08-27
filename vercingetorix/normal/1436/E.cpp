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
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
            t[v] = tl;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void push(int v) {
        if (t[v] != 0) {
            t[2*v] = max(t[2*v], t[v]);
            t[2*v+1] = max(t[2*v+1], t[v]);
            t[v] = 0;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = max(t[v],val);
        else {
            push(v);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return get (v*2, tl, tm, pos);
        else
            return get (v*2+1, tm+1, tr, pos);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
//    cout << n;
    readv(a,n);
    stree st;
    st.build(n, 1, 0, n-1);
    vvi pos(n+2);
    forn(i,0,n) {
        pos[a[i]].pb(i);
    }
    int ans = 1;
    if(pos[1].size() == n) {
        cout<<1;
        exit(0);
    }
    while(1) {
        if(pos[ans].size() == 0) {
            cout<<ans+1;
            exit(0);
        }
        int last = -1;
        for(auto x: pos[ans]) {
            st.update(1, 0, n-1, last+1, x, x);
            last = x;
        }
        st.update(1, 0, n-1, last+1, n-1, n);
//        cout<<ans<<endl;
//        forn(i,0,n) cout << st.get(1,0,n-1,i)<<' '; cout<<endl;
        ans += 1;
        last = 0;
        int can = 0;
        pos[ans].pb(n);
        for (auto x : pos[ans]) {
//            if (x == n) break;
            if(last >= n) break;
            if(st.get(1, 0, n-1, last) < x) {
                can = 1;
                break;
            }
            else last = x + 1;
        }
        pos[ans].pop_back();
        if(can == 0){
            cout<<ans;
            exit(0);
        }
    }
}