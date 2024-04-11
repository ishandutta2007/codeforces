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

void yes(const vll & a) {
    printf("YES\n");
    for(auto x : a) printf("%lld ", x);
    exit(0);
}

void no() {
    printf("NO\n");
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(b,n);
    int mx = 0;
    int mn = 1e9;
    forn(i,0,n) {
        mx = max(b[i], mx);
        mn = min(mn, b[i]);
    }
    if(mx == 0) {
        yes(vll(n,1));
    }
    else if(mx == mn) no();
    vll a(n);
    forn(i,0,n) if(b[i] != mx && b[(i+1)%n] == mx) {
        int s = (i+1)%n;
        ll sum = b[s];
        forn(it,0,n) {
            a[s] = sum;
            s = (s+n-1)%n;
            if(b[s] == 0 && sum == mx) sum += mx;
            else sum += b[s];
        }
        yes(a);
    }
    
}