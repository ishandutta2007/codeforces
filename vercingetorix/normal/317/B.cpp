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
const int A = 1000;
int d[A][A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi dx = {1,-1,0,0};
    vi dy = {0,0,1,-1};
    vpi q;
    int n,t;
    scanf("%d %d", &n, &t);
    d[0][0] = n;
    if(n>=4) q.pb(mp(0,0));
    while(!q.empty()) {
        int x = q.back().first;
        int y = q.back().second;
        q.pop_back();
        if(d[x][y] < 4) continue;
        int add = d[x][y] / 4;
        d[x][y] %= 4;
        forn(i,0,4) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if(x2<0 || y2<0) continue;
            int was = d[x2][y2];
            if(x2 == 0 && y2 == 0) d[x2][y2] += 2*add;
            else if(x2 == 0 || y2 == 0) {
                if(x==0||y==0) d[x2][y2] += add;
                else d[x2][y2] += 2*add;
            }
            else d[x2][y2] += add;
            if(was<4 && d[x2][y2] >= 4) q.pb(mp(x2,y2));
        }
    }
    while(t--) {
        int x,y;
        scanf("%d %d", &x, &y);
        x = abs(x);
        y = abs(y);
        if(x>=A || y>=A) printf("0\n");
        else printf("%d\n", d[x][y]);
    }
    
    
    
}