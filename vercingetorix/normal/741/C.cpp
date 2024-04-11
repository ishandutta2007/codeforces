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
    vi ans(2*n, -1);
    vvi pr(n);
    vi w(2*n);
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        w[i] = x/2;
        w[2*n-1-i] = y/2;
        pr[x/2].pb(i);
        pr[y/2].pb(2*n-1-i);
    }
    forn(i,0,n) {
        if(ans[pr[i][0]] != -1) continue;
        ans[pr[i][0]] = 1;
        ans[2*n-1-pr[i][0]] = 2;
        int cur = w[2*n-1-pr[i][0]];
        while(1) {
            if(ans[pr[cur][0]] != -1 && ans[pr[cur][1]] != -1) break;
            int ind = pr[cur][1];
            if(ans[pr[cur][0]] == -1) ind = pr[cur][0];
            ans[ind] = 1;
            ans[2*n-1-ind] = 2;
            cur = w[2*n-1-ind];
        }
    }
    forn(i,0,n) {
        printf("%d %d\n", ans[i], ans[2*n-1-i]);
    }
    
}