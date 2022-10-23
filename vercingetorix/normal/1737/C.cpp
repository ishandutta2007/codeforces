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
        scanf("%d", &n);
        vi x(4), y(4);
        forn(i,0,4) scanf("%d %d", &x[i], &y[i]);
        
        map<int, int> cx,cy;
        forn(i,0,3) {
            cx[x[i]]++;
            cy[y[i]]++;
        }
        int mx,my,ax,ay;
        for(auto u : cx) {
            if(u.second == 2) mx = u.first;
            else ax = u.first;
        }
        for(auto u : cy) {
            if(u.second == 2) my = u.first;
            else ay = u.first;
        }
        if((x[3] + y[3])%2 == (mx+my)%2 && x[3]%2 != mx%2) {
            printf("NO\n");
            continue;
        }
        if(min(mx,my) != 1 && max(mx,my) != n) {
            printf("YES\n");
            continue;
        }
        
        auto flip = [&] (int & k) {
            k = n+1-k;
        };
        if(my == n) {
            forn(i,0,4) swap(x[i],y[i]);
            swap(mx,my);
            swap(ax,ay);
        }
        if(mx == n) {
            forn(i,0,4) {
                flip(x[i]);
            }
            flip(mx);
            flip(ax);
        }
        if(my == 1) {
            forn(i,0,4) swap(x[i],y[i]);
            swap(mx,my);
            swap(ax,ay);
        }
        // mx == 1
        if(my != 1 && my != n) {
            printf("YES\n");
            continue;
        }
        if(my == n) {
            forn(i,0,4) {
                flip(y[i]);
            }
            flip(my);
            flip(ay);
        }
        if(x[3] == 1 || y[3] == 1) printf("YES\n");
        else printf("NO\n");
    }
    
    
}