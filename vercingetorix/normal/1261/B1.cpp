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
    
    int getr(int v, int tl, int tr, int left) {
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if(t[v*2] < left) return getr(v*2+1, tm+1, tr, left - t[v*2]);
        else return getr(v*2, tl, tm, left);
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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d", &n);
    readv(a,n);
    map<int, vi> cnt;
    forn(i,0,n) cnt[a[i]].pb(i);
    vi q;
    for(auto x : cnt) q.pb(x.first);
    srtrev(q);
    int ptq = 0;
    int pt = cnt[q[ptq]].size() - 1;
    map<int, vpi> qq;
    scanf("%d", &m);
    forn(i,0,m) {
        int k,pos;
        scanf("%d %d", &k, &pos);
        qq[k].pb(mp(pos, i));
    }
    stree st;
    vi ans(m,-1);
    st.build(n, 1, 0, n-1);
    forn(k,1,n+1) {
        int ind = cnt[q[ptq]][pt--];
        if(pt < 0) {
            ptq++;
            if(ptq < q.size()) pt = cnt[q[ptq]].size() - 1;
            srtrev(cnt[q[ptq]]);
        }
        st.update(1, 0, n-1, ind, 1);
        for(auto req : qq[k]) {
            ans[req.second] = st.getr(1, 0, n-1, req.first);
        }
    }
    forn(i,0,m) printf("%d\n", a[ans[i]]);
    
    
}