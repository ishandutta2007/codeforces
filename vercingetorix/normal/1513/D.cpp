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
const int A = 200500;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
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
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int n,p;
        scanf("%d %d", &n, &p);
        forn(i,0,n) make_set(i);
        readv(a,n);
        vpi ord;
        forn(i,0,n) ord.pb(mp(a[i], i));
        srt(ord);
        ll ans = 0;
        int ednum = 0;
        forn(i,0,n) {
            int ind = ord[i].second;
            int val = ord[i].first;
            if(val >= p) break;
            int l = ind;
            int r = ind;
            while(l>0 && a[l-1]%val == 0 && find_set(l) != find_set(l-1)) {
                union_sets(l, l-1);
                l--;
                ans += val;
                ednum++;
            }
            while(r<n-1 && a[r+1]%val == 0 && find_set(r) != find_set(r+1)) {
                union_sets(r, r+1);
                r++;
                ans += val;
                ednum++;
            }
        }
        while(ednum < n-1) {
            ednum++;
            ans+=p;
        }
        printf("%lld\n", ans);
    }
    
    
    
}