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
    //ll ans = 0;
    scanf("%d %d", &n,&m);
    vi reord(n);
    vpi ord;
    forn(i,0 ,n) {
        int x;
        scanf("%d", &x);
        x--;
        ord.pb(mp(x,i));
        reord[x] = i;
    }
//    sort(all(ord));
  //  forn(i,0,n) reord[ord[i].second] = i;
    vvi ff(n);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d",&x,&y);
        x--; y--;
        if(reord[x]>reord[y]) swap(x,y);
        ff[reord[y]].pb(reord[x]);
    }
    ll ans=0;
    int curl = -1;
    forn(r,0,n) {
        for(auto l:ff[r]) {
            curl = max(curl,l);
        }
        ans+=(r-curl);
    }
    cout<<ans;
}