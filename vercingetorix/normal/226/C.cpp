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

//const long long mod = 1000000007;
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
//const ll mod = 5; /** exclude-line */
ll mod;
typedef vector<ll> Poly;
ll linearRec(Poly S, Poly tr, ll k) {
    int n = tr.size();
    
    auto combine = [&](Poly a, Poly b) {
        Poly res(n * 2 + 1);
        forn(i,0,n+1) forn(j,0,n+1)
        res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
        for (int i = 2 * n; i > n; --i) forn(j,0,n)
            res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % mod;
        res.resize(n + 1);
        return res;
    };
    
    Poly pol(n + 1), e(pol);
    pol[0] = e[1] = 1;
    
    for (++k; k; k /= 2) {
        if (k % 2) pol = combine(pol, e);
        e = combine(e, e);
    }
    
    ll res = 0;
    forn(i,0,n) res = (res + pol[i + 1] * S[i]) % mod;
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll l,r,k;
    cin>>mod>>l>>r>>k;
    const int A = 1000400;
    ll best = 1;
    forn(a,1,A) {
        ll mb = r/(a+k-1);
        if(a*mb >= l) best = max(best, mb);
    }
    forn(b,1,A) {
        if(r/b-(l-1)/b >= k) best = max(best, (ll)b);
    }
    cout<<linearRec({0, 1}, {1, 1}, best);
    
    
    
}