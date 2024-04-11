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
const int A = 1<<22;
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

int union_sets (int a, int b) {
    if(a == -1) return b;
    else if(b == -1) return a;
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
    return a;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    int neg = (1<<n) - 1;
    readv(a,m);
    vi join(1<<n, 0);
    vi to(1<<n, -1);
    vi ind(1<<n, -1);
    forn(i,0,m) {
        make_set(i);
        ind[a[i]^neg] = i;
        join[a[i]] = 1;
        to[a[i]] = i;
    }
    forn(mask,0,1<<n) {
        if(join[mask]) {
            forn(bit, 0, n) {
                join[mask | (1<<bit)] = 1;
            }
        }
    }
    for(int mask = (1<<n)-1; mask>=0; mask--) {
        if(join[mask]) {
            forn(bit, 0, n) {
                ind[mask] = union_sets(ind[mask], ind[mask | (1<<bit)]);
            }
            union_sets(ind[mask], to[mask]);
        }
    }
    
    
    int ans =  0;
    forn(i,0,m) if(find_set(i) == i) ans++;
    cout<<ans;
    
    
}