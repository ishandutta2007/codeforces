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
#define readv(x, n) forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
vi a;
vi b;
vector<pair<pi, pi>> ans;
vi rows, cols;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    a.resize(n);
    b.resize(n);
    readv(a,n);
    readv(b,n);
    forn(i,0,n) a[i]--, b[i]--;
    
    forn(i,0,n) {
        rows.pb(i);
        cols.pb(i);
    }
    forn(i,0,n) {
        if(a[i]!=i || b[i] != i) {
            int x = i;
            int y = i;
            while(a[x] != i) x++;
            while(b[y] != i) y++;
            ans.pb(mp(mp(i,y), mp(x,i)));
            swap(a[x], a[i]);
            swap(b[y], b[i]);
        }
    }
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d %d %d %d\n", x.first.first+1, x.first.second+1, x.second.first+1,x.second.second+1);
    
}