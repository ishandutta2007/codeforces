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
vi a[1000000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,n) {
        int k;
        scanf("%d", &k);
        forn(j,0,k) {
            int x;
            scanf("%d", &x);
            x--;
            a[x].pb(i);
        }
    }
    forn(i,0,m) {
        sort(all(a[i]));
    }
    sort(a, a+m);
    int p = 0;
    ll ans = 1;
    while(p < m) {
        int pr = p+1;
        while(pr<m && a[pr]==a[p]) {
            pr++;
        }
        forn(i,1,pr-p+1) {
            ans = (ans*(ll)i)%mod;
        }
        p = pr;
    }
    cout<<ans;
}