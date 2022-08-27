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

const long long mod = 777777777;
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

const int A = (1<<8) + 1;
ll cnk[A][A];
ll d[A][A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,A) cnk[i][0] = 1;
    forn(n,1,A) forn(k,1,n+1) {
        cnk[n][k] = (cnk[n-1][k-1] + cnk[n-1][k])%mod;
    }
    int n,k;
    cin>>n>>k;
    d[0][0] = 1;
    forn(l,1,n+1) {
        for(int wasl = k; wasl>=0; wasl--) {
            for(int wast = n-k; wast >=0; wast--) {
                d[wasl][wast] %= mod;
                forn(tk,1,k+1-wasl) if(tk !=l) {
                    d[wasl+tk][wast] = (d[wasl+tk][wast]+d[wasl][wast]*cnk[n-wasl-wast][tk]);
                }
                d[wasl][wast+l] = (d[wasl][wast+l]+d[wasl][wast]*cnk[n-wasl-wast][l])%mod;
            }
            if(wasl % 11 == 0) {
                forn(i,wasl,k+1) forn(j,0,n-k+1) d[i][j] %= mod;
            }
        }
    }
    cout<<d[k][n-k];
    
}