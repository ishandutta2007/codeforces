#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
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
    ll p,m,k;
    string s;
    ll ans = 0;
    cin >> p >> k;
    if(k==0) {
        ans = 1;
        forn(i,0,p-1) ans = (ans*p)%mod;
        
        cout<<ans;
        return 0;
    }
    ll kk= k;
    int deg= 1;
    
    while(kk!=1) {
        kk=(kk*k) %p;
        deg++;
    }
    int degans = (p-1)/deg ;
    if(k==1) degans++;
    ans = 1;
    forn(i,0,degans) ans = (ans*p)%mod;
    
    cout<<ans;
}