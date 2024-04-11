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
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    void set (int v, int tl, int tr, int pos, int val) {
        if (pos == tl && tr == pos) {
            t[v] = val;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos, val);
            else set(v*2+1, tm+1, tr, pos,val);
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
stree st;
vi bad;
vi a,pos;
int n;
void upd(int i) {
    if(i == -1 || i == n-1) return;
    int was = bad[i];
    int cur = 0;
    if(pos[i] > pos[i+1]) cur = 1;
    if(was != cur) {
        bad[i] = cur;
        st.set(1, 0, n-2, i, cur);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    a.resize(n);
    pos.resize(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
        a[i]--;
        pos[a[i]] = i;
    }
    bad = vi(n-1,0);
    forn(i,0,n-1) if(pos[i] > pos[i+1]) bad[i] = 1;
    st.build(bad, 1, 0, n-2);
    int q;
    scanf("%d", &q);
    forn(i,0,q) {
        int t,l,r;
        scanf("%d %d %d", &t, &l, &r);
        l--;
        r--;
        if(t == 1) printf("%d\n", st.get(1, 0, n-2, l, r-1) + 1);
        else {
            swap(a[l], a[r]);
            pos[a[l]] = l;
            pos[a[r]] = r;
            upd(a[l] - 1);
            upd(a[l]);
            upd(a[r] - 1);
            upd(a[r]);
        }
    }
    
}