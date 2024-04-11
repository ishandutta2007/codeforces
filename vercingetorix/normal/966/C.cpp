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
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    vvll old(60);
    forn(i,0,n) {
        for(int bit = 59; bit>=0; bit--) {
            if(a[i] & (1ll<<bit)) {
                old[bit].pb(a[i]);
                break;
            }
        }
    }
    vll cur;
    for(int bit = 59; bit >= 0; bit--) {
        ll d2 = 1ll<<bit;
        vll ncur;
        int pt = 0;
        int flag = 1;
        for(auto x : cur) {
            if(pt != old[bit].size() && flag) {
                ncur.pb(old[bit][pt++]);
                flag ^= 1;
            }
            ncur.pb(x);
            if(x & d2) flag^=1;
        }
        if(pt != old[bit].size() && flag) {
            ncur.pb(old[bit][pt++]);
            flag ^= 1;
        }
        if(pt != old[bit].size()) {
            cout<<"No";
            exit(0);
        }
        swap(cur, ncur);
    }
    printf("Yes\n");
    for(auto x : cur) printf("%lld ", x);
    
}