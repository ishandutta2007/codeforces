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

bool gd(int x) {
    return x>=0 && x < 10;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    char ca[100500];
    char cb[100500];
    scanf("%s", ca);
    scanf("%s", cb);
    vi a,b;
    forn(i,0,n) a.pb(ca[i]-'0');
    forn(i,0,n) b.pb(cb[i]-'0');
    vi op(1,0);
    forn(i,0,n) {
        op.pb(b[i]-a[i]-op[i]);
    }
    if(op.back() != 0) {
        cout<<-1;
        exit(0);
    }
    ll ans = 0;
    forn(i,0,n) ans +=abs(op[i]);
    printf("%lld\n", ans);
    int pt = 1;
    int done = min(ans,100000ll);
    while(done) {
        if(op[pt] == 0) pt++;
        else {
            int dir = op[pt] / abs(op[pt]);
            if(gd(a[pt] + dir) && gd(a[pt-1] + dir)) {
                a[pt] += dir;
                a[pt-1] += dir;
                op[pt] -= dir;
                printf("%d %d\n", pt, dir);
                pt--;
                done--;
            }
            else pt++;
        }
    }
    
    
}