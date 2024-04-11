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
    vi a(n);
    forn(i,0,n) cin>>a[i];
//    set<pi> u;
//    u.insert(mp(1000000001, n));
//    forn(i,0,n) cin>>a[i];
//    vi nxm(n, n);
//    for(int i = n-1; i >=0; i--) {
//        nxm[i] = u.lower_bound(mp(a[i], 0)) -> second;
//        u.insert(mp(a[i],i));
//    }
//    int ans = 0;
//    vi m(n,1);
//    forn(i,0,n) {
//        if(nxm[i] < n) {
//            m[nxm[i]] = max(m[nxm[i]], m[a[i]])
//        }
//    }
//    int MAXN = 100041;
//    const int INF = 1000000010;
//    vi d(n+2,0);
//    d[0] = -INF;
//    for (int i=1; i<=n+1; ++i)
//        d[i] = INF;
//    int ans = 0;
//    for (int i=0; i<n; i++) {
//        int j = int (upper_bound (d.begin(), d.end(), a[i]) - d.begin());
//        if (d[j-1] < a[i] && a[i] < d[j])
//            d[j] = a[i];
//    }
//    forn(i,0,n+1) if(d[i]<INF) ans = i;
//    cout<<ans;
    int cur =1;
    int ans = 1;
    forn(i,1,n) {
        if(a[i] > a[i-1]) {
            cur++;
        }
    
        else cur = 1;
        ans = max(ans,cur);
    }
    cout<<ans;
    
    
}