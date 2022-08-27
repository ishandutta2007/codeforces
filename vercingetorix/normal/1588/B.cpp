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
ll ask(int l, int r) {
    if(r<=l) return 0;
    printf("? %d %d\n", l+1, r+1);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}
int main()
{
    //#ifdef LOCAL
    //    freopen("input.txt", "rt", stdin);
    //    freopen("output.txt", "wt", stdout);
    //#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        ll tot = ask(0,n-1);
        int l = 0;
        int r = n-1;
        ll lf;
        int m;
        while(r-l>1) {
            m = (r+l)/2;
            lf = ask(l,m);
            if(lf == 0) l = m;
            else if(lf == tot) r = m;
            else break;
        }
        if(r-l==1) m = l;
        int l1 = m - ask(l,m) + ask(l,m-1);
        int r1 = m + ask(m,r) - ask(m+1,r);
        int l0 = l1 - 1 - ask(0, l1-1) + ask(0,l1-2);
        if(l0 < l1-1) {
            printf("! %d %d %d\n", l0+1, l1+1, r1+1);
            fflush(stdout);
            continue;
        }
        else {
            int r2 = r1 + 1 + ask(r1+1,n-1) - ask(r1+2,n-1);
            printf("! %d %d %d\n", l1+1, r1+2, r2+1);
            fflush(stdout);
            continue;
        }
    }
    
    
}