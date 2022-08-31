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

class node {
public:
    int ch[2];
    vi ind;
    vi temp;
    int bit;
    node() {
        ch[0] = -1;
        ch[1] = -1;
    }
    
    int get(int l, int r) {
        int ret = lower_bound(all(ind), r+1) - lower_bound(all(ind), l);
        for(auto x : temp) if(x >= l && x <= r) ret ++;
        return ret;
    }
    
    int get1(int l, int r) {
        auto it = lower_bound(all(ind), l);
        if(it != lower_bound(all(ind), r+1)) return *it;
        for(auto x : temp) if(x >= l && x <= r) return x;
        return -1;
    }
};

int pt = 0;
#ifdef LOCAL
const int A = 500;
#else
const int A = 3000500;
#endif
node st[A];
void clean() {
    forn(i,0,pt) {
        st[i].ch[0] = -1;
        st[i].ch[1] = -1;
        st[i].ind.clear();
    }
    pt = 1;
}

void add(int cur, int x, int ind, int bit) {
    st[cur].ind.pb(ind);
    for(int b = bit; b >= 0; b--) {
        int to = 0;
        if(x & (1<<b)) to = 1;
        if(st[cur].ch[to] == -1) {
            st[cur].ch[to] = pt++;
        }
        cur = st[cur].ch[to];
        st[cur].ind.pb(ind);
    }
}

void addtemp(int cur, int x, int ind, int bit) {
    st[cur].temp.pb(ind);
    for(int b = bit; b >= 0; b--) {
        int to = 0;
        if(x & (1<<b)) to = 1;
        if(st[cur].ch[to] == -1) {
            st[cur].ch[to] = pt++;
        }
        cur = st[cur].ch[to];
        st[cur].temp.pb(ind);
    }
}

void remtemp(int cur, int x, int ind, int bit) {
    st[cur].temp.pop_back();
    for(int b = bit; b >= 0; b--) {
        int to = 0;
        if(x & (1<<b)) to = 1;
        int was = cur;
        cur = st[cur].ch[to];
        st[cur].temp.pop_back();
        if(st[cur].temp.empty() && st[cur].ind.empty()) {
            pt--;
            st[was].ch[to] = -1;
        }
    }
}
int ans;
vi a;
void solve(int cur, int bit, int l, int r) {
    if(bit == -1) return;
    int glr = -1;
    if(st[cur].ch[0] != -1) glr =  st[st[cur].ch[0]].get(l, r);
    if(glr > 1) solve(st[cur].ch[0], bit-1, l, r);
    else {
        ans |= 1<<bit;
        int v = -1;
        if(glr == 1) {
//            v = st[cur].get1(l, r);
            v = st[st[cur].ch[0]].get1(l, r);
            addtemp(cur, a[v]^(1<<bit), v, bit);
        }
        solve(st[cur].ch[1],bit-1,l,r);
        if(v!=-1) remtemp(cur, a[v]^(1<<bit), v, bit);
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        pt = 1;
        int n;
        scanf("%d", &n);
        a.resize(n);
        forn(i,0,n) scanf("%d", &a[i]);
        st[0].bit = 29;
        forn(i,0,n) add(0, a[i], i, 29);
        int q;
        scanf("%d", &q);
        while(q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--; r--;
            ans = 0;
            solve(0,29,l,r);
            printf("%d\n", ans);
        }
        clean();
    }
    
    
}