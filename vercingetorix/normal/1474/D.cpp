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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n;
        scanf("%d\n", &n);
        readv(a,n);
        vll z(1, a[0]);
        forn(i,1,n) {
            if(i%2 == 1) z.pb(z.back() - a[i]);
            else z.pb(z.back() + a[i]);
        }
        vll rz(n);
        rz[n-1] = a[n-1];
        forn(i,1,n) {
            if(i%2 == 1) rz[n-i-1] = rz[n-i] - a[n-i-1];
            else rz[n-i-1] = rz[n-i] + a[n-i-1];
        }
        vi lg(n,1), rg(n,1);
        forn(i,0,n) {
            if(i%2 == 0 && z[i] < 0) lg[i] = 0;
            if(i%2 == 1 && z[i] > 0) lg[i] = 0;
            if(i > 0 && lg[i-1] == 0) lg[i] = 0;
        }
        forn(i,0,n) {
            if(i%2 == 0 && rz[n-1-i] < 0) rg[n-1-i] = 0;
            if(i%2 == 1 && rz[n-1-i] > 0) rg[n-1-i] = 0;
            if(i>0 && rg[n-i] == 0) rg[n-1-i] = 0;
        }
        if(lg[n-1] == 1 && z[n-1] == 0) {
            printf("YES\n");
            continue;
        }
        int did = 0;
        forn(i,0,n-1) {
            if(i>0 && lg[i-1] == 0) continue;
            if(i<n-2 && rg[i+2] == 0) continue;
            if(i%2 == 0 && z[i] - a[i] + a[i+1] < 0) continue;
            if(i%2 == 1 && z[i] + a[i] - a[i+1] > 0) continue;
            if((n-2-i)%2 == 0 && rz[i+1] - a[i+1] + a[i] < 0) continue;
            if((n-2-i)%2 == 1 && rz[i+1] + a[i+1] - a[i] > 0) continue;
            if(i%2 == 0 && z[n-1] + 2*a[i+1] - 2*a[i] == 0) {
                printf("YES\n");
                did = 1;
                break;
            }
            if(i%2 == 1 && z[n-1] - 2*a[i+1] + 2*a[i] == 0) {
                printf("YES\n");
                did = 1;
                break;
            }
        }
        if(did == 1) continue;
        
        printf("NO\n");
    }
    
}