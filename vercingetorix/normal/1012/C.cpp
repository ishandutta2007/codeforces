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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int INF = 1e9;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    int km = (n+1)/2;
    vi d(km+1, INF);
    vi d1(km+1,INF);
    vi dv(km+1, INF);
    dv[0] = 0;
    forn(i,0,n) {
        vi nd1 = d;
        forn(k,1,km+1) {
            d[k] = dv[k-1];
            if(i>0) d[k] += max(0, a[i-1] - a[i] + 1);
            if(i<n-1) d[k] += max(0, a[i+1] - a[i] + 1);
            if(d1[k-1] < INF) {
                int cand = d1[k-1];
                if(i<n-1) cand += max(0, a[i+1] - a[i] + 1);
                int tol = min(a[i-2]-1, a[i-1]);
                cand += max(0, tol-a[i]+1);
                d[k] = min(d[k], cand);
            }
        }
        forn(k,1,km+1) dv[k] = min(dv[k], d1[k]);
        d1 = std::move(nd1);
    }
    forn(i,1,km+1) printf("%d ", min(dv[i], min(d1[i], d[i])));
    
    
}