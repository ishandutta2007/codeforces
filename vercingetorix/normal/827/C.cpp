#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
struct v4 {
    v4(int ax, int b, int c, int d) {a[0]=ax; a[1]=b; a[2] = c; a[3] = d;};
    v4() {a[0]=0; a[1]=0;a[2]=0;a[3]=0;};
    int a[4];
};
class stree {
public:
//    vvi t;
    vector<v4> t;
    int s;
    v4 combine(v4 a, v4 b) {
        return v4(a.a[0]+b.a[0], a.a[1]+b.a[1], a.a[2]+b.a[2], a.a[3]+b.a[3]);
    }
    
    vi combine(vi a, vi b) {
        vi res(4);
        forn(i,0,4) res[i] = a[i] + b[i];
        return res;
    }
    
    void build (vector<int> & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr) {
            t[v].a[a[tl]] = 1;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    void set (int v, int tl, int tr, int pos, int val) {
        if (pos == tl && tr == pos) {
            t[v] = v4();
            t[v].a[val] = 1;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos, val);
            else set(v*2+1, tm+1, tr, pos, val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    v4 get (int v, int tl, int tr, int l, int r) {
        if(l>r) return v4();
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return combine(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
};

stree d[11][10];
int s[11][10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string ss;
    getline(cin, ss);
    int n = ss.size();
    map<char, int> ctoi;
    ctoi['A']=0;
    ctoi['T']=1;
    ctoi['G']=2;
    ctoi['C']=3;
    vi a;
    for(auto x : ss) a.pb(ctoi[x]);
    forn(l,1,11) {
        forn(r,0,l) {
            vi b;
            for(int i = r; i < n; i += l) b.pb(a[i]);
            s[l][r] = b.size();
            if(s[l][r] > 0) {
                d[l][r].build(b, 1, 0, s[l][r]-1);
            }
        }
    }

    int q;
    scanf("%d", &q);
    forn(it,0,q) {
        int tp;
        scanf("%d", &tp);
        if(tp==1) {
            int x;
            char c;
            scanf("%d %c", &x, &c);
            x--;
            int to = ctoi[c];
            forn(l,1,11) {
                int r = x%l;
                int st = x/l;
                d[l][r].set(1, 0, s[l][r]-1, st, to);
            }
        }
        else if(tp == 2) {
            int fr, to;
            char ec[20];
            scanf("%d %d %s", &fr, &to, ec);
            fr--; to--;
            string e(ec);
            if(e.size() > to-fr+1) e.resize(to-fr+1);
            int k = e.size();
            int ans = 0;
            forn(r,0,k) {
                int nd = ctoi[e[r]];
                int x = fr + r;
                int st = x/k;
                int en = st + (to-x)/k;
                v4 test = d[k][x%k].get(1, 0, s[k][x%k]-1, st, en);
                ans += test.a[nd];
            }
            printf("%d\n", ans);
        }
    }
}