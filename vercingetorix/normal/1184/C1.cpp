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
    int n;
    cin>>n;
    vi x(4*n+1), y(4*n+1);
    vi cx(51,0);
    vi cy(51,0);
    forn(i,0,4*n+1) {
        cin>>x[i]>>y[i];
        cx[x[i]]++;
        cy[y[i]]++;
    }
    int l = 0;
    int r = 50;
    int u = 50;
    int d = 0;
    while(cx[r] < 2) r--;
    while(cx[l] < 2) l++;
    while(cy[u] < 2) u--;
    while(cy[d] < 2) d++;
    forn(i,0,4*n+1) {
        if(x[i] < l || x[i] > r || y[i] < d || y[i] > u || (x[i] != l && x[i] != r && y[i] !=u && y[i] !=d)) {
            cout<<x[i] << ' '<<y[i]<<'\n';
        }
    }
    
    
}