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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int A = 100500;
int parent[A];
int rk[A];
int cnt[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
    cnt[v] = 1;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
        cnt[a] += cnt[b];
        cnt[b] = 0;
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vpi e;
    vi nx(n, -1);
    forn(it,0,m) {
        readv(a,n);
        forn(i,0,n) a[i]--;
        forn(i,0,n-1) {
            if(it == 0) nx[a[i]] = a[i+1];
            else if(nx[a[i]] != a[i+1]) nx[a[i]] = -1;
        }
        nx[a[n-1]] = -1;
    }
    forn(i,0,n) make_set(i);
    forn(i,0,n) if(nx[i] != -1) union_sets(nx[i], i);
    vi done(n, 0);
    ll ans = 0;
    forn(i,0,n) {
        int v = find_set(i);
        if(done[v] == 0) {
            ans += (ll(cnt[v])*(cnt[v]+1))/2;
            done[v] = 1;
        }
    }
    cout<<ans;
    
}