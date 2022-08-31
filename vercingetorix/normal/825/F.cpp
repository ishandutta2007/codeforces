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
    vi ldd(10000,0);
    forn(i,1,10000) {
        int k = i;
        while(k>0) {
            ldd[i]++;
            k/=10;
        }
    }
    string s;
    getline(cin, s);
    int n = s.size();
    vvi q(n, vi(n,0));
    forn(i,0,n) {
        if(s[i] == s[0]) {
            q[i][0] = 1;
            q[0][i] = 1;
        }
    }
    forn(i,1,n) forn(j,1,n) {
        if(s[i] == s[j]) q[i][j] = 1 + q[i-1][j-1];
    }
    vvi rep(n, vi(n+1, 0));
    forn(r,0,n) {
        forn(len, 1, r+2) {
            if(len<=r && q[r][r-len] >= len) rep[r][len] = 1+rep[r-len][len];
            else rep[r][len] = 1;
        }
    }
    vi d;
    forn(i,0,n+1) d.pb(i+1);
    d[0] = 0;
    forn(i,1,n+1) {
        forn(l,1,i+1) {
            int m = rep[i-1][l];
            forn(k,1,m+1) {
                d[i] = min(d[i], d[i-k*l] + ldd[k] + l);
            }
        }
    }
    cout<<d[n];
    
}