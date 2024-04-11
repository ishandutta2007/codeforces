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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

ll d[241][51][51];
//ll d[241][3][3];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vvll cnk(51, vll(51, 0));
    forn(i,0,51) cnk[i][0] = 1;
    forn(i,1,51) {
        forn(j,1,i+1) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    int n, k;
    cin>>n>>k;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    int c1=0, c2=0;
    forn(i,0,n) {
        if(a[i] == 50) c1++;
        else c2++;
    }
    k /= 50;
    d[0][c1][c2] = 1;
    forn(s,0,240) {
        forn(i,0,c1+1) forn(j,0,c2+1) d[s][i][j] = d[s][i][j] % mod;
        if(d[s][0][0] > 0) {
            printf("%d\n", s);
            printf("%lld\n", d[s][0][0]);
            return 0;
        }
        if(s%2 == 0) {
            forn(w1,0,c1+1) {
                forn(w2,0,c2+1) {
                    if(d[s][w1][w2] == 0) continue;
                    forn(m1,0,w1+1) {
                        ll op = (d[s][w1][w2] * cnk[w1][m1]) % mod;
                        forn(m2,0,w2+1) {
                            if(m1+m2==0) continue;
                            if(m1+2*m2 > k) break;
                            d[s+1][w1-m1][w2-m2] += (op * cnk[w2][m2]) % mod;
                        }
                    }
                }
            }
        }
        else {
            forn(w1,0,c1+1) {
                forn(w2,0,c2+1) {
                    if(d[s][w1][w2] == 0) continue;
                    forn(m1,0,c1-w1+1) {
                        ll op = (d[s][w1][w2] * cnk[c1-w1][m1]) % mod;
                        forn(m2,0,c2-w2+1) {
                            if(m1+m2==0) continue;
                            if(m1+2*m2 > k) break;
                            d[s+1][w1+m1][w2+m2] += (op * cnk[c2-w2][m2]) % mod;
                        }
                    }
                }
            }
        }
        
    }
    cout<<-1<<'\n'<<0;
    
    
}