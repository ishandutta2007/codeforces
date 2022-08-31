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

const long long mod = 998244353;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    int A = 1000010;
//    A = 1000;
    vll d0(A, 0);
    vll d1(A, 0);
    vvll dd(2, vll(A, 0));
    dd[0][2] = 1;
//    dd[1][2] = 1;
    dd[1][1] = 1;
    vi d2(1,1);
    forn(i,0,30) d2.pb(d2.back() * 2);
    vi gr0;
    gr0.pb(2);
    forn(r, 3, A) {
        int d =0;
        while(r >= d2[d]) d++;
        int rmin = max(d2[d-2] - 1, r - d2[d-1]);
        int rmax = min(d2[d-1] - 1 , r - d2[d-2]);
        auto itl = lower_bound(all(gr0), rmin);
        auto itr = upper_bound(all(gr0), rmax);
        for(auto it = itl; it != itr; it++) {
            int r2 = *it;
            int r1 = r-1-r2;
            dd[1-r1%2][r] = (dd[1-r1%2][r] + dd[r1%2][r1] * dd[0][r2]) % mod;
        }
        if(dd[0][r] != 0) gr0.pb(r);
    }
//    forn(i,3,A) if(dd[0][i] + dd[1][i] != 0) cout<<i<<' '<<dd[0][i]+dd[1][i]<<endl;
//    cout<<dd[0][5] + dd[1][5];
    cout<<dd[0][n]+dd[1][n];
}