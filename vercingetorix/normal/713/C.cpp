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
    cin>>n;
    vll a(n);
    forn(i,0,n) cin>>a[i];
    forn(i,0,n) a[i]-=i;
    vll b = a;
    sort(all(b));
    vvll d(n, vll(n,0));
    forn(i,0,n) d[0][i] = abs(a[0]-b[i]);
    forn(i,1,n) {
        vll ch(n);
        ch[0] = d[i-1][0];
        forn(j,1,n) ch[j] = min(ch[j-1], d[i-1][j]);
        forn(j,0,n) {
            d[i][j] = abs(a[i]-b[j]) + ch[j];
        }
    }
    ll ans = d[n-1][0];
    forn(i,0,n) ans = min(ans, d[n-1][i]);
    cout<<ans;
    
    
}