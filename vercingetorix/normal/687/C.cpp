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
    forn(i,0,n) scanf("%d", &a[i]);
    vvvi d(1, vvi(k+1, vi(k+1,0)));
    d[0][0][0] = 1;
    forn(m,0,n) {
        for(int sum = k-a[m]; sum>=0; sum--) {
            for(int i = 0; i<=sum; i++) {
                int j = sum - i;
                if(d[0][i][j]) {
                    d[0][i+a[m]][j] = 1;
                    d[0][i][j+a[m]] = 1;
                    d[0][i][j] = 1;
                }
            }
        }
    }
    vi ans;
    forn(i,0,k+1) {
        int j = k-i;
        if(d[0][i][j]) ans.pb(i);
    }
    printf("%d\n", ans.size());
    for(auto u : ans) printf("%d ", u);
}