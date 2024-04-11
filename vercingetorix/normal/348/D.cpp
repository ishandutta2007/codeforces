#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <cassert>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
ll d1[3010][3010];
ll d2[3010][3010];
char a[3010][3010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n, &m);
//    vs a(n);
    
    forn(i,0,n) {
        char c;
//        a[i].resize(m);
//        forn(j,0,m) {
//            char * s;
            gets(a[i]);
//            scanf("%c", &a[i][j]);
//        }
//        scanf("\n");
//        getline(cin, a[i]);
    }
    if(a[1][0]=='#' || a[0][1]=='#' || a[n-2][m-1]=='#' || a[n-1][m-2]=='#') {
        cout<<0;
        return 0;
    }
//    vvll d1(n+1, vll(m+1,0));
//    vvll d2(n+1, vll(m+1,0));
    
    
    d1[1][0] = 1;
    d2[0][1] = 1;
//    forn(i,0,n-1) forn(j,0,m-1) {
    for(int sum = 2; sum <=n+m-3; sum++)
    for(int i = max(0, sum - m+1); i <= min(n-1, sum); i++) {
        int j= sum-i;
        if(a[i][j] == '#') continue;
        if(i>0) {
            d1[i][j] += d1[i-1][j];
            d2[i][j] += d2[i-1][j];
        }
        if(j>0) {
            d1[i][j] += d1[i][j-1];
            d2[i][j] += d2[i][j-1];
        }
//        if(d1[i][j] >= mod) d1[i][j]-=mod;
//        if(d2[i][j] >= mod) d2[i][j]-=mod;
        if(sum%30==0) {
            d1[i][j] = d1[i][j]%mod;
            d2[i][j] = d2[i][j]%mod;
        }
    }
    ll p1 = d1[n-1][m-2]%mod;
    ll p2 = d2[n-2][m-1]%mod;
    ll q1 = d1[n-2][m-1]%mod;
    ll q2 = d2[n-1][m-2]%mod;
    ll ans = (mod + p1*p2%mod - q1*q2%mod) % mod;
    
    cout<<ans;
}