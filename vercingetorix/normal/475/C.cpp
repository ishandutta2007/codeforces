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
const int A = 1000500;
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

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        st[a] += st[b];
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

void no() {
    cout<<-1;
    exit(0);
}

vs flip(const vs & a, int n, int m) {
    vs b(m, string(n, '?'));
    forn(i,0,n) forn(j,0,m) b[j][i] = a[i][j];
    return b;
}

int go(const vs & b, int n, int m) {
    vs a = b;
    int tlx = -1, tly = -1;
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == 'X' && tlx == -1) {
            tlx = i;
            tly = j;
        }
    }
    int ry = tly + 1;
    while(ry < m && a[tlx][ry] == 'X') ry++;
    int len = ry - tly;
    forn(i,0,n) {
        int l = 0;
        int r = m-1;
        while(l<=r && a[i][l] != 'X') l++;
        while(l<=r && a[i][r] != 'X') r--;
        if(l > r) continue;
        if(r-l+1 < len) return -1;
        forn(j,r-len+2,r+1) a[i][j] = '.';
    }
    vpi ord;
    forn(j,0,m) {
        int u = 0;
        int d = n-1;
        while(u<=d && a[u][j] != 'X') u++;
        while(u<=d && a[d][j] != 'X') d--;
        if(u>d) ord.pb(mp(-1,-1));
        else ord.pb(mp(u,d));
    }
    int s = 0;
    int e = m-1;
    while(ord[s].first == -1) s++;
    while(ord[e].first == -1) e--;
    forn(i,s,e+1) if(ord[i].first == -1) return -1;
    if(s == e) return len;
    int need = -1;
    forn(i,s+1,e+1) {
        if(ord[i].first > ord[i-1].second) return -1;
        int cur = ord[i-1].second - ord[i].first + 1;
        if(need == -1) need = cur;
        else if(need != cur) return -1;
    }
    return need*len;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n, &m);
    vs a;
    char c[2022];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    int can = 1;
    int nx = 0;
    int g = 0;
    forn(i,1,n) forn(j,1,m) {
        int cnt = 0;
        forn(i1,i-1,i+1) forn(j1,j-1,j+1) if(a[i1][j1] == 'X') cnt++;
        if(cnt == 3) {
            if(a[i][j] == '.' || a[i-1][j-1] == '.') can = 0;
        }
    }
    forn(i,0,n) forn(j,0,m) if(a[i][j] == 'X') nx++;
    forn(i,0,n*m) make_set(i);
    vpi dir;
    forn(i,-1,2) forn(j,-1,2) if(i*j == 0 && i+j!=0) dir.pb(mp(i,j));
    auto good = [&] (int i, int j) {return i>=0 && j>=0 && i<n && j<m;};
    if(can == 0) no();
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == 'X') {
            for(auto to : dir) {
                int i1 = i + to.first;
                int j1 = j + to.second;
                if(good(i1, j1) && a[i1][j1] == 'X') {
                    union_sets(i*m+j, i1*m+j1);
                }
            }
        }
    }
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == 'X') {
            int v = find_set(i*m+j);
            if(st[v] != nx) can = 0;
        }
    }
    if(can == 0) no();
    int best = -1;
    int cand = go(a,n,m);
    if(best == -1 || (cand != -1 && cand < best)) best = cand;
    a = flip(a, n, m);
    swap(n,m);
    cand = go(a,n,m);
    if(best == -1 || (cand != -1 && cand < best)) best = cand;
    cout<<best;
    
}