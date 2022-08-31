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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vvll a(3, vll(n));
    const ll INF = 1e18;
    forn(i,0,3) forn(j,0,n) scanf("%lld", &a[i][j]);
    vvll d(3,vll(n,-INF));
    d[2][n-1] = a[2][n-1];
    d[1][n-1] = a[1][n-1]+a[2][n-1];
    d[0][n-1] = a[1][n-1]+a[2][n-1]+a[0][n-1];
    for(int i = n-2; i>=0; i--) {
        d[1][i] = max(d[1][i], d[1][i+1] + a[1][i]);
        d[1][i] = max(d[1][i], d[0][i+1] + a[1][i] + a[0][i]);
        d[1][i] = max(d[1][i], d[2][i+1] + a[1][i] + a[2][i]);
        d[0][i] = max(d[0][i], d[0][i+1] + a[0][i]);
        d[0][i] = max(d[0][i], d[1][i+1] + a[0][i] + a[1][i]);
        d[0][i] = max(d[0][i], d[2][i+1] + a[0][i] + a[1][i] + a[2][i]);
        d[2][i] = max(d[2][i], d[2][i+1] + a[2][i]);
        d[2][i] = max(d[2][i], d[1][i+1] + a[2][i] + a[1][i]);
        d[2][i] = max(d[2][i], d[0][i+1] + a[0][i] + a[1][i] + a[2][i]);
        if(i<n-2) {
            d[0][i] = max(d[0][i], d[2][i+2] + a[0][i] + a[1][i] + a[2][i] + a[0][i+1] + a[1][i+1] + a[2][i+1]);
            d[2][i] = max(d[2][i], d[0][i+2] + a[0][i] + a[1][i] + a[2][i] + a[0][i+1] + a[1][i+1] + a[2][i+1]);
        }
        else {
            d[0][i] = max(d[0][i], a[0][i] + a[1][i] + a[2][i] + a[0][i+1] + a[1][i+1] + a[2][i+1]);
        }
    }
    cout<<d[0][0];
    
    
}