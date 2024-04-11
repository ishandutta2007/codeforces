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
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
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
stree st[3];
int cnt[3];
set<int> pos[3];
int n,q;

void go() {
    forn(v,0,3) {
        if(cnt[v] == n) {
            printf("%d\n", n);
            return;
        }
    }
    forn(v,0,3) {
        if(cnt[v] == 0) {
            printf("%d\n", cnt[(v+2)%3]);
            return;
        }
    }
    int ans = n;
    forn(v,0,3) {
        int g = (v+2)%3;
        int b = (v+1)%3;
        int l = *pos[g].begin();
        auto it = pos[g].end();
        it--;
        int r = *it;
        it = pos[b].end();
        it--;
        int r2 = *it;
        if(r2>r) ans -= st[v].get(1, 0, n-1, r, r2);
        int l2 = *pos[b].begin();
        if(l2<l) ans -= st[v].get(1, 0, n-1, l2, l);
    }
    printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d\n", &n, &q);
    forn(i,0,3) st[i].build(vi(n,0), 1, 0, n-1);
    char c[300500];
    scanf("%s", c);
    vi a;
    forn(i,0,n) {
        int v = 0;
        if(c[i] == 'P') v = 1;
        if(c[i] == 'S') v = 2;
        a.pb(v);
        st[v].update(1, 0, n-1, i, 1);
        pos[v].insert(i);
        cnt[v]++;
    }
    go();
    while(q--) {
        int i;
        char cc;
        scanf("%d %c", &i, &cc);
        int v = 0;
        if(cc == 'P') v = 1;
        if(cc == 'S') v = 2;
        i--;
        int was = a[i];
        pos[was].erase(i);
        cnt[was]--;
        st[was].update(1, 0, n-1, i, 0);
        pos[v].insert(i);
        cnt[v]++;
        st[v].update(1, 0, n-1, i, 1);
        a[i] = v;
        go();
    }
    
    
    
}