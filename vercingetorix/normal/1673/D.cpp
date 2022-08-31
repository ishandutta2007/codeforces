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
        ll b,q,y,c,r,z;
        cin>>b>>q>>y>>c>>r>>z;
        ll b2 = b + q*(y-1);
        ll c2 = c + r*(z-1);
        if(c<b || c2>b2 || r%q != 0 || (c-b)%q!=0) {
            printf("0\n");
        }
        else if(c2 + r > b2 || c - r < b) printf("-1\n");
        else {
            ll ans = 0;
            for(ll l =1; l*l<=r; l++) if(r%l == 0) {
                vll cl(1,l);
                if(l*l!=r) cl.pb(r/l);
                for(auto d : cl) {
                    if(d*q/gcd(d,q) == r) {
                        ans = (ans + r*r/(d*d))%mod;
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    
    
}