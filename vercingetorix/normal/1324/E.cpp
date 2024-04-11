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
const int A = 2050;
int d[A][A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,h,l,r;
    scanf("%d %d %d %d", &n, &h, &l, &r);
    readv(a,n);
    forn(i,0,h) d[n][i] = 0;
    for(int s = n-1; s>=0; s--) {
        forn(t,0,h) {
            int d1 = d[s+1][(t+a[s])%h];
            if((l<=(t+a[s])%h)&&((t+a[s])%h<=r)) d1 ++ ;
            int d2 = d[s+1][(t+a[s]-1)%h];
            if((l<=(t+a[s]-1)%h)&&((t+a[s]-1)%h<=r)) d2 ++ ;
            d[s][t] = max(d1,d2);
//            d[s][t] = max(d[s+1][(t+a[s])%h], d[s+1][(t+a[s]-1)%h]);
//            if((l<=t)&&(t<=r)) d[s][t]++;
        }
    }
    cout<<d[0][0];
    
    
    
}