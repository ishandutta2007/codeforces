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

ll d[2][101][101][101];

const int AC = 201;
const int BC = 201;
ll cnk[AC][BC];

void initcnk() {
    forn(i,0,AC) cnk[i][0] = 1;
    forn(i,1,AC) forn(j,1,BC) {
        cnk[i][j] = cnk[i-1][j-1] + cnk[i-1][j];
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initcnk();
    int n,m,k;
    cin>>n>>m>>k;
    forn(tk,1,n+1) d[0][tk][tk][1] = 1;
    ll ans = 0;
    forn(cm,0,m-1) {
        int cur = cm%2;
        int nx = cur^1;
        forn(i,0,n+1) forn(j,0,n+1) forn(w,0,k+1) d[cur^1][i][j][w] = 0;
        forn(wn,1,n+1) forn(l,1,n+1-wn) forn(w,1,k+1) {
            int add = 0;
            while(1) {
                ll mul = cnk[add+l-1][add];
                if(wn + l + add > n || mul*w > k) break;
                d[nx][wn + l + add][add][mul*w] = d[nx][wn + l + add][add][mul*w] + d[cur][wn][l][w];
                if(d[nx][wn + l + add][add][mul*w] >= mod) d[nx][wn + l + add][add][mul*w]-=mod;
                add++;
            }
        }
        forn(wn,1,n+1) forn(w,1,k+1) ans += (m-cm-1)*d[nx][wn][0][w];
        ans %= mod;
    }
    cout<<ans;
    
    
}