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
const int A = 10000001;
int best[A][2];
const int N = A;
int divs[1000];
vi mindiv(N+1, 0);
vector<ll> pr;
vi isp(N+1, 0);

int getdiv(int n) {
    if(n == 1) return 1;
    int p = mindiv[n];
    int deg = 1;
    n/=p;
    while(n%p == 0) {
        deg++;
        n/=p;
    }
    int k = getdiv(n);
    int dp = p;
    int cur = k;
    forn(it,0,deg) {
        forn(i,0,k) divs[cur++] = divs[i]*dp;
        dp*=p;
    }
    return cur;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    divs[0] = 1;
    forn(i,0,A) {
        best[i][0] = A;
        best[i][1] = A;
    }
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int n;
    read(n);
    readv(a,n);
    for(auto x : a) {
        int k = getdiv(x);
        forn(i,0,k) {
            int d = divs[i];
            if(best[d][0] >= x) {
                best[d][1] = best[d][0];
                best[d][0] = x;
            }
            else if(best[d][1] >= x) {
                best[d][1] = x;
            }
        }
    }
    ll ans = 1e18;
    pll b;
    forn(d,1,A) {
        if(best[d][1] < A) {
            if(ans > ll(best[d][1])/d*best[d][0]) {
                ans = ll(best[d][1])/d*best[d][0];
                b = mp(best[d][1], best[d][0]);
            }
        }
    }
    int i = 0, j= 0;
    while(a[i] != b.first) i++;
    while(a[j] != b.second || i == j) j++;
    if(i>j) swap(i,j);
    printf("%d %d", i+1, j+1);
//    cout<<ans;
    
    
    
}