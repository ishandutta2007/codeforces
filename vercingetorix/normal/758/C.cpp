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
    ll n,m,x,y;
    ll k;
    cin>>n>>m>>k>>x>>y;
    ll c = m*n;
    x--;
    y--;
    if(n>1) c += m*(n-2);
    vvll cnt(n, vll(m,0));
    forn(i,0,n)forn(j,0,m) {
        if(i==0 || i==n-1) cnt[i][j] = k/c;
        else cnt[i][j] = 2*(k/c);
    }
    k%=c;
    forn(i,0,min(k, m*n)) {
        cnt[i/m][i%m]++;
    }
    if(k>m*n) {
        forn(i,0,k-m*n) {
            cnt[n-2 - (i/m)][i%m]++;
        }
    }
    
    ll mx = 0;
    ll mn = 2e18;
    forn(i,0,n) forn(j,0,m) {
        mx = max(mx, cnt[i][j]);
        mn = min(mn, cnt[i][j]);
    }
    cout << mx <<' '<<mn<<' '<<cnt[x][y];
    
    
}