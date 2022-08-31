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
    scanf("%d\n", &n);
    string s;
    getline(cin, s);
    vi a(26);
    forn(i,0,26) scanf("%d", &a[i]);
    const int INF = 1e8;
    vll d(n+1,0);
    vi mn(n+1,0);
    forn(i,0,n+1) mn[i] = i;
    d[0] = 1;
    int best = 1;
    forn(e,0,n) {
        int maxl = INF;
        int st = e;
        while (st >= 0 && e-st < maxl && e - st < a[s[st]-'a']) {
            maxl = min(maxl, a[s[st]-'a']);
            st--;
            d[e+1] = (d[e+1] + d[st+1]) % mod;
            mn[e+1] = min(mn[e+1], mn[st+1] + 1);
            best = max(best, e-st);
        }
    }
    cout<<d[n]<<endl;
    cout<<best<<endl;
    cout<<mn[n]<<endl;
    
    
}