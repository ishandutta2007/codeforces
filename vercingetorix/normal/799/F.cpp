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
const int INF = 1e9;
struct val {
    val () {};
    val(int mn, int cnt, ll sum) : mn(mn), cnt(cnt), sum(sum) {};
    int mn=INF;
    int cnt=0;
    ll sum=0;
    void print() {
        cout<<mn<<' '<<cnt<<' '<<sum<<endl;
    }
};

val combine(val x, val y) {
    if(x.mn < y.mn) return x;
    else if(y.mn < x.mn) return y;
    else return val(x.mn, x.cnt+y.cnt, x.sum+y.sum);
}

class stree {
public:
    int s;
    vector<val> t;
    vector<int> lazy;
    void build (vi & a, int v, int tl, int tr, int ignore2) {
        if(v==1) {
            s = a.size();
            lazy.resize(4*s);
            t.resize(4*s);
        }
        if (tl == tr) {
            t[v] = val(a[tl], 1, tl);
            if(tl%2 == ignore2) t[v].mn = INF;
            lazy[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm, ignore2);
            build (a, v*2+1, tm+1, tr, ignore2);
            lazy[v] = 0;
            t[v] = combine(t[v*2], t[v*2 + 1]);
        }
    }
    
    void push(int v) {
        if (lazy[v] == 0) return;
        t[v].mn += lazy[v];
        if(v<2*s) {
            lazy[v*2] += lazy[v];
            lazy[v*2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int add) {
        push(v);
        if (l > r)
            return;
        if (l == tl && tr == r) {
            lazy[v] += add;
            push(v);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            t[v] = combine(t[v*2], t[v*2 + 1]);
        }
    }
    
    val get (int v, int tl, int tr, int l, int r) {
        push(v);
        if (l > r)
            return val(INF,0,0);
        if (l == tl && tr == r) {
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            val ret = combine(get(v*2, tl, tm, l, min(r,tm)),
                              get(v*2+1, tm+1, tr, max(l,tm+1), r));
            t[v] = combine(t[v*2], t[v*2 + 1]);
            return ret;
        }
    }
    void print() {
        forn(i,0,s) cout<<get(1,0,s-1,i,i).mn<<' ';
        cout<<endl;
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
    vi l(n), r(n);
    vvi e(m);
    set<int> ns;
    vector<set<int>> oe(2);
    vector<stree> ban(2);
    vi def(m,0);
    ban[0].build(def, 1, 0, m-1, 1);
    ban[1].build(def, 1, 0, m-1, 0);
    forn(i,0,n) {
        scanf("%d %d", &l[i], &r[i]);
        l[i]--;
        r[i]--;
        e[l[i]].pb(r[i]);
        ns.insert(l[i]);
        if((r[i]-l[i])%2 == 0) {
            // odd len
            ban[1-l[i]%2].update(1, 0, m-1, l[i], r[i], 1);
        }
        else {
            ban[1-l[i]%2].update(1, 0, m-1, l[i], r[i], 1);
            forn(j,0,2) ban[j].update(1, 0, m-1, r[i]+1, m-1, 1);
        }
    }
    int pt = 0;
    ll ans = 0;
    ns.insert(m);
    forn(s,0,m) {
        while(!ns.empty() && *ns.begin() < s) ns.erase(ns.begin());
//        cout<<"CURS "<<s<<endl;
//        cout<<"B0 "; ban[0].print();
//        cout<<"B1 "; ban[1].print();
        int to = m-1;
        if(!oe[1-s%2].empty()) to = min(to, *oe[1-s%2].begin());
        int f = s;
        if(oe[0].empty() && oe[1].empty()) f = *ns.begin();
        val ol = ban[s%2].get(1, 0, m-1, f, to);
//        cout << "from " << f << " to "<<to<<' ';
//        cout<<"OL "; ol.print();
        if (ol.mn == 0) ans += (ol.sum - (ll)ol.cnt * ll(s-1));
//        cout<<ans<<endl;
        forn(j,0,2) if(!oe[j].empty()) f = max(f, 1+*(--oe[j].end()));
//        cout<<"request "<<1-s%2<<' '<<ef<<' '<<to<<endl;
        val el = ban[1-s%2].get(1, 0, m-1, f, to);
//        cout << "from " << f << " to "<<to<<' ';
//        cout<<"EL "; el.print();
        if (el.mn == 0) ans += (el.sum - (ll)el.cnt * ll(s-1));
//        cout<<ans<<endl;
        for(auto x : e[s]) {
            oe[x%2].insert(x);
            if((x-s)%2 == 0) {
                ban[1-s%2].update(1, 0, m-1, s, x, -1);
            }
            else {
                ban[1-s%2].update(1, 0, m-1, s, x, -1);
                forn(j,0,2) ban[j].update(1, 0, m-1, x+1, m-1, -1);
            }
        }
        forn(j,0,2) while(!oe[j].empty() && *oe[j].begin() <= s) oe[j].erase(oe[j].begin());
    }
    cout<<ans;
}