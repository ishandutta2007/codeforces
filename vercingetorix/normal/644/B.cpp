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
    int n,m,k,b;
    string s;
    ll ans = 0;
    scanf("%d %d", &n, &b);
    int tt,dd;
    set<ll> endpoints;
    forn(i,0,n) {
        scanf("%d %d", &tt, &dd);
        ll t=tt;
        ll d=dd;
        while ((endpoints.size()>0) && ((*endpoints.begin()) <= t)) endpoints.erase(endpoints.begin());
        ll newend;
        if (endpoints.size() > 0) newend = *(--endpoints.end()) + d;
        else newend = t + d;
        if(endpoints.size() >= b+1) {
            printf("-1 ");
        }
        else{
            printf("%I64d ", newend);
            endpoints.insert(newend);
        }
    }
    
    //cout<<ans;
}