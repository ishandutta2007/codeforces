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
const int N = 200500;
const int A = 200500;
//int mindiv[N+1];
vi mindiv(N+1, 0);


int divs[2000];
int getdiv(int n) {
    if(n == 1) return 1;
    int p = mindiv[n];
    int deg = 1;
    n/=p;
    while(n%p == 0) {
        deg++;
        n/=p;
    }
    int k = getdiv(n);
    int dp = p;
    int cur = k;
    forn(it,0,deg) {
        forn(i,0,k) divs[cur++] = divs[i]*dp;
        dp*=p;
    }
    return cur;
}

vi fdiv[A];
ll nd[A];
vi fdiv2[A];

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    
    T get(int l, int r) {
        T ret = get(r);
        if (l>0) ret -= get(l-1);
        return ret;
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fenwick<ll> fen(A);
    vector<ll> pr;
    vi isp(N+1, 0);
    divs[0] = 1;
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    forn(m,1,A) {
        int k = getdiv(m);
        forn(i,0,k) fdiv[m].pb(divs[i]);
        srt(fdiv[m]);
        fdiv2[m] = fdiv[m];
        forn(i,0,k) if(m%(divs[i]*2) != 0) fdiv2[m].pb(divs[i]*2);
        srt(fdiv2[m]);
        
        while(!fdiv[m].empty() && fdiv[m].back() >= m) fdiv[m].pop_back();
        while(!fdiv2[m].empty() && fdiv2[m].back() >= m) fdiv2[m].pop_back();
        ll s = fdiv[m].size();
        nd[m] = s;
        ll cur = s*(s-1)/2;
        ll bad = 0;
        for(auto x : fdiv2[m]) if(2*x >= m+1) bad += fdiv2[m].end() - lower_bound(all(fdiv2[m]), m-x+1) - 1;
        fen.modify(m, cur + bad);
//        if(m<100) cout<<m<<' '<<0*cur+bad/2<<'\n';
    }
    int ta;
    read(ta);
    vvpi q(A);
    forn(ifa,0,ta) {
        int l,r;
        scanf("%d %d", &l, &r);
        q[l].pb(mp(r,ifa));
    }
    vll ans(ta, -1);
    forn(l,1,A) {
        for(auto x : q[l]) {
            ll num = x.first - l + 1;
            ans[x.second] = num*(num-1)*(num-2)/6-fen.get(l, x.first);
        }
        for(int m = 2*l; m<A; m+=l) {
            nd[m]--;
            ll dec = nd[m];
            fen.modify(m, -dec);
        }
        if(l%3==0) {
            if(l*2<A) fen.modify(l*2, -1);
            if(l%2 == 0) if(l*5/2 < A) fen.modify(l*5/2, -1);
        }
    }
    forn(i,0,ta) printf("%lld\n", ans[i]);
}