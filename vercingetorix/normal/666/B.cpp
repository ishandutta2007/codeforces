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
    const int INF = 1000000000;
    int n,m;
    scanf("%d %d", &n,&m);
    vector<vector < vector < int > >> g (2, vector < vector < int > >(n));
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        g[0][x].pb(y);
        g[1][y].pb(x);
    }
    vector<vvi> d(2, vvi(n, vi(n, INF)));
    
    forn(w,0,2) {
        forn(s,0,n) {
            vector<int>  p (n);
            d[w][s][s] = 0;
            priority_queue < pair<int,int> > q;
            q.push (make_pair (0, s));
            while (!q.empty()) {
                int v = q.top().second,  cur_d = -q.top().first;
                q.pop();
                if (cur_d > d[w][s][v])  continue;
                for (size_t j=0; j<g[w][v].size(); ++j) {
                    int to = g[w][v][j];
                    if (d[w][s][v] + 1 < d[w][s][to]) {
                        d[w][s][to] = d[w][s][v] + 1;
                        p[to] = v;
                        q.push (make_pair (-d[w][s][to], to));
                    }
                }
            }
        }
    }
    vvpi f3s(n, vpi(3, mp(-INF, -INF))), f3b(n, vpi(3, mp(-INF, -INF)));
    forn(i,0,n) {
        forn(j,0,n) {
            if(i!=j && d[0][i][j] != INF) {
                f3s[i].pb(mp(d[0][i][j], j));
                sort(all(f3s[i]));
                reverse(all(f3s[i]));
                f3s[i].resize(3);
            }
            if(i!=j && d[1][i][j] != INF) {
                f3b[i].pb(mp(d[1][i][j], j));
                sort(all(f3b[i]));
                reverse(all(f3b[i]));
                f3b[i].resize(3);
            }
        }
    }
    int best = 0;
    int A1,A2,A3,A4;
    forn(a2,0,n) forn(a3,0,n) {
        if(a2==a3) continue;
        if(d[0][a2][a3] == INF) continue;
        for(auto ap1: f3b[a2]) {
            for(auto ap4: f3s[a3]) {
                int a1 = ap1.second;
                int a4 = ap4.second;
                if(ap1.first == -INF || ap4.first == -INF || a1 == a3 || a1 == a4 || a4 == a2) continue;
                int dist = ap1.first + ap4.first + d[0][a2][a3];
                if(dist > best) {
                    best = dist;
                    A1=a1;
                    A2=a2;
                    A3=a3;
                    A4=a4;
                }
            }
        }
    }
    
    cout<<A1+1<<" "<<A2+1<<" "<<A3+1<<" "<<A4+1<<endl;
}