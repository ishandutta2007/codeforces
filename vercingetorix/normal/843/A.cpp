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
    int n;
    scanf("%d", &n);
    vi a(n);
    vpi ord;
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) ord.pb(mp(a[i],i));
    sort(all(ord));
    vi to(n);
    forn(i,0,n) to[ord[i].second] = i;
    vi vis(n,0);
    vvi ans;
    forn(i,0,n) {
        if(!vis[i]) {
            ans.pb(vi());
            int cur = i;
            while(1) {
                cur = to[cur];
                vis[cur] = 1;
                ans.back().pb(cur+1);
                if(cur == i) break;
            }
        }
    }
    printf("%d\n", ans.size());
    for(auto x : ans) {
        printf("%d", x.size());
        for(auto y:x) printf(" %d", y);
        printf("\n");
    }
}