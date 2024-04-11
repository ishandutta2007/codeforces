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
const int A = 400500;

int dist[A];
int parent[A];
int rk[A];
vi ver[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
    dist[v] = 0;
    ver[v].pb(v);
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b, int w) {
    int wa = a;
    int wb = b;
    a = find_set (a);
    b = find_set (b);
    w^=dist[wa]^dist[wb];
    if (a != b) {
        if(ver[a].size() < ver[b].size()) swap(a,b);
        for(auto x : ver[b]) {
            parent[x] = a;
            dist[x] ^= w;
            ver[a].pb(x);
        }
        ver[b].clear();
    }
}

class CoordinateCompressor {
public:
    set<int> has;
    map<int, int> to;
    int num = 0;

    void add(int x) {
        make_set(num);
        to[x] = num++;
        has.insert(x);
    }
    
    int comp(int x) {
        if(has.find(x) == has.end()) {
            add(x);
            return num-1;
        }
        else return to[x];
    }
};
CoordinateCompressor comp;



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int last = 0;
    int q;
    read(q);
    while(q--) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int l,r,x;
            scanf("%d %d %d", &l, &r, &x);
            l^=last;
            r^=last;
            x^=last;
            if(l>r) swap(l,r);
            union_sets(comp.comp(l-1), comp.comp(r), x);
        }
        else {
            int l,r;
            scanf("%d %d", &l, &r);
            l^=last;
            r^=last;
            if(l>r) swap(l,r);
            l = comp.comp(l-1);
            r = comp.comp(r);
            if(find_set(l) == find_set(r)) {
                last = dist[l]^dist[r];
                printf("%d\n", last);
            }
            else {
                printf("-1\n");
                last = 1;
            }
        }
    }
    
    
}