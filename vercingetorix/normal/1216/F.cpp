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
const ll INF = 1e18;
class stree {
public:
    vll t;
    int s;
    void build (int n, int v, int tl, int tr) {
        t = vll(4*n, INF);
    }
    
    void update (int v, int tl, int tr, int l, int r, ll val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = min(t[v], val);
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    ll get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return min(t[v], get (v*2, tl, tm, pos));
        else
            return min(t[v], get (v*2+1, tm+1, tr, pos));
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d\n", &n, &k);
    char c[200500];
    scanf("%s", c);
    stree st;
    st.build(n+1, 1, 0, n);
    st.update(1, 0, n, 0, 0, 0);
    forn(i,0,n) {
        st.update(1, 0, n, i+1, i+1, st.get(1, 0, n, i) + i+1);
        if(c[i] == '1') {
            int l = max(0,i-k);
            int r = min(n,i+k+1);
            st.update(1, 0, n, 0, r, st.get(1, 0, n, l)+i+1);
        }
    }
    cout<<st.get(1, 0, n, n);
    
    
}