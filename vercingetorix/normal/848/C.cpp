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

#define pb push_back
#define mp make_pair

const int A = 320;

set<int> num[100010];
ll t[400000];
class stree {
public:
    void build (vll & a, int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    void set (int v, int tl, int tr, int pos) {
        if (pos == tl && tr == pos) {
            t[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos);
            else set(v*2+1, tm+1, tr, pos);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return get (v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
    }
};

ll getval(int l, int r, int val) {
    if(num[val].size()<=1) return 0;
    auto itl = num[val].lower_bound(l);
    auto itr = num[val].upper_bound(r);
    if(itl == itr) return 0;
    itr--;
    return *itr-*itl;
}

ll rem(int l, int r, int val, int pos) {
    if(num[val].size()<=1) return 0;
    auto itl = num[val].lower_bound(l);
    auto itr = num[val].upper_bound(r);
    if(itl == itr) return 0;
    itr--;
    if(itl == itr) return 0;
    if(*itr == pos) {
        itr--;
        return pos-*itr;
    }
    else if(*itl == pos) {
        itl++;
        return *itl-pos;
    }
    return 0;
}

ll add(int l, int r, int val, int pos) {
    auto itl = num[val].lower_bound(l);
    auto itr = num[val].upper_bound(r);
    if(itl == itr) return 0;
    itr--;
    int vl = *itl;
    int vr = *itr;
    int was = vr-vl;
    if(pos>=l) vl=min(vl,pos);
    if(pos<=r) vr=max(vr,pos);
    return vr-vl-was;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) a[i]--;
    vi tp(m);
    vi l(m), r(m);
    forn(i,0,m) scanf("%d %d %d", &tp[i], &l[i], &r[i]);
    forn(i,0,m) l[i]--;
    forn(i,0,m) r[i]--;
    int s = 0;
    forn(i,0,n) {
        num[a[i]].insert(i);
    }
    while(s < m) {
        deque<pi> q;
        forn(i,s,min(s+A, m)) {
            if(tp[i] == 2) q.pb(mp(l[i], r[i]));
        }
        deque<ll> ans(q.size(), 0);
        int k = q.size();
        vector<pair<pi, int>> req;
        forn(i,0,k) req.pb(mp(q[i], i));
        sort(all(req));
        vi prev(n,-1);
        vi nx(n,-1);
        vll def(n,0);
        forn(i,0,n) {
            int val = a[i];
            if (prev[val] != -1) {
                nx[prev[val]] = i;
                def[i] = i-prev[val];
            }
            prev[val] = i;
        }
        int cur = 0;
        stree st;
        st.build(def, 1, 0, n-1);
        forn(i,0,k) {
            while(cur < req[i].first.first) {
                if(nx[cur] != -1) st.set(1, 0, n-1, nx[cur]);
                cur++;
            }
            ans[req[i].second] = st.get(1, 0, n-1, req[i].first.first, req[i].first.second);
        }
        forn(i,s,min(s+A, m)) {
            if(tp[i] == 2) {
                printf("%lld\n", ans.front());
                ans.pop_front();
                q.pop_front();
                k--;
            }
            else {
                int pos = l[i];
                int nval = r[i];
                int val = a[pos];
                a[pos] = nval;
                if(val!=nval) {
                    forn(j,0,k) {
                        ans[j] -= rem(q[j].first, q[j].second, val, pos);
                        ans[j] += add(q[j].first, q[j].second, nval, pos);
                    }
                }
                num[val].erase(pos);
                num[nval].insert(pos);
            }
        }
        
        s += A;
    }
    
}