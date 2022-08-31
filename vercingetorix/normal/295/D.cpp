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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
const int A = 2000;
ll kill[A+1][A+1];
ll killd[A+1][A+1];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    cin>>n>>m;
    forn(i,0,A+1) kill[i][0] = 1;
    kill[1][0] = 0;
    forn(k,1,A+1) {
        ll ch = 0;
        ll cur = 0;
        forn(n,1,A+1) {
            ch += kill[n][k-1];
            cur += ch;
            if(n>1) kill[n][k] = (1+cur) % mod;
        }
    }
    forn(n,1,A+1) killd[n][0] = 1;
    forn(k,1,A+1) forn(n,1,A+1) {
        killd[n][k] = (kill[n][k] - kill[n][k-1] + mod) % mod;
    }
    ll ans = 0;
    forn(s,0,n) {
        forn(l,2,m+1) {
            ans = (ans + (m+1-l)*((killd[l][s] * kill[l][n-s-1])%mod))%mod;
        }
    }
    cout<<ans;
    
    
}