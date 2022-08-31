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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    vi r(n);
    vll sum(n);
    r[n-1] = n-1;
    sum[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--) {
        int curr = i;
        ll cursum = a[i];
        while(curr < n-1) {
            int candr = r[curr+1];
            ll candsum = cursum + sum[curr+1];
            if(candsum * (curr-i+1)  <= cursum * (candr - i+ 1)) {
                curr = candr;
                cursum = candsum;
            }
            else break;
        }
        r[i] = curr;
        sum[i] = cursum;
    }
    int pt = 0;
    vd ans;
    while(pt < n) {
        int pr = r[pt];
        forn(i,0,pr-pt+1) ans.pb(double(sum[pt]) / (pr-pt+1));
        pt = pr+1;
    }
    forn(i,0,n) printf("%.15lf\n", ans[i]);
    
    
}