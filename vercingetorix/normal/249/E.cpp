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
typedef __int128 lll;
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

const ll mod = 10000000000;

lll ss(lll x) {
    return x*(x+1)*(2*x+1)/6;
}

lll s1(lll x) {
    return x*(x+1)/2;
}

lll get(int x, int y) {
    if(x==0 || y==0) return 0;
    ll k = min(x,y);
    lll ret = s1(k*k);
    if(y>x) ret += (ss(y-1) - ss(x-1))*x + s1(x)*(y-x);
    else if(x>y) ret += (ss(x) - ss(y))*y - s1(y-1)*(x-y);
    return ret;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        auto res = get(x2,y2) - get(x1-1,y2) - get(x2,y1-1) + get(x1-1,y1-1);
        if(res >= mod) {
            string ans = to_string(ll(res%mod));
            ans = string(10-ans.size(), '0') + ans;
            printf("...");
            printf("%s\n", ans.c_str());
        }
        else printf("%lld\n", (ll)res);
    }
    
    
}