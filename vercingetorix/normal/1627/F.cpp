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
int n,k;

#ifdef LOCAL
const int A = 20;
#else
const int A = 500;
#endif
int r[A][A];
int b[A][A];
//int d[A/2][A];

int ans;

//void go() {
//    forn(i,0,k/2) forn(j,0,k) d[i][j] = 0;
//    forn(tk,1,k) {
//        forn(j,0,tk-1) d[0][tk] += r[0][j];
//        forn(j,tk,k) d[0][tk] += r[0][j];
//    }
//    forn(l,1,k/2) {
//        forn(was,1,k) {
//            int cur = 0;
//            forn(j,was,k) cur += b[l-1][j];
//            forn(j,0,k) cur += r[l][j];
//            forn(to,1,k) {
//                cur -= r[l][to-1];
//                if(to>=2) cur += r[l][to-2];
//                if(was >= to) cur += b[l-1][to-1];
//                else cur -= b[l-1][to-1];
//                d[l][to] = max(d[l][to], d[l-1][was] + cur);
//            }
//        }
//    }
//    forn(was,1,k) {
//        int num = min(was, k-was);
//        int cand = d[k/2-1][was];
//        forn(j,0,num) {
//            cand += b[k/2-1][j];
//            cand += b[k/2-1][k-1-j];
//        }
//        ans = max(ans, cand);
//    }
//}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        scanf("%d %d", &n, &k);
        vvi cor(n, vi(4));
        ans = 0;
        forn(i,0,n) {
            forn(j,0,4) scanf("%d", &cor[i][j]);
            forn(j,0,4) cor[i][j]--;
            if(cor[i][0] + cor[i][1] > cor[i][2] + cor[i][3]) {
                swap(cor[i][0], cor[i][2]);
                swap(cor[i][1], cor[i][3]);
            }
        }
        auto fill = [&] {
            forn(i,0,k) forn(j,0,k) {
                r[i][j] = 0;
                b[i][j] = 0;
            }
            forn(i,0,n) {
                if(cor[i][0] == cor[i][2]) {
                    r[cor[i][0]][cor[i][1]]++;
                    r[k-1-cor[i][2]][k-1-cor[i][3]]++;
                }
                else {
                    b[cor[i][0]][cor[i][1]]++;
                    b[k-1-cor[i][2]][k-1-cor[i][3]]++;
                }
            }
        };
        fill();
        int nd = (k+1)*(k+1);
        vector < vector < pair<int,int> > > g (nd);
        forn(i,1,k) forn(j,0,k) {
            int u = i*(k+1) + j;
            int v = i*(k+1) + j + 1;
            int w = b[i-1][j];
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
        }
        forn(j,1,k) forn(i,0,k) {
            int u = i*(k+1) + j;
            int v = (i+1)*(k+1) + j;
            int w = r[i][j-1];
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
        }
        const int INF = 1e9;
        int s = k/2*(k+1) + k/2;
        vector<int> d (nd, INF),  p (nd);
        d[s] = 0;
        priority_queue < pair<int,int> > q;
        q.push (make_pair (0, s));
        while (!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if (cur_d > d[v])  continue;
            
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push (make_pair (-d[to], to));
                }
            }
        }
        int ans = 0;
        forn(i,0,k+1) ans = max(ans, n-d[i]);
        forn(i,0,k+1) ans = max(ans, n-d[(k+1)*k + i]);
        forn(i,0,k+1) ans = max(ans, n-d[(k+1)*i]);
        forn(i,0,k+1) ans = max(ans, n-d[(k+1)*i + k]);
        printf("%d\n", ans);
    }
    
    
}