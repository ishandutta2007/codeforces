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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
    
    int getr(int v, int tl, int tr, int k) {
        if(t[v] < k) return tr+1;
        if(tl==tr) return tl;
        int tm = (tl+tr)/2;
        if(t[v*2] >= k) return getr(v*2, tl, tm, k);
        else return getr(v*2+1,tm+1,tr,k-t[v*2]);
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[100500];
    forn(ifa,0,ta) {
        int n;
        scanf("%d\n", &n);
        scanf("%s", c);
        string s(c);
        scanf("%s", c);
        string t(c);
        string s2 = s;
        srt(s2);
        if(s2 >= t) {
            printf("-1\n");
            continue;
        }
        stree st;
        st.build(vi(n,0), 1, 0, n-1);
        ll best = ll(n)*(n-1)/2;
        ll cur = 0;
        vvi pos(26);
        vi pt(26,0);
        forn(i,0,n) pos[s[i]-'a'].pb(i);
        vi taken(n,0);
        int poss = 0;
        forn(post,0,n) {
            while(taken[poss]) poss++;
            if(cur >= best) break;
            if(t[post] > s[poss]) {
                best = min(best, cur);
                break;
            }
            int ct = t[post]-'a';
            int was = n;
            forn(l,0,ct) {
                if(pt[l] < pos[l].size()) {
                    was = min(was, pos[l][pt[l]]);
                }
            }
            if(was != n) best = min(best, cur + was + st.get(1, 0, n-1, was, n-1) - post);
            if(pt[ct] == pos[ct].size()) break;
            was = pos[ct][pt[ct]];
            cur += was + st.get(1, 0, n-1, was, n-1) - post;
            taken[was] = 1;
            st.update(1, 0, n-1, was, 1);
            pt[ct]++;
        }
        
        printf("%lld\n", best);
    }
    
    
}