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

const long long mod = 998244353;
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

const int A= 251;
ll d[A][A];
ll cnk[A][A];
ll pm[A][A*A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(n,0,A) cnk[n][0] = 1;
    forn(x,0,A) pm[x][0] = 1;
    forn(x,0,A) forn(l,1,A*A) pm[x][l]  = pm[x][l-1]*x%mod;
    forn(n,1,A) forn(k,1,A) cnk[n][k] = (cnk[n-1][k] + cnk[n-1][k-1]) % mod;
    d[0][0] = 1;
    int n,k;
    cin>>n>>k;
    forn(last,0,k) {
        for(int was = n-1; was >= 0; was--) {
            forn(tk, 0, n-was) {
//                cout<<was+tk<<' '<<last+1<<" from "<<was<<' '<<last<<' '<<d[was][last]*cnk[was+tk][tk]%mod*pm[k-last][tk*was+was*(was-1)/2]<<'\n';
                d[was+tk][last+1] = (d[was+tk][last+1] + d[was][last]*cnk[was+tk][tk]%mod*pm[k-last][tk*was+tk*(tk-1)/2])%mod;
            }
        }
    }
    cout<<d[n-1][k];
    
    
}