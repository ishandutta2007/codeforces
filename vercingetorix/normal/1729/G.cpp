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
const int INF = 1e9;
pll d[1000];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        string s,t;
        cin>>s>>t;
        int n= s.size();
        int m = t.size();
        vi bad(n,0);
        forn(i,0,n) if(i + m - 1 < n && s.substr(i,m) == t) bad[i] = 1;
        forn(i,0,n+1) d[i] = mp(INF, 0);
        d[0] = mp(0, 1);
        pll ans = mp(INF, 0);
        forn(r,0,n+1) {
            int nx = -1;
            forn(l,r,n) if(bad[l]) {
                nx = l;
                break;
            }
            if(nx == -1) {
                if(ans.first > d[r].first) ans = d[r];
                else if(ans.first == d[r].first) ans.second = (ans.second + d[r].second)%mod;
                continue;
            }
            forn(tk,nx,nx+m) if(bad[tk]){
                int num = d[r].first+1;
                ll w = d[r].second;
//                printf("%d to  %d\n", r, tk+m);
                if(d[tk+m].first > num) d[tk+m] = mp(num, w);
                else if(d[tk+m].first == num) d[tk+m].second = (d[tk+m].second + w)%mod;
            }
        }
//        forn(i,1,ans.first + 1) ans.second = ans.second * i%mod;
        printf("%lld %lld\n", ans.first, ans.second);
    }
    
    
}