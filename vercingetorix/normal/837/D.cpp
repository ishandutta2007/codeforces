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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    cin>>n>>k;
    const int INF = 1e9;
    vvi d(k+1, vi(27*k+1, -INF));
    d[0][0] = 0;
    forn(i,0,n) {
        ll x;
        cin>>x;
        int d2 = 0;
        int d5 = 0;
        while(x%2==0) {
            x/=2;
            d2++;
        }
        while(x%5==0) {
            x/=5;
            d5++;
        }
        for(int num = k; num >= 1; num--) {
            forn(j,0,27*k+1-27) {
                d[num][j+d5] = max(d[num][j+d5], d[num-1][j] + d2);
            }
        }
    }
    int ans = 0;
    forn(i,0,27*k+1) ans = max(ans, min(i, d[k][i]));
    cout<<ans;
    
    
}