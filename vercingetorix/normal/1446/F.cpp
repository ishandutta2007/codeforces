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
typedef std::vector<long double> vd;
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
int n;
ll k;
vi x, y;
vd px, py;
ld ppi = acos(ld(-1));

ld ang(ld a, ld b) {
    ld len = sqrt(a*a+b*b);
    ld phi = acos(a/len);
    if(b<0) phi = 2*ppi - phi;
    return phi;
}

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
ll tot;

ll out(ld d) {
    vector<pair<ld, int>> ev;
    forn(i,0,n) {
        ld len = sqrt(px[i]*px[i] + py[i]*py[i]);
        ld cs = len/d;
        if(cs > 1) {
            ev.pb(mp(0, -i-1));
            ev.pb(mp(0, i+1));
            continue;
        }
        ld phi = acos(cs);
        ld t = d*sin(phi);
        ld x1 = px[i] + t/len * py[i];
        ld y1 = py[i] - t/len * px[i];
        ld x2 = px[i] - t/len * py[i];
        ld y2 = py[i] + t/len * px[i];
        ld ain = ang(x1, y1);
        ld bin = ang(x2, y2);
        ev.pb(mp(ain, -i-1));
        ev.pb(mp(bin, +i+1));
    }
    sort(all(ev));
    vi op(n,0);
    vi cl(n,0);
    forn(i,0,2*n) {
        if(ev[i].second < 0) op[-ev[i].second-1] = i;
        else cl[ev[i].second - 1] = i;
    }
    stree st;
    st.build(2*n, 1, 0, 2*n-1);
    forn(i,0,n) if(op[i] > cl[i]) {
        st.update(1, 0, 2*n-1, op[i], 1);
    }
    ll ans=0;
    forn(i,0,2*n) {
        if(ev[i].second < 0) {
            st.update(1, 0, 2*n-1, i, 1);
        }
        else {
            int v = ev[i].second - 1;
            st.update(1, 0, 2*n-1, op[v], 0);
            if(op[v] < cl[v]) {
                ans += st.get(1, 0, 2*n-1, op[v], cl[v]);
            }
            else {
                ans += st.get(1, 0, 2*n-1, op[v], 2*n-1);
                ans += st.get(1, 0, 2*n-1, 0, cl[v]);
            }
        }
    }
    return tot-ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %lld", &n, &k);
    x.resize(n);
    y.resize(n);
    forn(i,0, n) scanf("%d %d", &x[i], &y[i]);
    forn(i,0,n) {
        if(x[i] == 0 && y[i] == 0) {
            if(k <= n - 1) {
                cout<<0;
                return 0;
            }
            else {
                k -= (n-1);
                swap(x[i], x[n-1]);
                swap(y[i], y[n-1]);
                n--;
                x.pop_back();
                y.pop_back();
            }
        }
    }
    tot = ll(n)*(n-1) / 2;
    forn(i,0,n) {
        px.pb(ld(x[i])/(x[i]*x[i]+y[i]*y[i]));
        py.pb(ld(y[i])/(x[i]*x[i]+y[i]*y[i]));
    }
    ld l = 0;
    ld r = 100000;
    forn(adad,0,50) {
        ld m = (l+r)/2;
        ll num = out(ld(1)/m);
        if(num >= k) r = m;
        else l = m;
    }
    printf("%.10lf", double(l));
    
    
}