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
    char a[200500];
    char b[200500];
    forn(ifa,0,ta) {
        int n;
        scanf("%d\n", &n);
        scanf("%s", a);
        scanf("%s", b);
        vi p(n+1,0);
        vi q(n+1,0);
        p[0] = 1;
        forn(i,0,n) {
            if(a[i]-'0' <= 2 && p[i]) p[i+1] = 1;
            if(b[i]-'0' <= 2 && q[i]) q[i+1] = 1;
            if(a[i]-'0' > 2 && b[i]-'0' > 2) {
                if(p[i]) q[i+1] = 1;
                if(q[i]) p[i+1] = 1;
            }
        }
        if(q[n]) printf("YES\n");
        else printf("NO\n");
    }
    
    
}