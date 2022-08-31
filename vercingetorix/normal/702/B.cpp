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
    vi p2;
    int d2 = 1;
    map<int,int> isd2;
    forn(i,0,31) {
        p2.pb(d2);
        isd2[d2]=1;
        d2*=2;
    }
    map<int,int> cnt;
    map<int,int> cnt2;
    forn(i,0,n) {
        int x;
        cin>>x;
        cnt[x]++;
    }
    cnt2 = cnt;
    ll ans = 0;
    for(auto u : cnt) {
        int a = u.first;
        forn(i,0,31) {
            d2 = p2[i];
            if(d2 <= a) continue;
            int b = d2 -a;
            ll x=u.second;
            ll y = cnt2[b];
            if(b==a) ans += x*(x-1);
            else ans += x*y;
        }
    }
    cout<<ans/2;
    
    
}