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
vi a;
int n;

void make1() {
    forn(i,0,n) swap(a[2*i], a[2*i+1]);
}

void make2() {
    forn(i,0,n) swap(a[i], a[i+n]);
}

bool sorted() {
    forn(i,1,2*n) if(a[i-1] > a[i]) return false;
    return true;
}

void stop(int x) {
    cout<<x;
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    a.resize(2*n);
    forn(i,0,2*n) scanf("%d", &a[i]);
    int INF = 10000;
    vi b = a;
    int ans = INF;
    forn(i,0,2*n+2) {
        if(sorted()) {
            ans = min(ans, i);
            break;
        }
        if(i%2 == 0) make1();
        else make2();
    }
    a = b;
    forn(i,0,2*n+2) {
        if(sorted()) {
            ans = min(ans, i);
            break;
        }
        if(i%2 == 1) make1();
        else make2();
    }
    if(ans == INF) ans = -1;
    cout<<ans;
}