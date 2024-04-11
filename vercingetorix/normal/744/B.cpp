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
    vi ans(n, 1000000000);
    vi d2(1,1);
    forn(i,0,10) d2.pb(d2.back()*2);
    forn(i,0,10) {
        forn(j,0,2) {
            vi req;
            forn(k,0,n) {
                int bit = (k&d2[i]) / d2[i];
                if(bit == j) req.pb(k+1);
            }
            int l = req.size();
            if(l == 0) continue;
            printf("%d\n", req.size());
            forn(k,0,l-1) {
                printf("%d ", req[k]);
            }
            printf("%d\n", req[l-1]);
            fflush(stdout);
            vi ret(n);
            forn(k,0,n) {
                scanf("%d", &ret[k]);
                int bit = (k&d2[i]) / d2[i];
                if(bit != j) ans[k] = min(ans[k], ret[k]);
            }
        }
    }
    printf("-1\n");
    forn(i,0,n-1) printf("%d ", ans[i]);
    printf("%d\n", ans[n-1]);
    fflush(stdout);
    
}