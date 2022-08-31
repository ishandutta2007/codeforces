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
    vi t(n);
    forn(i,0,n) {
        scanf("%d", &t[i]);
    }
    const int INF = 1e9;
    vi d(n+1,INF);
    d[0]=0;
    forn(i,0,n) {
        d[i+1] = min(d[i+1], d[i] + 20);
        int en = lower_bound(all(t), t[i] + 90) - t.begin();
        d[en] = min(d[en], d[i] + 50);
        en = lower_bound(all(t), t[i] + 1440) - t.begin();
        d[en] = min(d[en], d[i] + 120);
    }
    for(int i = n-1; i>=0; i--) d[i] = min(d[i], d[i+1]);
    forn(i,1,n+1) {
        printf("%d\n", d[i]-d[i-1]);
    }
    
    
}