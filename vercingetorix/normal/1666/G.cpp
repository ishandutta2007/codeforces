#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <array>
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
const int A = 100500;
int parent[A];
int rk[A];
ld a2[A];
ld a1[A];
ld a0[A];
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
        a2[a] += a2[b];
        a1[a] += a1[b];
        a0[a] += a0[b];
        a2[b] = 0;
        a1[b] = 0;
        a0[b] = 0;
    }
}

ll sq(ll x) {
    return x*x;
}

struct pt3 {
    ll x,y,z;
    
    pt3(ll x, ll y, ll z) : x(x), y(y), z(z) {};

    ld norm() {
        return sqrt((ld)(sq(x) + sq(y) + sq(z)));
    }
    
    ld dist(const pt3 & b) {
        return sqrt((ld)(sq(x-b.x)+sq(y-b.y)+sq(z-b.z)));
    }
};

const int B = 1000501;

vector<pair<int, array<ld, 3>>> ev[B];
vpi un[B];
vpi req[B];

ld her(ld a, ld b, ld c) {
    ld p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vector<pt3> a;
    forn(i,0,n) {
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);
        a.emplace_back(x,y,z);
        make_set(i);
    }
    int m;
    read(m);
    while(m--) {
        int i,j,k;
        scanf("%d %d %d", &i, &j, &k);
        --i; --j; --k;
        if(a[j].z > a[i].z) swap(i,j);
        if(a[k].z > a[i].z) swap(i,k);
        if(a[k].z > a[j].z) swap(j,k);
        un[a[j].z].pb(mp(i,j));
        un[a[k].z].pb(mp(i,k));
        ld p = a[i].dist(a[j]);
        ld q = a[i].dist(a[k]);
        ld r = a[k].dist(a[j]);
        ld s = her(p,q,r);
        if(a[i].z == a[k].z) {
            ev[a[i].z].pb(mp(i, array<ld, 3>({0,0,s})));
        }
        else {
            ll h = a[i].z - a[k].z;
            ld q1 = q * (a[i].z - a[j].z) / h;
            ld s1 = s * (a[i].z - a[j].z) / h;
            ld s2 = s-s1;
            if(a[j].z < a[i].z) {
                ld tmp = s1 / sq(a[j].z-a[i].z);
                ev[a[i].z].pb(mp(i, array<ld, 3>({tmp,-2*tmp*a[i].z,tmp*(ld)sq(a[i].z)})));
                ev[a[j].z].pb(mp(i, array<ld, 3>({-tmp,+2*tmp*a[i].z,s1-tmp*(ld)sq(a[i].z)})));
            }
            if(a[k].z < a[j].z) {
                ld tmp = s2 / sq(a[j].z-a[k].z);
                ev[a[j].z].pb(mp(i, array<ld, 3>({-tmp,+2*tmp*a[k].z,s2-tmp*(ld)sq(a[k].z)})));
                ev[a[k].z].pb(mp(i, array<ld, 3>({tmp,-2*tmp*a[k].z,tmp*(ld)sq(a[k].z)})));
            }
            
        }
    }
    int q;
    read(q);
    forn(i,0,q) {
        int h, ind;
        scanf("%d %d", &h, &ind);
        ind--;
        req[h].pb(mp(ind, i));
    }
    vector<ld> ans(q);
    for(int cur = B-1; cur>=0; cur--) {
        for(auto x : req[cur]) {
            if(a[x.first].z <= cur) {
                ans[x.second] = -1;
                continue;
            }
            int i =find_set(x.first);
            ans[x.second] = (a2[i]*cur+a1[i])*cur+a0[i];
        }
        for(auto x : ev[cur]) {
            int i = find_set(x.first);
            a2[i] += x.second[0];
            a1[i] += x.second[1];
            a0[i] += x.second[2];
        }
        for(auto x : un[cur]) {
            union_sets(x.first, x.second);
        }
    }
    forn(i,0,q) {
        if(ans[i] < 0) printf("-1\n");
        else printf("%.12lf\n", (double)ans[i]);
    }
    
    
}