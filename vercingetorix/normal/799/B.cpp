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
    vi ban(n,0);
    vvpi d(3);
    vi pt(3,0);
    vi p(n),a(n),b(n);
    forn(i,0,n) scanf("%d", &p[i]);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) scanf("%d", &b[i]);
    forn(i,0,n) {
        a[i]--; b[i]--;
        forn(j,0,3) {
            if(a[i] == j || b[i] == j) d[j].pb(mp(p[i], i));
        }
    }
    int m;
    forn(j,0,3) sort(all(d[j]));
    scanf("%d", &m);
    forn(i,0,m) {
        forn(j,0,3) {
            while(pt[j] < d[j].size() && ban[d[j][pt[j]].second]) pt[j]++;
        }
        int c;
        scanf("%d", &c);
        c--;
        if(pt[c] == d[c].size()) {
            printf("-1 ");
        }
        else {
            printf("%d ", d[c][pt[c]].first);
            ban[d[c][pt[c]].second] = 1;
        }
    }
    
}