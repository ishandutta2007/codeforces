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
            s = a.size();
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += val;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(l,n);
    srtrev(l);
    ll sum = 1;
    forn(i,0,n) {
        sum += l[i] - 2;
    }
    if(sum < k) {
        printf("-1\n");
        exit(0);
    }
    int pt = 0;
    const int A = 1000000;
    stree st;
    st.build(vi(A,0), 1, 0, A-1);
    st.update(1, 0, A-1, 0, 0, 1);
    int was = 0;
    while(pt<n) {
        while(st.get(1, 0, A-1, was) == 0) was++;
        int cur = st.get(1, 0, A-1, was);
        if(cur >= k) {
            printf("%d\n", was);
            exit(0);
        }
        if(cur + st.get(1, 0, A-1, was+1) >= k) {
            printf("%d\n", was+1);
            exit(0);
        }
        st.update(1, 0, A-1, was, was, -1);
        int add = l[pt++] - 1;
        st.update(1, 0, A-1, was+2, was+1+add/2, 1);
        st.update(1, 0, A-1, was+2, was+1+add-add/2, 1);
    }
    sum = 0;
    while(1) {
        sum += st.get(1, 0, A-1, was);
        if(sum >= k) {
            printf("%d\n", was);
            exit(0);
        }
        was++;
    }
    
}