#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <queue>
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

vvi e;

int n,m; //  



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    //int n,m,k;
    //string s;
    ll ans = 0;
    cin >> n >> m;
    e = vvi (n, vi(n, 0));

    forn(i,0,m) {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        e[x][y]=1;
        e[y][x]=1;
    }
    queue<int> q;
    q.push (0);
//    vector<bool> used (n);
    vector<int> d (n), p (n);
    int r = 1-e[0][n-1];
    int s= 0;
    vb used(n,false);
    used[s] = true;
  //  vi p(n);
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to=0; to<n; ++to) {
            if(to==v) continue;
            if(e[v][to] != r) continue;
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    int to = n-1;
    if (!used[n-1]) {
        cout << -1;
        return 0;
    }
    else {
        vector<int> path;
        for (int v=to; v!=-1; v=p[v])
            path.push_back (v);
        reverse (path.begin(), path.end());
        cout << path.size() - 1;
    }
    
    //cout<<ans;
}