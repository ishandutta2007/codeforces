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
    int n,m,a,b;
    ll ans=0;
    
    scanf("%d %d", &n,&m);
    std::vector<std::vector<int>> nb(n);
    vll deg(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin >>u>>v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
        if(u<v)swap(u,v);
        nb[u].push_back(v);
    }
    vll maxtail(n,0);
    for(int i = 0; i<n; i++) {
        maxtail[i]=1;
        for(auto x:nb[i]) {
            maxtail[i]=max(maxtail[i], 1+maxtail[x]);
        }
        ans=max(ans, maxtail[i]*deg[i]);
    }

    
    
    cout<<ans;
}