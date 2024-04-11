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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int base = 1000222111;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    cin >>n>>m>>q;
    vvi t(n, vi(m,0));
    forn(i,0,n) forn(j,0,m) t[i][j] = i*m+j;
    vi ans(m*n, 0);
    forn(arn,0,q) {
        int type;
        cin>>type;
        if(type == 3) {
            int x,y,v;
            cin>>x>>y>>v;
            x--;
            y--;
            int was = t[x][y];
            ans[was] = v;
        }
        if(type == 1) {
            int k;
            cin>>k;
            k--;
            int val = t[k][0];
            forn(i,0,m-1) t[k][i] = t[k][i+1];
            t[k][m-1] = val;
        }
        if(type == 2) {
            int k;
            cin>>k;
            k--;
            int val = t[0][k];
            forn(i,0,n-1) t[i][k] = t[i+1][k];
            t[n-1][k] = val;
        }
    }
    forn(i,0,n) {
        forn(j,0,m) cout<<ans[i*m+j]<<" "; cout<<endl;
    }
}