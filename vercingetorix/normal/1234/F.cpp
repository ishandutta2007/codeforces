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

int d[1<<20];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[1000500];
    scanf("%s", c);
    string s(c);
    int n = s.size();
    forn(l,0,n) {
        int cur = 0;
        int r = l;
        while(r<n && !((1<<(s[r]-'a'))&cur)) {
            cur |= 1<<(s[r++]-'a');
            d[cur] = 1;
        }
    }
    forn(i,0,1<<20) if(d[i]) d[i] = __builtin_popcount(i);
    forn(mask,1,1<<20) {
        forn(bit,0,20) if(mask&(1<<bit)) d[mask] = max(d[mask], d[mask^(1<<bit)]);
    }
    int rev = (1<<20)-1;
    int ans = 0;
    forn(mask,0,1<<20) {
        ans = max(d[mask]+d[mask^rev], ans);
    }
    cout<<ans;
    
    
    
}