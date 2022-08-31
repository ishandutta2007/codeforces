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

long long mod=1000000007;

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
    cin>>n>>m;
    vi a(4*n,-1);
    forn(i,0,m) {
        if(i<2*n) {
            if(i&1) a[3*n + i/2] = i+1;
            else a[i/2] = i+1;
        }
        else {
            if(i&1) a[2*n + (i-2*n)/2] = i+1;
            else a[n + (i-2*n)/2] = i+1;
        }
    }
    forn(i,0, n) {
        if(a[n+i]>0) cout<<a[n+i]<<" ";
        if(a[i]>0) cout<<a[i]<<" ";
        if(a[2*n+i]>0) cout<<a[2*n+i]<<" ";
        if(a[3*n+i]>0) cout<<a[3*n+i]<<" ";
    }
    // cout<<ans;
}