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
    int n,c,d;
    scanf("%d %d %d", &n, &c, &d);
    int A = 100000;
    vvi bc(A+1);
    vvi dc(A+1);
    forn(i,0,n) {
        int b,p;
        char c;
        scanf("%d %d %c", &b, &p, &c);
        if(c=='C') {
//            bc[p] = max(bc[p], b);
            bc[p].pb(b);
        }
        else {
//            dc[p] = max(dc[p], b);
            dc[p].pb(b);
        }
    }
    forn(i,0,A) {
        for(auto x : bc[i]) bc[i+1].pb(x);
        sort(all(bc[i+1]));
        reverse(all(bc[i+1]));
        if(bc[i+1].size() > 2) bc[i+1].resize(2);
        for(auto x : dc[i]) dc[i+1].pb(x);
        sort(all(dc[i+1]));
        reverse(all(dc[i+1]));
        if(dc[i+1].size() > 2) dc[i+1].resize(2);
    }
    int ans = 0;
    if(!bc[c].empty() && !dc[d].empty()) ans = bc[c][0] + dc[d][0];
    forn(i,0,c+1) {
        if(bc[i].empty() || bc[c-i].empty()) continue;
        if(bc[i][0] != bc[c-i][0]) ans = max(ans, bc[i][0] + bc[c-i][0]);
        if(bc[i].size() > 1) ans = max(ans, bc[i][1] + bc[c-i][0]);
        if(bc[c-i].size() > 1) ans = max(ans, bc[i][0] + bc[c-i][1]);
    }
    forn(i,0,d+1) {
        if(dc[i].empty() || dc[d-i].empty()) continue;
        if(dc[i][0] != dc[d-i][0]) ans = max(ans, dc[i][0] + dc[d-i][0]);
        if(dc[i].size() > 1) ans = max(ans, dc[i][1] + dc[d-i][0]);
        if(dc[d-i].size() > 1) ans = max(ans, dc[i][0] + dc[d-i][1]);
    }
    cout<<ans;
    
}