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

vvi a;
ll cur = 0;
int n,m;
int count(int i, int j, pi dir) {
    if(a[i][j] == 1) return 0;
    else {
        int i2 = i+dir.first;
        int j2=j+dir.second;
        if(i2>=0 && j2>=0 && i2<n&&j2<m) return 1 + count(i2,j2,mp(dir.second, dir.first));
        else return 1;
    }
}

ll count(int i, int j) {
    int dl = count(i, j, mp(-1,0));
    int ul = count(i,j,mp(0,-1));
    int dr = count(i,j,mp(0,1));
    int ur = count(i,j,mp(1,0));
    return (dl)*(dr)+(ul)*(ur) - 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta=1;
//    read(ta);
    forn(ifa,0,ta) {
        int q;
        scanf("%d %d %d\n", &n, &m, &q);
        a = vvi(n, vi(m, 0));
        cur = 0;
        forn(i,0,n) forn(j,0,m) {
            int il = i - min(i,j);
            int jl = j - min(i,j);
            int dl = 2*min(i,j);
            int ul = 2*min(i,j);
            if(il > 0) dl++;
            if(jl > 0) ul++;
            cur += (dl+1)+(ul+1) - 1;
        }
        forn(i,0,q) {
            int x,y;
            scanf("%d %d", &x, &y);
            x--; y--;
            if(a[x][y] == 0) {
                cur -= count(x,y);
                a[x][y] = 1;
            }
            else {
                a[x][y] = 0;
                cur += count(x,y);
            }
            printf("%lld\n", cur);
        }
        
    }
    
    
}