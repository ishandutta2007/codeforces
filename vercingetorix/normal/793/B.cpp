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
    int n,m;
    scanf("%d %d\n", &n, &m);
    vs a(n);
    int sx,sy,tx,ty;
    forn(i,0,n) {
        getline(cin, a[i]);
        forn(j,0,m) {
            if(a[i][j]=='S') {
                sx=i; sy=j;
            }
            if(a[i][j]=='T') {
                tx=i; ty=j;
            }
        }
    }
    string ans = "NO";
    forn(i,0,n) {
        bool can = true;
        for(int j=min(sx,i); j<=max(sx,i); j++) if(a[j][sy] == '*') can = false;
        for(int j=min(tx,i); j<=max(tx,i); j++) if(a[j][ty] == '*') can = false;
        for(int j=min(sy,ty); j<=max(ty,sy); j++) if(a[i][j] == '*') can = false;
        if(can) ans = "YES";
    }
    
    forn(i,0,m) {
        bool can = true;
        for(int j=min(sy,i); j<=max(sy,i); j++) if(a[sx][j] == '*') can = false;
        for(int j=min(ty,i); j<=max(ty,i); j++) if(a[tx][j] == '*') can = false;
        for(int j=min(sx,tx); j<=max(tx,sx); j++) if(a[j][i] == '*') can = false;
        if(can) ans = "YES";
    }
    cout<<ans;
}