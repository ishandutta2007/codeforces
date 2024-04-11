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
    //string s;
    ll ans = 0;
    scanf("%d %d %d", &n,&m,&k);
    vvi banned(n);
    forn(i,0,m) {
        int a,b;
        scanf("%d %d", &a,&b);
        a--;b--;
        banned[a].pb(b);
        banned[b].pb(a);
    }
    if(banned[0].size() + k > n-1) {
        cout<<"impossible";
        return 0;
    }
    vb used(n, false);
    //set<int> toadd;
    vi toadd;
    forn(i,1,n) toadd.pb(i);
    vb badn(n,false);
    used[0]=true;
    vb banfrom1(n,false);
    int comps=0;
    for(auto x:banned[0]) banfrom1[x]=true;
    for(int s=1; s<n; s++) {
        if(used[s]) continue;
        if(banfrom1[s]) continue;
        comps++;
        deque<int> bfs;
        bfs.pb(s);
        used[s]=true;
        while(bfs.size()>0) {
            int v = bfs.front();
            bfs.pop_front();
            for(auto x: banned[v]) badn[x]=true;
            vi newtoadd;
            for(auto u:toadd) {
                if(badn[u]) newtoadd.pb(u);
                else {
                    used[u]=true;
                    bfs.pb(u);
                }
            }
            toadd=newtoadd;
            for(auto x: banned[v]) badn[x]=false;
        }
    }
    
    bool allused = true;
    forn(i,0,n) if(!used[i]) allused = false;
    if ((!allused) || (comps>k)) cout<<"impossible";
    else cout<<"possible";
    //cout<<ans;
}