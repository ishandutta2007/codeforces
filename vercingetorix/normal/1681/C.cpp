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
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d", &n);
        vvi a(n, vi(2));
        forn(i,0,2) forn(j,0,n) scanf("%d", &a[j][i]);
        forn(i,0,n) a[i].pb(i);
        vvi b = a;
        srt(b);
        int fail = 0;
        forn(j,1,n) forn(i,0,2) if(b[j][i] < b[j-1][i]) fail = 1;
        if(fail) {
            printf("-1\n");
            continue;
        }
        vpi ans;
        vi cur;
        forn(i,0,n) cur.pb(i);
        forn(i,0,n) {
            int j = i;
            while(cur[j] != b[i][2]) j++;
            if(i!=j) {
                ans.pb(mp(i,j));
                swap(cur[i], cur[j]);
            }
        }
        printf("%d\n", ans.size());
        for(auto x: ans) printf("%d %d\n", x.first+1, x.second+1);
    }
    
    
}