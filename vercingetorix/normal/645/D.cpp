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

//int n; //  
vector<int> g[100001]; // 
bool used[100001];
vector<int> ans;
int n,m,k;
void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ans.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ans.begin(), ans.end());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    //string s;
    //ll ans = 0;
    //()
    scanf("%d %d", &n, &m);
    vpi match;
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        match.pb(mp(x-1,y-1));
    }
    int l = 1;
    int r = m+1;
    while(r-l>0) {
        int med = (r+l)/2;
        forn(i,0,n) g[i].clear();
        map<pi, int> used;
        forn(i,0,med) {
            g[match[i].first].pb(match[i].second);
            used[match[i]] = 1;
        }
        topological_sort();
        bool f=true;
        forn(i,0,n-1) {
            if(used[mp(ans[i],ans[i+1])]!=1) {
                f=false;
                break;
            }
        }
        if(f) r=med;
        else l=med+1;
    }
    if(l==m+1) cout<<-1;
    else cout<<l;
    //cout<<ans;
}