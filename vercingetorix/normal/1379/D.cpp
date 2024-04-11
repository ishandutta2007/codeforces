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
    int n,h,m,k;
    scanf("%d %d %d %d", &n, &h, &m, &k);
    vpi mt;
    forn(i,0,n) {
        int a,b;
        scanf("%d %d", &a,&b);
        mt.pb(mp(b%(m/2), i+1));
    }
    sort(all(mt));
    forn(i,0,n) {
        mt.pb(mp(mt[i].first + m/2, mt[i].second));
    }
    int ans = n+1;
    int best = 0;
    forn(i,0,n) {
        auto it = lower_bound(mt.begin(), mt.end(), mp(mt[i].first + k, 0));
        if ((it - mt.begin()) - i - 1 < ans) {
            ans = (it - mt.begin()) - i - 1;
            best = i;
        }
    }
//    auto it = lower_bound(mt.begin(), mt.end(), mp(mt[best].first + k, 0));
    printf("%d %d\n", ans, (mt[best].first + k) % (m/2));
    forn(i,1,ans+1) {
        if(i>0) printf(" ");
        printf("%d", mt[best + i].second);
    }
    printf("\n");
}