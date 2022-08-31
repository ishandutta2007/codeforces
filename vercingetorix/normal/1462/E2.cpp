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
    int A = 200010;
    int B = 101;
    vvll cnk(B, vll(A, 0));
    forn(i,0,A) cnk[0][i] = 1;
    forn(k,1,B) {
        forn(i,k,A) {
            cnk[k][i] = (cnk[k][i-1] + cnk[k-1][i-1])%mod;
        }
    }
    int t;
    read(t);
    forn(afaf,0,t) {
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);
        readv(a,n);
        vi cnt(n,0);
        forn(i,0,n) cnt[a[i]-1]++;
        int tot = 0;
        int r = -1;
        ll ans = 0;
        forn(l,0,n) {
            while(r<n-1 && r+1<=l+k) {
                r++;
                tot += cnt[r];
            }
            ans = (ans+cnk[m][tot])%mod;
            tot -= cnt[l];
            ans = (ans + mod - cnk[m][tot]) % mod;
        }
        printf("%d\n", int(ans));
        
    }
    
    
}