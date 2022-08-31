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

int cc[32][32];
int rr[32][32];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vi rm(31), cm(31);
    forn(deg,0,5) {
        for(int i = 1<<deg; i < 32; i+=(1<<(deg+1))) rm[i-1] = 1<<(2*deg);
        for(int i = 1<<deg; i < 32; i+=(1<<(deg+1))) cm[i-1] = 1<<(2*deg+1);
    }
//    forn(i,0,31) cout<<rm[i]<<' '; cout<<'\n';
//    forn(i,0,31) cout<<cm[i]<<' '; cout<<'\n';
    forn(i,0,n) {
        forn(j,0,n-1) {
            if(j!=0) printf(" ");
            printf("%d", cm[j]);
        }
        printf("\n");
    }
    forn(i,0,n-1) {
        forn(j,0,n) {
            if(j!=0) printf(" ");
            printf("%d", rm[i]);
        }
        printf("\n");
    }
    forn(i,0,32) forn(j,i+1,32) {
        forn(k,i,j) cc[i][j] ^= cm[k];
        cc[j][i] = cc[i][j];
        forn(k,i,j) rr[i][j] ^= rm[k];
        rr[j][i] = rr[i][j];
    }
    int x = 0; int y = 0;
    fflush(stdout);
    forn(i,0,k) {
        int res;
        scanf("%d", &res);
        int x2, y2;
        forn(cx,0,n) forn(cy,0,n) {
            if((rr[x][cx]^cc[y][cy]) == res) {
                x2 = cx;
                y2 = cy;
            }
        }
        printf("%d %d\n", x2+1, y2+1);
        x = x2;
        y = y2;
        fflush(stdout);
    }
    
    
}