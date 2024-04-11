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

//const long long mod = 1000000007;
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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

const int A = 51;
vvll kinv(A+1, vll(A*A,0));
vvll kpadv(A+1, vll(A+1, 0));

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,mod;
    cin>>n>>mod;
    vll nfac(1,1);
    forn(i,1,n+1) nfac.pb(nfac.back()*i%mod);
    
    kinv[1][0] = 1;
    forn(k,2,A+1) {
        forn(f,0,k) {
            forn(was,0,A*A-k) {
                kinv[k][f+was] = (kinv[k-1][was] + kinv[k][f+was]) % mod;
            }
        }
    }
    forn(k,1,A+1) {
        int mx = k*(k-1)/2;
        vll sl(mx+1, 0);
        forn(i,0,mx+1) {
            sl[i] = kinv[k][i];
            if(i>0) sl[i] = (sl[i-1] + sl[i]) % mod;
        }
        forn(adv,0,min(mx+1, k+2)) {
            forn(j,adv,mx+1) kpadv[k][adv] += (sl[j-adv] * kinv[k][j]) % mod;
            kpadv[k][adv] %= mod;
        }
    }
    vll ans(n+1, 0);
    forn(k,4,n+1) {
        ans[k] = ans[k-1]*k % mod;
        forn(gap,1,k) {
            ll cnt = k - gap;
            ans[k] = (ans[k] +  kpadv[k-1][gap + 1] * cnt) % mod;
        }
    }
    cout<<ans[n];
    
}