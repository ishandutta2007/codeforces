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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    if(n%2 == 1) {
        printf("Second\n");
        fflush(stdout);
        vi a(2*n+1);
        forn(i,1,2*n+1) scanf("%d", &a[i]);
        vvi pr(n+1);
        forn(i,1,2*n+1) pr[a[i]].pb(i);
        vi to(2*n+1,0);
        forn(i,1,n+1) {
            to[pr[i][0]] = pr[i][1];
            to[pr[i][1]] = pr[i][0];
        }
        vi take(2*n+1,0);
        forn(i,1,n+1) {
            if(take[i] == 0 && take[i+n] == 0) {
                take[i] = 1;
                int cur = to[i];
                while(cur != i+n) {
                    cur = (cur + n-1) %(2*n) + 1;
                    take[cur] = 1;
                    cur = to[cur];
                }
                
            }
        }
        int sum = 0;
        forn(i,1,2*n+1) if(take[i]) sum = (sum+i)%(2*n);
        if(sum != 0) forn(i,1,2*n+1) take[i] = 1-take[i];
        forn(i,1,2*n+1) if(take[i]) printf("%d ", i);
        printf("\n");
    }
    else {
        int d2 = 1;
        vi ans(2*n, 0);
        while(n%2 == 0) {
            n/=2;
            d2*=2;
        }
        int pt = 1;
        for(int base = 0; base < n; base++) {
            forn(r,0,d2) {
                ans[base * d2 * 2 + r] = pt;
                ans[base * d2 * 2 + r + d2] = pt++;
            }
        }
        printf("First\n");
        forn(i,0,2*d2*n) {
            printf("%d", ans[i]);
            if(i!=2*d2*n-1) printf(" ");
        }
        printf("\n");
    }
    
}