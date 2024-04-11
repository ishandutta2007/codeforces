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
    string s;
    cin>>s;
    int n = s.size();
    vvi dr(n+1, vi(n+1,0));
    dr[n][0] = 1;
    for(int i = n-1; i>=0; i--) {
        if(s[i] == '(') dr[i] = dr[i+1];
        else if(s[i] == ')') {
            forn(j,0,n) dr[i][j+1] = dr[i+1][j];
        }
        else {
            forn(j,0,n) dr[i][j+1] =(dr[i+1][j+1] +dr[i+1][j])%mod;
            dr[i][0] = dr[i+1][0];
        }
    }
    vvi dl(n+1, vi(n+1,0));
    dl[0][0]=1;
    forn(i,0,n-1) {
        if(s[i] == ')') dl[i+1] = dl[i];
        else if(s[i] == '(') {
            forn(j,0,n) dl[i+1][j+1] = dl[i][j];
        }
        else {
            forn(j,0,n) dl[i+1][j+1] =(dl[i][j+1] +dl[i][j])%mod;
            dl[i+1][0] = dl[i][0];
        }
    }
    vvi dlinc(n+1, vi(n+1,0));
//    dl[0][0] = 1;
    for(int i = 0; i<n; i++) {
        if(s[i] == ')') continue;
        else {
            forn(j,0,n) dlinc[i+1][j+1] = dl[i][j];
//            forn(j,0,n) dl[i+1][j+1] = dl[i][j];
        }
    }
    ll ans = 0;
    forn(i,0,n+1) {
        for(int k=n; k>=1; k--) {
            dr[i][k-1] =(dr[i][k-1]+dr[i][k]) % mod;
        }
    }
    forn(l,0,n-1) forn(k,1,n) ans = (ans + ll(dlinc[l+1][k])*ll(dr[l+1][k]))%mod;
    cout<<ans;
    
}