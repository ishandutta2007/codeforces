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
        int n;
        scanf("%d", &n);
        readv(p,n);
        vi w(n+1);
        forn(i,0,n) w[p[i]] = i;
        w[n] = n;
        int l = n;
        int r = -1;
        ll ans = 0;
        forn(mx,0,n) {
            l = min(l, w[mx]);
            r = max(r, w[mx]);
            if(w[mx+1] >= l && w[mx+1] <= r) continue;
            int bl = -1;
            if(w[mx+1] < l) bl = w[mx+1];
            int br = n;
            if(w[mx+1] > r) br = w[mx+1];
            int tol = l-bl-1;
            int tor = br-r-1;
            int cantake = 2*(mx+1) - (r-l+1);
            int f = min(tol,tor);
            int s = max(tol,tor);
            int fin = tol + tor;
            ll r = min(cantake, f);
            if(r >= 0) ans += (r+1)*(r+2)/2;
            r = min(cantake, s);
            if(r > f) ans += (r-f)*(f+1);
            r = min(cantake, fin);
            if(r>s) ans += (r-s)*(fin+1) - (r+s+1)*(r-s)/2;
        }
        cout<<ans<<'\n';
    }
    
    
}