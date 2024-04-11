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
    int cur = 0;
    int mx = 1000000000;
    int mn = -1000000000;
    forn(i,0,n) {
        int d,c;
        scanf("%d %d", &c, &d);
        if(d==1) {
            // cur + st >= 1900
            mn = max(mn, 1900 - cur);
        }
        else {
            mx = min(mx, 1899 - cur);
        }
        cur += c;
    }
    if(mn > mx) {
        cout<<"Impossible";
    }
    else if(mx==1000000000) {
        cout<<"Infinity";
    }
    else {
        cout<<mx+cur;
    }
}