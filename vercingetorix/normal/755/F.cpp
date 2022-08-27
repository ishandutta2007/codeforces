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
    int n,k;
    scanf("%d %d", &n, &k);
    vi a(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    vi cycles;
    vi used(n,0);
    forn(i,0,n) {
        if(used[i]) continue;
        int cur = i;
        int len = 0;
        while(1) {
            len++;
            cur = a[cur];
            used[cur] = 1;
            if(cur == i) break;
        }
        cycles.pb(len);
    }
//    for(auto x:cycles) cout<<x<<' ';
    int db = 0;
    for(auto x:cycles) db+=x/2;
    int mx = k+min(db,k);
    if(mx>n) mx = n;
    sort(all(cycles));
    int T = 200;
    vi d(k+1,0);
    d[0] = 1;
    while(!cycles.empty() && cycles.back() >= T) {
        int s = cycles.back();
        cycles.pop_back();
        for(int i = k; i>=s; i--) d[i] |= d[i-s];
    }
    int pt = 0;
    while(pt<cycles.size()) {
        int pr = pt+1;
        while(pr<cycles.size() && cycles[pr] == cycles[pt]) pr++;
        int s = cycles[pt];
        int cnt = pr-pt;
        pt = pr;
        vi nd(k+1,0);
        forn(i,0,k+1) {
            if(d[i]) nd[i] = 0;
            else if(i<s) nd[i] = cnt+1;
            else nd[i] = 1+nd[i-s];
            if(nd[i] <= cnt) d[i] = 1;
        }
    }
    if(d[k]) cout<<k<<' '<<mx;
    else cout<<k+1<<' '<<mx;
    
}