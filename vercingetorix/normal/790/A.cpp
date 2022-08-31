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
    vs names;
    forn(i,0,400) {
        string s;
        s.pb('A'+i/26);
        s.pb('a'+i%26);
        names.pb(s);
    }
    
    int pt = 0;
    int n,k;
    scanf("%d %d\n", &n, &k);
    vi u(n-k+1);
    forn(i,0,n-k+1) {
        char c[5];
        scanf("%s", c);
        if(c[0] == 'Y') u[i] = 1;
        else u[i] = 0;
    }
    vs ans;
    if(u[0] == 1) {
        forn(i,0,k) ans.pb(names[pt++]);
    }
    else {
        ans.pb(names[0]);
        forn(i,0,k-1) ans.pb(names[pt++]);
    }
    forn(i,1,n-k+1) {
        if(u[i] == 1) {
            ans.pb(names[pt++]);
        }
        else {
            ans.pb(ans[i]);
        }
    }
    for(auto x : ans) printf("%s ", x.c_str());
    
    
}