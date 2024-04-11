#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <cstring>
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
    ll n,m,k,x1,y1,x2,y2;
    //string s;
    ll ans = 1000000000000000000;
    cin >> n>>x1>>y1>>x2>>y2;
    vll dist1;
    vll dist2;
    forn(i,0,n) {
        ll x,y;
        cin>>x>>y;
        dist1.pb((x-x1)*(x-x1)+(y-y1)*(y-y1));
        dist2.pb((x-x2)*(x-x2)+(y-y2)*(y-y2));
        
    }
    forn(r1,0,n) {
        ll d = dist1[r1];
        ll r2 = 0;
        forn(i,0,n) if(dist1[i]>d) r2=max(r2, dist2[i]);
        ans=min(ans, dist1[r1]+r2);
        
    }
    ll d = 0;
    ll r2 = 0;
    forn(i,0,n) if(dist1[i]>d) r2=max(r2, dist2[i]);
    ans=min(ans, r2);
    cout<<ans;
}