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
int req(const vi & a, const vi & b) {
    printf("? %d %d\n", (int)a.size(), (int)b.size());
    forn(i,0,a.size()) {
        printf("%d", a[i]);
        if(i+1!=a.size()) printf(" ");
    }
    printf("\n");
    forn(i,0,b.size()) {
        printf("%d", b[i]);
        if(i+1!=b.size()) printf(" ");
    }
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}
int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int to = 1;
        vi a(1, 1);
        while(1) {
            int res = req(a, vi(1, to+1));
            if(res != 0) break;
            a.pb(++to);
        }
        int nz = to+1;
        vi ans;
        forn(i,to+2,n+1) {
            if(req(vi(1, to+1), vi(1, i)) == 0) ans.pb(i);
        }
        int l = 0;
        int r = to;
        while(r-l > 1) {
            int m = (r+l)/2;
            vi x;
            forn(i,1,m+1) x.pb(i);
            if(req(x, vi(1, to+1)) == 0) l = m;
            else r = m;
        }
        forn(i,1,to+1) if(i!=r) ans.pb(i);
        printf("! %d", ans.size());
        for(auto x : ans) printf(" %d", x);
        printf("\n");
        fflush(stdout);
    }
}