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
    int m,a,b;
    scanf("%d %d %d", &m, &a, &b);
    vi mx(a+b,-1);
    int cur = 0;
    int curm = 0;
    mx[0] = -1;
    while(mx[cur] == -1) {
        mx[cur] = curm;
        if(cur >= b) cur-=b;
        else cur+=a;
        curm = max(curm, cur);
    }
    ll ans = 0;
    if(m < a+b) {
        forn(i,0,m+1) if(mx[i] != -1) ans += max(0, m-mx[i]+1);
        cout<<ans;
    }
    else {
        forn(i,0,a+b) if(mx[i] != -1) ans += max(0, m-mx[i]+1);
        int d = gcd(a,b);
        int l = (a+b)/d;
        int r = m/d;
        ans += ll(m+1)*(r-l+1) - d*ll(r+l)*(r-l+1)/2;
        cout<<ans;
    }
    
}