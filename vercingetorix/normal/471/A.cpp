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
    vi l(10,0);
    int a;
    forn(i,0,6) {
        cin>>a;
        l[a]++;
    }
    int legs=-2;
    forn(i,0,10) {
        if(l[i]>=4) {
            legs = i;
            l[i]-=4;
        }
    }
    if(legs<0) {
        
    cout<<"Alien";
        return 0;
    }
    vi gs;
    forn(i,0,10) {
        while(l[i]>0) {
            l[i]--;
            gs.pb(i);
        }
    }
    if(gs[0]==gs[1]) cout<<"Elephant";
    else cout<<"Bear";
    // cout<<ans;
}