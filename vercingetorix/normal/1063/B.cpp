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
#include <queue>
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
int n,m;

int to(int i, int j) {
    return i*m+j;
}

pi fr(int x) {
    return mp(x/m, x%m);
}

bool valid(int i, int j) {
    return i>=0 && j>=0 && i<n && j<m;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &m);
    int r,c;
    scanf("%d %d\n", &r, &c);
    int x,y;
    scanf("%d %d\n", &x, &y);
    r--; c--;
    vpi dir = {{0,-1}, {0,1}, {-1,0}, {1,0}};
    vs a;
    char cc[2020];
    forn(i,0,n) {
        scanf("%s", cc);
        a.pb(string(cc));
    }
    
    vector < vector < pair<int,int> > > g (n);
    int s = r*m+c;
    const int INF = 1e9+100;
    vvi d (n, vi(m, INF));
    d[r][c] = 0;
    priority_queue < pair<int,int> > q;
    q.push (make_pair (0, s));
    while (!q.empty()) {
        int v = q.top().second,  cur_d = -q.top().first;
        auto cor = fr(v);
        q.pop();
        int i = cor.first;
        int j = cor.second;
        if (cur_d > d[i][j])  continue;
        for(auto st : dir) {
            int i2 = i+st.first;
            int j2 = j+st.second;
            if(!valid(i2,j2)) continue;
            if(a[i2][j2] == '*') continue;
//            int to = g[v][j].first,
//            len = g[v][j].second;
            int len = 0;
            if(st.second < 0) len = 1;
            if (d[i][j] + len < d[i2][j2]) {
                d[i2][j2] = d[i][j] + len;
                q.push (make_pair (-d[i2][j2], to(i2, j2)));
            }
        }
    }
    int ans = 0;
    forn(i,0,n) {
        forn(j,0,m) {
            if(d[i][j] <= x) {
                int tor = d[i][j] + j - c;
                if(tor <= y) ans ++;
            }
        }
    }
    cout<<ans;
    
}