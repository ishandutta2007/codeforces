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
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    sort(all(a));
    vi md(1000001, 0);
    forn(i,0,n) {
        if(i==0 || a[i]>a[i-1]) {
            int cur = a[i];
            while(cur<=1000001) {
                md[cur] = a[i];
                cur+=a[i];
            }
        }
    }
    int ans = 0;
    forn(base, 1, 1000001) {
        if(md[base]==0) continue;
        auto x = --lower_bound(all(a), base + md[base]);
        ans = max(ans, (*x) - base);
    }
    cout<<ans;
    
}