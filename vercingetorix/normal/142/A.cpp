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

int divs[10000];
int getdiv(int n, int l) {
    if(n == 1) return 1;
    while(l*l <= n) {
        if(n%l == 0) {
            int p = l;
            int deg = 1;
            n/=p;
            while(n%p == 0) {
                deg++;
                n/=p;
            }
            int k = getdiv(n, l+1);
            int dp = p;
            int cur = k;
            forn(it,0,deg) {
                forn(i,0,k) divs[cur++] = divs[i]*dp;
                dp*=p;
            }
            return cur;
        }
        l++;
    }
    divs[0] = 1;
    divs[1] = n;
    return 2;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    divs[0] = 1;
    int k = getdiv(n, 2);
    
    sort(divs, divs+k);
    ll mn = 1e18;
    ll mx = 0;
    forn(i,0,k) forn(j,0,i+1) {
        if(divs[i]%divs[j] == 0) {
            ll a = divs[i]/divs[j];
            ll b = divs[j];
            ll c = n/divs[i];
            ll cur = (a+1)*(b+2)*(c+2) - n;
            mn = min(mn, cur);
            mx = max(mx, cur);
        }
    }
    cout<<mn<<' '<<mx;
    
}