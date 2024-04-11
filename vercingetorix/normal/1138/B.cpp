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
    cin >> n;
    string as,bs;
    cin >> as >> bs;
    vi a(n);
    vi b(n);
    forn(i,0,n)  {
        a[i] = as[i] - '0';
        b[i] = bs[i] - '0';
    }
    vi ind;
    vi ind2;
    forn(i,0,n/2) ind.pb(i);
    forn(i,n/2,n) ind2.pb(i);
    int sa = 0;
    int sb = 0;
    for(auto i : ind) sa += a[i];
    for(auto i : ind2) sb += b[i];
    forn(it,0,5010) {
        int done = 0;
        forn(i,0,n/2) forn(j,0,n/2) {
            int i1 = ind[i];
            int j1 = ind2[j];
            int dif = abs(sa - sb);
            int sa2 = sa - a[i1] + a[j1];
            int sb2 = sb - b[j1] + b[i1];
            if(abs(sa2-sb2) < dif) {
                swap(ind[i], ind2[j]);
                sa = sa2;
                sb = sb2;
                done = 1;
            }
        }
        if(done == 0) break;
    }
    if(sa != sb) printf("-1");
    else for(auto i : ind) printf("%d ", i+1);
    
    
}