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
    int n,m,k;
    //string s;
    ll ans = 0;
    cin >> n;
    vi a(n);
    forn(i,0,n) {
        cin>>a[i];
    }
    vi l(n);
    vi r(n);
    l[0] = 1;
    forn(i,1,n) l[i] = min(a[i], l[i-1]+1);
    r[n-1]=1;
    for(int i = n-2; i>=0; i--) r[i]=min(a[i], r[i+1]+1);
    int best=0;
    forn(i,0,n) best = max(best, min(l[i],r[i]));
    cout<<best;
    
    // cout<<ans;
}