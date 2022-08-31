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
typedef std::vector<ld> vd;
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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

string s;
vll d10(1,1);


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(i,0,1000) d10.pb(d10.back()*10%mod);
    getline(cin, s);
    int n = s.size();
    vector<vvll> f(10, vvll(n+1, vll(n+1, 0)));
    forn(i,0,10) f[i][n][0] = 1;
    for(int i = n-1; i>=0; i--) {
        forn(dig,0,10) {
            forn(l,0,n+1) {
                f[dig][i][l] = f[dig][i+1][l]*(9-dig);
                if(l>0) f[dig][i][l] += f[dig][i+1][l-1]*(dig+1);
                f[dig][i][l] %= mod;
            }
        }
    }
    vector<vvll> d(10, vvll(n+1, vll(n+1,0)));
    forn(i,0,10) d[i][n][0] = 1;
    for(int pos = n-1; pos >=0; pos--) {
        int cdig = s[pos] - '0';
        forn(dig,0,10) {
            if(dig < cdig) {
                forn(l,0,n+1) {
                    d[dig][pos][l] = d[dig][pos+1][l];
                    d[dig][pos][l] += f[dig][pos+1][l]*(cdig-dig-1);
                    if(l>0) d[dig][pos][l] += f[dig][pos+1][l-1] * (dig+1);
                    d[dig][pos][l] %= mod;
                }
            }
            else if(dig==cdig) {
                forn(l,1,n+1) {
                    d[dig][pos][l] = f[dig][pos+1][l-1]*cdig;
                    d[dig][pos][l] += d[dig][pos+1][l-1];
                    d[dig][pos][l] %= mod;
                }
            }
            else if(dig>cdig) {
                forn(l,1,n+1) {
                    d[dig][pos][l] = d[dig][pos+1][l-1];
                    d[dig][pos][l] += f[dig][pos+1][l-1]*cdig;
                    d[dig][pos][l] %= mod;
                }
            }
        }
    }
    vvll cum(10, vll(n+1, 0));
    forn(i,0,10) cum[i][0] = d[i][0][0];
    forn(i,0,10) forn(j,1,n+1) cum[i][j] = (cum[i][j-1] + d[i][0][j]) % mod;
    ll ans  = 0;
    forn(pos, 0, n) {
        forn(dig,0,10) {
            ll num = cum[9][n];
            if(dig>0) num = cum[dig-1][pos];
            num = num + mod - cum[dig][pos];
            num%=mod;
            ans += ll(num*dig)%mod * d10[n-1-pos] % mod;
            ans%=mod;
        }
    }
    cout<<ans;
    
}