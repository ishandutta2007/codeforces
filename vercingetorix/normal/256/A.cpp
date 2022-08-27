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
const int A = 1000001;
int cnt[A];
int up[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(b,n);
    set<int> u;
    for(auto x : b) u.insert(x);
    int ans = 1;
    for(auto s : u) {
        vi pos;
        forn(i,0,n) if(b[i] == s) pos.pb(i);
        int k = pos.size();
        ans = max(ans, k);
        pos.pb(n);
        for(auto x: b) cnt[x] = 0;
        forn(i,0,k) {
            int f = pos[i];
            int e = pos[i+1];
            forn(j,f+1, e) {
                if(up[b[j]] == 0) {
                    up[b[j]] = 1;
                    cnt[b[j]]++;
                    ans = max(ans, 2*cnt[b[j]]);
                    if(i != k-1) ans = max(ans, 2*cnt[b[j]] + 1);
                }
            }
            forn(j,f+1,e) up[b[j]] = 0;
        }
    }
    cout<<ans;
    
    
}