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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n, &m);
//    vs a;
    vvi a(n, vi(m,0));
    vvi s(n, vi(m,0));
    char c[1000500];
    forn(i,0,n) {
        scanf("%s", c);
        forn(j,0,m) if(c[j] == 'X') a[i][j] = 1;
    }
    forn(i,0,n) forn(j,0,m) s[i][j] = a[i][j];
    forn(i,0,n) forn(j,0,m-1) s[i][j+1] += s[i][j];
    forn(i,0,n-1) forn(j,0,m) s[i+1][j] += s[i][j];
    int l = 0;
    int r = min(n,m);
    vpi dir;
    forn(i,-1,2) forn(j,-1,2) {
        if(i==0 && j == 0) continue;
        dir.pb(mp(i,j));
    }
    while(r - l > 1) {
        int k = (r+l)/2;
        if(2*k +1 > min(n,m)) {
            r =k;
            continue;
        }
//        if(s[n-1][k-1] > 0 || s[k-1][m-1] > 0 || s[n-1][m-1] > s[n-k-1][m-k-1]) {
//            r = k;
//            continue;
//        }
        int bad = 0;
        vvi b(n, vi(m, 0));
        vpi q;
        forn(i,k,n-k) {
            forn(j,k,m-k) {
                int cur = s[i+k][j+k];
                if(i>k) cur -= s[i-k-1][j+k];
                if(j>k) cur -= s[i+k][j-k-1];
                if(i>k && j>k) cur += s[i-k-1][j-k-1];
                if(cur == (2*k+1)*(2*k+1)) {
                    b[i][j] = 1;
                    q.pb(mp(i,j));
                }
//                if(cur != 0 && cur != (2*k+1)*(2*k+1)) {
//                    bad = 1;
//                    break;
//                }
            }
        }
        forn(it,0,k) {
            vpi nq;
            for(auto x : q) {
                for(auto to : dir) {
                    int i1 = x.first + to.first;
                    int j1 = x.second + to.second;
                    if(b[i1][j1] == 0) {
                        nq.pb(mp(i1,j1));
                        b[i1][j1] = 1;
                    }
                }
            }
            q = nq;
        }
        if(a==b ) l = k;
        else r= k;
//        if(bad) r = k;
//        else l = k;
    }
    vvi ans(n, vi(m,0));
    int k = l;
    forn(i,k,n-k) {
        forn(j,k,m-k) {
            int cur = s[i+k][j+k];
            if(i>k) cur -= s[i-k-1][j+k];
            if(j>k) cur -= s[i+k][j-k-1];
            if(i>k && j>k) cur += s[i-k-1][j-k-1];
            if(cur == (2*k+1)*(2*k+1)) {
                ans[i][j] = 1;
            }
        }
    }
    printf("%d\n", l);
    forn(i,0,n) {
        forn(j,0,m) {
            if(ans[i][j] == 1) printf("X");
            else printf(".");
        }
        printf("\n");
    }
    
}