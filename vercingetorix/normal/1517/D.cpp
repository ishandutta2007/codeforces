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

int d[11][501][501];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    if(k%2!=0) {
        forn(i,0,n) {
            forn(j,0,m) printf("-1 ");
            printf("\n");
        }
        return 0;
    }
    vvi a(n, vi(m-1));
    vvi b(n-1, vi(m));
    forn(i,0,n) forn(j,0,m-1) scanf("%d", &a[i][j]);
    forn(i,0,n-1) forn(j,0,m) scanf("%d", &b[i][j]);
    vpi dir;
    dir.pb(mp(1,0));
    dir.pb(mp(-1,0));
    dir.pb(mp(0,1));
    dir.pb(mp(0,-1));
    forn(l,1,k/2 + 1) {
        forn(x,0,n) forn(y,0,m) {
            for(auto pp : dir) {
                int x2 = x+pp.first;
                int y2 = y+pp.second;
                if(x2<0 || x2>=n || y2<0 || y2>=m) continue;
                int cand = 0;
                if(pp.first == 0) cand = a[x][min(y,y2)];
                else cand = b[min(x,x2)][y];
                cand += d[l-1][x2][y2];
                if(d[l][x][y] == 0 || d[l][x][y] > cand) d[l][x][y] = cand;
            }
        }
    }
    forn(i,0,n) {
    forn(j,0,m) {
        printf("%d ", 2*d[k/2][i][j]);
    }
        printf("\n");
    }
    
}