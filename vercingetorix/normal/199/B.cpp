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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi x(4), y(4), r(4);
    cin>>x[0]>>y[0]>>r[0]>>r[1];
    x[1]=x[0]; y[1] = y[0];
    cin>>x[2]>>y[2]>>r[2]>>r[3];
    x[3]=x[2]; y[3] = y[2];
    int a[2][2];
    int ins[2][2];
    forn(i,0,2) forn(j,0,2) {
        a[i][j] = 1;
        ins[i][j] = 0;
        int x1 = x[i];
        int y1 = y[i];
        int x2 = x[2+j];
        int y2 = y[2+j];
        int r1 = r[i];
        int r2 = r[2+j];
        int dist2 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        if(dist2 < (r1+r2)*(r1+r2) && dist2 > (r1-r2)*(r1-r2)) a[i][j] = 0;
        else if(dist2 <= (r1-r2)*(r1-r2)) ins[i][j] = 1;
    }
    int ans = a[0][1]*a[0][0]+a[0][1]*a[1][1]+a[1][0]*a[0][0]+a[1][0]*a[1][1];
    if(ins[0][0] && ins[0][1] && r[0] > r[2] && r[0] < r[3]) ans--;
    if(ins[1][0] && ins[1][1] && r[1] > r[2] && r[1] < r[3]) ans--;
    if(ins[0][0] && ins[1][0] && r[2] > r[0] && r[2] < r[1]) ans--;
    if(ins[0][1] && ins[1][1] && r[3] > r[0] && r[3] < r[1]) ans--;
    
    if(ins[1][1] && ins[1][0] + ins[0][1] != 2 && a[1][0] == 1 && a[0][1] == 1) ans -= 2;
    else {
        if(a[1][1] == 0 && ins[1][0] && ins[0][1] && a[0][0] == 1 && ins[0][0] == 0) ans-=2;
        else {
            if(ins[0][1] && a[0][0] == 1 && ins[0][0] == 0) ans--;
            if(ins[1][0] && a[0][0] == 1 && ins[0][0] == 0) ans--;
        }
    }
    cout<<ans;
    
}