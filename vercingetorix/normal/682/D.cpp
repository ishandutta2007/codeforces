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
    int n,m,k;
    scanf("%d %d %d\n", &n, &m, &k);
    string s,t;
    getline(cin,s);
    getline(cin,t);
    vector<vvi> d(n+1, vvi(m+1, vi(2*k +1, 0)));
    forn(i,0,n+1)
    forn(j,0,m+1) {
        forn(st,0,2*k+1) {
            if(st%2 == 0) {
                if(i<n) d[i+1][j][st] = max(d[i+1][j][st], d[i][j][st]);
                if(j<m) d[i][j+1][st] = max(d[i][j+1][st], d[i][j][st]);
                if(st<2*k) d[i][j][st+1] = max(d[i][j][st+1], d[i][j][st]);
            }
            if(st%2 == 1) {
                if(i<n && j<m && s[i]==t[j]) d[i+1][j+1][st] = max(d[i+1][j+1][st], d[i][j][st]+1);
                if(i<n && j<m && s[i]==t[j]) d[i+1][j+1][st+1] = max(d[i+1][j+1][st+1], d[i][j][st]+1);
            }
        }
    }
    cout<<d[n][m][2*k];
}