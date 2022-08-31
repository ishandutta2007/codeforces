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

const int A = 1000;
int parent[A];
int rk[A];
int st[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
    st[v] = 1;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

int fe = 0;
multiset<int> comp;

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        comp.erase(comp.find(st[a]));
        comp.erase(comp.find(st[b]));
        st[a] += st[b];
        comp.insert(st[a]);
        if (rk[a] == rk[b])
            ++rk[a];
    }
    else {
        fe++;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,d;
    scanf("%d %d", &n, &d);
    forn(i,0,n) {
        make_set(i);
        comp.insert(1);
    }
    forn(i,0,d) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        union_sets(u, v);
        auto it = comp.end();
        int ans = -1;
        forn(i,0,fe+1) {
            it--;
            ans += *it;
        }
        printf("%d\n", ans);
    }
    
}