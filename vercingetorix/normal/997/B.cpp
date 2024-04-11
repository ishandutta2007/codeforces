#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
    int n;
    cin>>n;
    
    if(n<=150) {
        set<int> can;
        forn(a,0,n+1) {
            forn(b,0,n-a+1) {
                forn(c,0,n-a-b+1) {
                    can.insert(4*a+9*b+49*c);
                }
            }
        }
        cout<<can.size();
    }
    else {
        vi mx(49,0);
        vi mn(49,1414);
        forn(a,0,9) forn(b,0,49) {
            mx[(a*4+b*9)%49] = max((a*4+b*9)/49+n-a-b, mx[(a*4+b*9)%49]);
            mn[(a*4+b*9)%49] = min((a*4+b*9)/49, mn[(a*4+b*9)%49]);
        }
       ll ans = 0;
       forn(i,0,49) ans += mx[i] - mn[i] + 1;
        cout<<ans;
    }
    
    
}