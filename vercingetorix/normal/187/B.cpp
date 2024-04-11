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
const int A = 60;
const int INF = 1e9;
int d[A][A][A];
int len[A][A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,r;
    scanf("%d %d %d", &n, &m, &r);
    forn(i,0,m) forn(s,0,n) forn(f,0,n) scanf("%d", &len[i][s][f]);
    forn(car,0,m)
        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    len[car][i][j] = min (len[car][i][j], len[car][i][k] + len[car][k][j]);
    forn(s,0,n) forn(f,0,n) forn(k,0,A) d[s][f][k] = INF;
    forn(car,0,m) forn(s,0,n) forn(f,0,n) d[s][f][0] = min(d[s][f][0], len[car][s][f]);
//    forn(i,0,n) {
//        forn(j,0,n) cout<<d[i][j][0]<<' ';
//        cout<<'\n';
//    }
    for (int k=0; k+1<A; ++k) {
        forn(i,0,n) forn(j,0,n) d[i][j][k+1] = d[i][j][k];
        forn(mid,0,n)
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    d[i][j][k+1] = min (d[i][j][k+1], d[i][mid][k] + d[mid][j][0]);
    }
    
    while(r--) {
        int s,t,k;
        scanf("%d %d %d", &s, &t, &k);
        s--; t--;
        k = min(k, A-1);
        printf("%d\n", d[s][t][k]);
    }
    
    
}