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
    cin>>n;
    vi d(n);
    vi s(n);
    set<pair<pi, int>> ya;
    forn(i,0,n) {
        cin>>d[i]>>s[i];
        ya.insert(mp(mp(d[i],s[i]), i));
    }
    vpi ans;
    while(ya.size()>0) {
        pair<pi, int> cur = *(ya.begin());
        ya.erase(ya.begin());
        if(cur.first.first == 1) {
            int u = cur.first.second;
            //cout<<cur.second<< " "<<u<<endl;
            ans.pb(mp(cur.second, u));
            ya.erase(mp(mp(d[u],s[u]),u));
            d[u]--;
            d[cur.second] = 0;
            s[cur.second] = 0;
            s[u] = (s[u] | cur.second) - (s[u] & cur.second);
            ya.insert(mp(mp(d[u],s[u]),u));
        }
    }
    cout<<ans.size()<<endl;
    for(auto x: ans) cout<<x.second<< " "<<x.first<<endl;
}