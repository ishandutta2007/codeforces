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
const int A = 1000400;
int has[20*A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    cin>>n>>m;
    
    vi root(A, 0);
    vi rlog(A);
    forn(k,2,A) if(root[k] == 0) {
        ll dk = k;
        int deg = 1;
        while(dk < A) {
            root[dk] = k;
            rlog[dk] = deg;
            deg++;
            dk *= k;
        }
    }
    vi ans(20,0);
    int cur = 0;
    forn(l,1,20) {
        forn(i,1,m+1) {
            if(has[l*i] == 0) {
                cur++;
                has[l*i] = 1;
            }
        }
        ans[l] = cur;
    }
    ll res = 1;
    vi mx(n+1,0);
    forn(i,2,n+1) mx[root[i]] = rlog[i];
    forn(i,2,n+1) res += ans[mx[i]];
    cout<<res;
    
}