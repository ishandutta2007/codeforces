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
bool operator<(const pll &a , const pll & b) {
    return a.first*b.second<a.second*b.first;
}

bool comp1(const pair<pll, int> &a , const pair<pll, int> & b) {
    return a.first<b.first || (a.first==b.first && a.second<b.second);
}

bool operator==(const pll &a , const pll & b) {
    return a.first*b.second==a.second*b.first;
}

bool operator<(const pair<pll, int> &a , const pair<pll, int> & b) {
    return a.first<b.first || (a.first==b.first && a.second<b.second);
}


bool operator<(const pair<pll, pi> &a , const pair<pll, pi> & b) {
    return a.first<b.first || (a.first==b.first && a.second < b.second);
}

bool comp2(const pair<pll, pi> &a , const pair<pll, pi> & b) {
    return a.first<b.first || (a.first==b.first && a.second < b.second);
}

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
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,w;
    scanf("%d %d", &n, &w);
    vi x(n), v(n);
    forn(i,0,n) scanf("%d %d", &x[i], &v[i]);
    vector<pair<pll, int>> ord1;
    forn(i,0,n) {
        int s = abs(v[i] - w);
        ord1.pb(mp(mp(abs(x[i]), s), i));
    }
    sort(all(ord1),comp1);
    vi pos1(n);
    forn(i,0,n) pos1[ord1[i].second] = i;
    vector<pair<pll, pi>> ord2;
    forn(i,0,n) {
        int s = abs(v[i] + w);
        ord2.pb(mp(mp(abs(x[i]), s), mp(-pos1[i], i)));
    }
    sort(all(ord2),comp2);
    vi pos2(n);
    forn(i,0,n) pos2[ord2[i].second.second] = i;
    fenwick<int> fen(n);
    int pt = n-1;
    ll ans = 0;
    while(pt >= 0) {
        int pr = pt-1;
        while(pr>=0 && ord1[pt].first == ord1[pr].first) pr--;
        for(int i = pt; i>pr; i--) ans += fen.get(pos2[ord1[i].second]);
        for(int i = pt; i>pr; i--) fen.modify(pos2[ord1[i].second], 1);
        ans += ll(pt-pr) * (pt-pr-1)/2;
        pt = pr;
    }
    
    cout<<ans;
    
    
}