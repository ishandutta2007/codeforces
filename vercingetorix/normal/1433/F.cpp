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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int INF =1e9;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    cin>>n>>m>>k;
    vvi a(n, vi(m,0));
    forn(i,0,n) forn(j,0,m) cin>>a[i][j];
    vi best(k,-INF);
    best[0] = 0;
    forn(i,0,n) {
        vvi d(k, vi(m+1,-INF));
        forn(j,0,k) d[j][0] = best[j];
        for(auto x : a[i]) {
            for(int t = m-1; t>=0; t--) {
                forn(r,0,k) {
                    d[(r+x)%k][t+1] = max(d[(r+x)%k][t+1], d[r][t] + x);
                }
            }
        }
        forn(t,0,m/2+1) forn(j,0,k) best[j] = max(best[j], d[j][t]);
    }
    cout<<best[0];
}