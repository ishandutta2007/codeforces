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
        read(n);
        readv(a,n);
        int ans = 1e9;
        forn(n1,0,2) forn(n2,0,3) {
            if(n1*(n2-1)> 0) continue;
            int n3 = 0;
            forn(i,0,n) {
                if(a[i] == 1 && n1 == 0) n3 = 1e9;
                if(a[i]%3 == 0) {
                    if(n1*n2) n3 = max(n3, a[i]/3-1);
                    else n3 = max(n3,a[i]/3);
                }
                else if(a[i]%3 == 1) {
                    if(n2==2) n3 = max(n3, a[i]/3-1);
                    else if(n1 == 1) n3 = max(n3,a[i]/3);
                    else n3 = 1e9;
                }
                else if(a[i]%3 == 2) {
                    if(n2==0) n3 = 1e9;
                    else n3 = max(n3, a[i]/3);
                }
//                if(a[i] % 3 == 1) n1 = 1;
//                if(a[i]%3 == 2) n2 = 1;
            }
            ans = min(ans, n3 +n1+n2);
        }
        printf("%d\n", ans);
    }
    
    
}