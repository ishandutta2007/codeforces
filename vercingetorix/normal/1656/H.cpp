#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
__int128 gcd (__int128 a, __int128 b) {return b==0 ? a : gcd(b, a%b);}
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
typedef std::vector<__int128> vx;
typedef __int128 lx;

lx nok(lx x, lx y) {
    if(x == 0) return y;
    if(y == 0) return x;
    return x/gcd(x,y)*y;
}

class streenok {
public:
    vx t;
    int s;
    void build (const vx & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = nok(t[v*2], t[v*2+1]);
        }
    }
    
    lx get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  nok(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, lx new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  nok(t[v*2], t[v*2+1]);
        }
    }
};

__int128 readx() {
    string s;
    cin>>s;
    if(s.size() < 19) return stoll(s);
    else {
        lx ret = stoll(s.substr(0,18));
        s = s.substr(18);
        forn(i,0,s.size()) ret*=10;
        ret += stoull(s);
        return ret;
    }
}

lx d[1000][1000];
const ll cut = 1e18;
void printx(lx x) {
    if(x < cut) printf("%lld ", (ll)x);
    else {
        printf("%lld", ll(x/cut));
        string res = to_string(ll(x%cut));
        res = string(18-res.size(), '0') + res;
        printf("%s ", res.c_str());
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        int n,m;
        cin>>n>>m;
        vx a,b;
        forn(i,0,n) a.pb(readx());
        forn(i,0,m) b.pb(readx());
        vector<streenok> da(n), db(m);
        forn(i,0,n) forn(j,0,m) d[i][j] = gcd(a[i], b[j]);
        vpi q;
        vi adone(n,0);
        vi bdone(m,0);
        forn(i,0,n) {
            vx cur;
            forn(j,0,m) cur.pb(d[i][j]);
            da[i].build(cur, 1, 0, m-1);
            if(da[i].t[1] != a[i]) {
                q.pb(mp(0,i));
                adone[i] = 1;
            }
        }
        forn(j,0,m) {
            vx cur;
            forn(i,0,n) cur.pb(d[i][j]);
            db[j].build(cur, 1, 0, n-1);
            if(db[j].t[1] != b[j]) {
                bdone[j] = 1;
                q.pb(mp(1,j));
            }
        }
        
        set<int> al, bl;
        forn(i,0,n) al.insert(i);
        forn(i,0,m) bl.insert(i);
        while(!q.empty()) {
            auto del = q.back();
            q.pop_back();
            if(del.first == 0) {
                int i = del.second;
                al.erase(i);
                for(auto j : bl) if(bdone[j] == 0) {
                    db[j].update(1, 0, n-1, i, 0);
                    if(db[j].t[1] != b[j]) {
                        bdone[j] = 1;
                        q.pb(mp(1,j));
                    }
                }
            }
            else {
                int j = del.second;
                bl.erase(j);
                for(auto i : al) if(adone[i] == 0) {
                    da[i].update(1, 0, m-1, j, 0);
                    if(da[i].t[1] != a[i]) {
                        q.pb(mp(0,i));
                        adone[i] = 1;
                    }
                }
            }
            if(al.empty() || bl.empty()) break;
        }
        if(al.empty() || bl.empty()) printf("NO\n");
        else {
            printf("YES\n");
            printf("%d %d\n", al.size(), bl.size());
            for(auto x : al) printx(a[x]);
            printf("\n");
            for(auto x : bl) printx(b[x]);
            printf("\n");
        }
    }
    
    
}