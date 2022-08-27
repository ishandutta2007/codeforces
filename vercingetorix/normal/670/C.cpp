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
    int n,m;
    scanf("%d",&n);
    map<int,int> lang;
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        lang[x]++;
    }
    scanf("%d", &m);
    vi b(m), c(m);
    forn(i,0,m) scanf("%d", &b[i]);
    forn(i,0,m) scanf("%d", &c[i]);
    int best1 = 0;
    int best2 = 0;
    int ans = 1;
    forn(i,0,m) {
        if(lang[b[i]] > best1 || (lang[b[i]] == best1 && lang[c[i]] > best2)) {
            best1=lang[b[i]];
            best2=lang[c[i]];
            ans=i+1;
        }
    }
    cout<<ans;
}