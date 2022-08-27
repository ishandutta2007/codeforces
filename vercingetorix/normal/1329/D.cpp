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
set<int> let;
stree st;
int n;
pi get(int l, int r) {
    auto it = let.lower_bound(l);
    vi todel;
    while(it!=let.end() && *it<=r) {
        todel.pb(*it);
        it++;
    }
    int l1 = l - st.get(1, 0, n-1, 0, l-1);
    int r1 = l1 +r - l - st.get(1,0,n-1,l,r);
    for(auto x : todel) {
        st.update(1, 0, n-1, x, 1);
        let.erase(x);
    }
    return mp(l1,r1);
}
int k;
vpi bad;
vpi ans;
vi tol, tor;
vi cbad;
set<pi> has;
map<pi, set<pi>> w;
int sum;
vi bi;
void rem(int i, int j) {
    if(i<0 || j>=k) return;
    int mn = min(bi[i], bi[j]);
    int mx = max(bi[i], bi[j]);
    pi u =mp(mn,mx);
    w[u].erase(mp(i, j));
    if(mn!=mx) if(w[u].empty()) has.erase(u);
    
}

void app(int i, int j) {
    if(i<0 || j>=k) return;
    int mn = min(bi[i], bi[j]);
    int mx = max(bi[i], bi[j]);
    pi u =mp(mn,mx);
    if(mn!=mx) if(w[u].empty()) has.insert(u);
    w[u].insert(mp(i, j));
}

void cap(int i) {
    int lx = tol[i];
    int rx = tor[i];
    if(lx >= 0) tor[lx] = rx;
    if(rx < k) tol[rx]=lx;
    rem(lx,i);
    rem(i,rx);
    app(lx,rx);
}

void go1(int i) {
    ans.pb(get(bad[i].second, bad[i].second));
    bad[i].second--;
    cbad[bi[i]]--;
    sum--;
    if(bad[i].second == bad[i].first) {
        cap(i);
    }
}

void go(int i, int j) {
    ans.pb(get(bad[i].second, bad[j].first));
    bad[i].second--;
    cbad[bi[i]]--;
    cbad[bi[j]]--;
    sum-=2;
    if(bad[i].second == bad[i].first) {
        cap(i);
    }
    bad[j].first++;
    if(bad[j].second == bad[j].first) {
        cap(j);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[200100];
    int t;
    read(t);
    while(t--) {
        ans.clear();
        scanf("%s", c);
        string s(c);
        n = s.size();
        st.build(n, 1, 0, n-1);
        let.clear();
        forn(i,0,n) let.insert(i);
        int pt =0;
        bad.clear();
        cbad = vi (26,0);
        bi.clear();
        
        while(pt < n) {
            int ptr = pt;
            while(ptr <n && s[ptr] == s[pt]) ptr++;
            if(ptr>pt+1) {
                bad.pb(mp(pt, ptr-1));
                bi.pb(int(s[pt]-'a'));
            }
            int xc = s[pt] - 'a';
            cbad[xc] += ptr-pt-1;
            pt = ptr;
        }
        has.clear();
        k = bad.size();
        tor = vi (k,0);
        tol = vi (k,0);
        sum = 0;
        forn(i,0,26) sum += cbad[i];
        forn(i,0,k) tor[i] = i+1;
        forn(i,0,k) tol[i] = i-1;
        forn(i,0,k) app(i,i+1);
        
        if(sum % 2 == 1) {
            int pt = 0;
            forn(i,0,26) if(cbad[i] > cbad[pt]) pt = i;
            forn(i,0,k) if(bi[i] == pt) {
                go1(i);
//                cbad[pt]--;
//                sum--;
                break;
            }
        }
        int mark = -1;
        while(1) {
            int pt = 0;
            forn(i,0,26) if(2*cbad[i]>=sum) {
                mark = i;
                break;
            }
            if(mark>=0) break;
            auto u = *has.begin();
            go(w[u].begin()->first, w[u].begin()->second);
        }
        while(cbad[mark] != sum) {
            forn(i,0,26) {
                if(i==mark) continue;
                pi u = mp(min(i,mark),max(i,mark));
                while(!w[u].empty()) {
                    go(w[u].begin()->first, w[u].begin()->second);
                }
            }
        }
        forn(i,0,k) while(bad[i].first!=bad[i].second) go1(i);
        ans.pb(get(0,n-1));
        printf("%d\n", ans.size());
        for(auto x : ans) {
            printf("%d %d\n", x.first+1, x.second+1);
        }
    }
    
    
    
}