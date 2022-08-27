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

const long long mod = 998244353;
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
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d %d", &n, &k);
        readv(a,n);
        readv(b,k);
        vi sd(n,-1);
        vi sdbn(n+1, -1);
        forn(i,0,k) sdbn[b[i]] = i;
        forn(i,0,n) if(sdbn[a[i]] != -1) sd[i] = sdbn[a[i]];
        ll ans = 1;
        forn(i,0,n){
            if(sd[i] == -1) continue;
            ll var = 0;
            if(i>0) {
                if(sd[i-1] == -1 || sd[i-1] < sd[i]) var++;
            }
            if(i<n-1) {
                if(sd[i+1] == -1 || sd[i+1] < sd[i]) var++;
            }
            ans = ans*var%mod;
        }
        printf("%lld\n", ans);
    }
    
}