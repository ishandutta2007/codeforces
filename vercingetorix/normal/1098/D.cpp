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
const ll INF = 1e18;
int igo[500500];
class stree {
public:
    vll t;
    vll pp;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vll(n*4,0);
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
    
    void update (int v, int tl, int tr, int l, int r, ll val) {
        if (l == tl && tr == r) {
            pp[v] += val;
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
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int count_pos(int v, int tl, int tr) {
        push(v, tl, tr);
        if(t[v] <= 0) return 0;
        else if(tl == tr && igo[tl] == 0) return 1;
        int tm = (tl + tr) / 2;
        return count_pos(v*2, tl, tm) + count_pos(v*2+1, tm+1, tr);
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return -INF;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  max(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    scanf("%d\n", &q);
    vi ev;
    set<int> xx;
    forn(i,0,q) {
        int x;
        char c;
        scanf("%c %d\n", &c, &x);
        if(c=='+') ev.pb(x);
        else ev.pb(-x);
        xx.insert(x);
    }
    map<int, int> to;
    int m = 0;
    for(auto x : xx) to[x] = m++;
    vi cnt(m,0);
    int n = 0;
    stree st;
    st.build(m, 1, 0, m-1);
    forn(i,0,q) {
        int x = abs(ev[i]);
        int ind = to[x];
        if(ev[i] > 0) {
            n++;
            cnt[ind]++;
            if(cnt[ind] == 1) st.update(1, 0, m-1, ind, ind, x);
//            if(cnt[ind] > 1) igo[ind] = 1;
//            else {
//                st.update(1, 0, m-1, ind, ind, x);
//            }
            st.update(1, 0, m-1, ind+1, m-1, -2*x);
        }
        else {
            n--;
            cnt[ind]--;
//            if(cnt[ind] <= 1) igo[ind] = 0;
            if(cnt[ind] == 0) st.update(1, 0, m-1, ind, ind, -x);
            st.update(1, 0, m-1, ind+1, m-1, 2*x);
        }
        int k = st.count_pos(1, 0, m-1);
        printf("%d\n", n-k);
    }
    
    
}