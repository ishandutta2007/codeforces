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
    vvi a(n, vi(n,1));
    int o = 1;
    int e = 2;
    int p = (n*n+1)/2;
    int q = n*n - p;
    forn(i,0,n/2) forn(j,0,n/2) {
        if(q>0) {
            q-=4;
            a[i][j] = 0;
            a[n-1-i][j]=0;
            a[n-1-i][n-1-j]=0;
            a[i][n-1-j]=0;
        }
    }
    forn(i,0,n) forn(j,0,n) {
        if(a[i][j] == 0) {
            a[i][j] = e;
            e+=2;
        }
        else {
            a[i][j]= o;
            o+=2;
        }
    }
    forn(i,0,n) {
        forn(j,0,n) {
            cout<<a[i][j];
            if(j<n-1) cout<<' ';
        }
        cout<<endl;
    }
    
    
    
}