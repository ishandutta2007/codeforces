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
    int n,m,k;
    string s;
    //ll ans = 0;
    cin >> n;
    vector<pair<pi, int>> a;
    forn(i,0,n) {
        int x,y;
        cin>>x>>y;
        a.pb(mp(mp(x,y), i));
    }
    sort(all(a));
    ll x1 = a[0].first.first;
    ll x2 = a[1].first.first;
    ll y1 = a[0].first.second;
    ll y2 = a[1].first.second;
    for(int i = 2; i<n; i++) {
        ll x3=a[i].first.first;
        ll y3 = a[i].first.second;
        if((x3-x1)*(y2-y1) == (x2-x1)*(y3-y1)) continue;
        cout << a[0].second +1 << " " << a[1].second +1 << " " <<a[i].second+1;
        return 0 ;
    }
    //cout<<ans;
}