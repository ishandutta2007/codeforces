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
    cin>>n;
    vs a(n);
    forn(i,0,n) cin>>a[i];
    int minx = n;
    int miny = n;
    int maxx = -1;
    int maxy = -1;
    forn(i,0,n) forn(j,0,n) if(a[i][j] == '4') {
        minx=min(minx, i);
        miny=min(miny, j);
        maxx=max(maxx, i);
        maxy=max(maxy, j);
    }
    if(minx==n) {
        cout<<"No";
        return 0;
    }
    vs b(n, string(n,'0'));
    forn(i,minx,maxx+1) forn(j,miny,maxy+1) {
        b[i][j] = '4';
    }
    if(minx>0) {
        forn(j,miny,maxy+1) {
            b[minx-1][j] = '2';
        }
        if(miny>0) b[minx-1][miny-1] = '1';
        if(maxy<n-1) b[minx-1][maxy+1] = '1';
    }
    if(maxx<n-1) {
        forn(j,miny,maxy+1) {
            b[maxx+1][j] = '2';
        }
        if(miny>0) b[maxx+1][miny-1] = '1';
        if(maxy<n-1) b[maxx+1][maxy+1] = '1';
    }
    if(miny>0) {
        forn(i,minx,maxx+1) {
            b[i][miny-1] = '2';
        }
    }
    if(maxy<n-1) {
        forn(i,minx,maxx+1) {
            b[i][maxy+1] = '2';
        }
    }
//    forn(i,0,n) cout<<b[i] <<endl;
    forn(i,0,n) forn(j,0,n) {
        if(a[i][j]!=b[i][j]) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    
}