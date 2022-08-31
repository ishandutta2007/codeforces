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

int ask(const vi & a) {
    printf("?");
    for(auto x: a) printf(" %d", x);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    if(k%2==0 && n%2!=0) {
        printf("-1\n");
        exit(0);
    }
    int ans = 0;
    while(n>=3*k || (n%k==0 && n>0)) {
        vi x;
        forn(pt,0,k) x.pb(n-pt);
        ans ^= ask(x);
        n-=k;
    }
    if(n == 0) {
        printf("! %d\n", ans);
        exit(0);
    }
    if(n>=2*k && n%2==0 && k%2==1) {
        vi x;
        forn(pt,0,k) x.pb(n-pt);
        ans ^= ask(x);
        n-=k;
    }
    if((n-k)%2 == 0) {
        vi x;
        forn(i,1,k+1) x.pb(i);
        ans^=ask(x);
        int r = (n-k)/2;
        x.clear();
        forn(i,k+1,k+r+1) x.pb(i);
        forn(i,1,k-r+1) x.pb(i);
        ans^=ask(x);
        x.clear();
        forn(i,k+r+1,k+2*r+1) x.pb(i);
        forn(i,1,k-r+1) x.pb(i);
        ans^=ask(x);
        printf("! %d\n", ans);
        exit(0);
    }
// n  k 
    int r = n;
    while(r>=2*(n-k)) {
        vi x;
        forn(i,1,n+1) if(i<=r-(n-k) || i> r) x.pb(i);
        ans^=ask(x);
        x.clear();
        forn(i,1,n+1) if(i<=r-2*(n-k) || i> r-(n-k)) x.pb(i);
        ans^=ask(x);
        r-=2*(n-k);
    }
    if(r>0) {
        vi x;
        forn(i,1,n+1) if(i<=r/2 || i> r + (n-k-r/2)) x.pb(i);
        ans^=ask(x);
        x.clear();
        forn(i,1,n+1) if((i<=r&&i>r/2) || i> r + (n-k-r/2)) x.pb(i);
        ans^=ask(x);
    }
    printf("! %d\n", ans);
}