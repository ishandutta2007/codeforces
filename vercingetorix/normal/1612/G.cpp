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
const int A = 1000001;
ll nfac[A];
int cnt[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    int m;
    scanf("%d", &m);
    readv(c,m);
    for(auto x : c) cnt[x]++;
    ll len = 0;
    for(auto x : c) len+=x;
    ll ans = 1;
    ll sum = 0;
    for(int i = A-1; i>=1; i--) {
        if(i >= 2){
            ans = ans*nfac[cnt[i]]%mod*nfac[cnt[i]]%mod;
            cnt[i-2] += cnt[i];
            sum += (len-cnt[i])%mod*cnt[i]%mod*(i-2)%mod + (len-cnt[i])%mod*cnt[i]%mod;
            len -= 2*cnt[i];
        }
        else ans = ans*nfac[cnt[i]]%mod;
        
    }
    cout<<sum%mod<<' '<<ans;
    
    
}