#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <array>
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

const long long mod = 95542721;
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
int cube(int x) {
    return ll(x)*x%mod*x%mod;
}
class stree {
public:
    vector<array<int, 48>> t;
    vi pp;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            int n = a.size();
            t.resize(n * 4);
            pp = vi(n*4,0);
        }
        if (tl == tr) {
            t[v][0] = a[tl]%mod;
            forn(i,1,48) {
                t[v][i] = cube(t[v][i-1]);
            }
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            forn(i,0,48) {
                t[v][i] = t[v*2][i] + t[v*2+1][i];
                if(t[v][i] >= mod) t[v][i] -= mod;
            }
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        rotate(t[v].begin(), t[v].begin() + pp[v], t[v].end());
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
            if(pp[2*v] >= 48) pp[2*v]-=48;
            if(pp[2*v+1] >= 48) pp[2*v+1]-=48;
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r) {
        if (l == tl && tr == r) {
            pp[v] ++;
            if(pp[v] >= 48) pp[v]-=48;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm));
            update (v*2+1, tm+1, tr, max(l,tm+1), r);
            forn(i,0,48) {
                t[v][i] = t[v*2][i] + t[v*2+1][i];
                if(t[v][i] >= mod) t[v][i] -= mod;
            }
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v][0];
        int tm = (tl + tr) / 2;
        int ret =  get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
        if(ret >= mod) ret -= mod;
        forn(i,0,48) {
            t[v][i] = t[v*2][i] + t[v*2+1][i];
            if(t[v][i] >= mod) t[v][i] -= mod;
        }
        return ret;
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    stree st;
    st.build(a, 1, 0, n-1);
    int m;
    read(m);
    while(m--) {
        int tp,l,r;
        scanf("%d %d %d", &tp, &l, &r);
        l--; r--;
        if(tp == 1) {
            printf("%d\n", (int)(st.get(1, 0, n-1, l, r)%mod));
        }
        else {
            st.update(1, 0, n-1, l, r);
        }
    }
    
    
}