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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k,p;
    scanf("%d %d %d", &n, &k, &p);
    vi a(n);
    vi b(k);
    forn(i,0,n) {
        scanf("%d", &a[i]);
    }
    forn(i,0,k) {
        scanf("%d", &b[i]);
    }
    sort(all(a));
    sort(all(b));
    ll ans = 1e18;
    forn(s,0,k-n+1) {
        ll cand = 0;
        forn(i,0,n) cand=max(cand,(ll)abs(a[i]-b[i+s]) + (ll)abs(b[i+s]-p));
        ans = min(ans, cand);
    }
    cout<<ans;
    
    
}