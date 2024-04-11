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
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef long double ld;

const ld EPS = 1e-20;

const long long mod = 1000000007;

const ll INF = mod*mod+mod;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

struct Line {
    ll a, b;
    
    ld inter(const Line& l) const {
//        assert(a != l.a);
        return (ld) (l.b - b) / (a - l.a);
    }
    
    Line() {}
    
    Line(ll a, ll b) : a(a), b(b) {}
    
    ll get(int x) {
        return a * 1ll * x + b;
    }
};

struct Hull {
    vector<Line> st;
    
    void push(const Line& l) {
        while (sz(st) >= 2) {
            const Line& l1 = st[sz(st) - 2];
            const Line& l2 = st[sz(st) - 1];
            
            if  (l2.a == l.a) {
                if  (l.b > l2.b) {
                    st.pop_back();
                    continue;
                } else {
                    return;
                }
            }
            
            ld x1 = l1.inter(l2);
            ld x2 = l2.inter(l);
            if  (x2 < x1 + EPS) {
                st.pop_back();
            } else {
                break;
            }
        }
        st.pb(l);
    }
    
    ll get_best(ll x) {
        int L = -1;
        int R = sz(st) - 1;
        while (L < R - 1) {
            int M = (L + R) / 2;
            ld xx = st[M].inter(st[M + 1]);
            if  (xx < x) {
                L = M;
            } else {
                R = M;
            }
        }
        ll ans = -INF;
        for (int i = max(0, L - 3); i < min(sz(st), R + 4); ++i) {
            ans = max(ans, st[i].get(x));
        }
        return ans;
    }
};

const int MAXN = 301000;

vector<Hull> t(4*MAXN);
vector<vector<Line>> vt(4*MAXN);
void build (int v, int tl, int tr) {
    //    if (tl == tr)
    //        t[v] = a[tl];
    //    else {
    //t[v].insert_line(0, -mod*mod);
    vt[v].pb(Line(0, -INF));
    if(tl==tr) return;
    int tm = (tl + tr) / 2;
    build (v*2, tl, tm);
    build (v*2+1, tm+1, tr);
    //    }
}

void update (int v, int tl, int tr, int l, int r, pll add) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        //t[v] += add;
        //t[v].insert_line(add.first, add.second);
        vt[v].pb(Line(add.first, add.second));
    else {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), add);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
    }
}



ll get (int v, int tl, int tr, int pos, ll num) {
    if (tl == tr)
        return t[v].get_best(num);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return max(t[v].get_best(num), get (v*2, tl, tm, pos, num));
    else
        return max(t[v].get_best(num), get (v*2+1, tm+1, tr, pos, num));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    build(1,0,n-1);
    vi type(n);
    vpi q(n);
    vi num(n);
    vi u(n,0);
    forn(i,0,n) {
        scanf("%d", &type[i]);
        if(type[i] == 1) scanf("%d %d", &q[i].first, &q[i].second);
        if(type[i] == 2) scanf("%d", &num[i]);
        if(type[i] == 3) scanf("%d", &num[i]);
    }
    for(int i = n-1; i>=0; i--) {
        if(u[i]) continue;
        if(type[i]==3) continue;
        if(type[i]==2) {
            int l = num[i] - 1;
            update(1,0,n-1,l,i,mp((ll)q[l].first, (ll)q[l].second));
            u[l]=1;
        }
        if(type[i]==1) {
            update(1,0,n-1,i,n-1,mp((ll)q[i].first, (ll)q[i].second));
        }
    }
    forn(i,0,4*MAXN) {
        if(vt[i].size() > 0) {
            sort(all(vt[i]), [](Line a, Line b) {
                return a.a < b.a || (a.a == b.a && a.b < b.b);
            });
            for(auto l : vt[i]) t[i].push(l);
        }
        
    }
    forn(i,0,n) {
        if(type[i] == 3) {
            ll ans = get(1,0,n-1,i,(ll)num[i]);
            if(ans==-INF) printf("EMPTY SET\n");
            else printf("%lld\n", ans);
        }
    }
    
}