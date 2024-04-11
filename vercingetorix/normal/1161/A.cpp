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
    int n,k;
    scanf("%d %d", &n, &k);
    readv(a,k);
//    vi cnt(n,0);
//    for(auto x : a) cnt[x-1]++;
    forn(i,0,k) a[i] --;
    vi last(n, -1);
    vi f(n, -1);
    forn(i,0,k) {
        if(f[a[i]] == -1) f[a[i]] = i;
        last[a[i]] = i;
    }
    ll ans = 0;
    forn(i,0,n) {
        if(f[i] == -1) ans += 1;
        if(i>0) {
            if(last[i-1] < f[i] || f[i] == -1 || f[i-1] == -1) ans++;
//            int fr = -1;
//            if(last[i-1] != -1) fr = last[i-1];
//            int to = k-1;
//            if(f[i] != -1) to = f[i] - 1;
//            ans += to-fr+1;
        }
        if(i<n-1) {
            if(last[i+1] < f[i]|| f[i] == -1 || f[i+1] == -1) ans++;
//            int fr = -1;
//            if(last[i+1] != -1) fr = last[i+1];
//            int to = k-1;
//            if(f[i] != -1) to = f[i] - 1;
//            ans += to-fr+1;
        }
    }
    cout<<ans;
    
    
}