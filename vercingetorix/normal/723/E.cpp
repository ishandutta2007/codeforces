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
    int t;
    scanf("%d\n", &t);
    forn(agag,0,t) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        vector<set<int>> g(n);
        forn(i,0,m) {
            int x,y;
            scanf("%d %d\n", &x,&y);
            x--;
            y--;
            g[x].insert(y);
            g[y].insert(x);
        }
        int ans = 0;
        vpi roads;
        forn(i,0,n) if((int)g[i].size() % 2 == 0) ans++;
        int p = 0;
        while(p<n) {
            if((int)g[p].size() % 2 == 1 || g[p].empty()) {
                p++;
                continue;
            }
            vi used(n, 0);
            int cur = p;
            deque<int> c;
            while(!used[cur] && (int)g[cur].size()%2 == 0) {
                auto it = g[cur].begin();
                if(!c.empty() && c.back() == *it) it++;
                c.pb(cur);
                used[cur] = 1;
                cur = *it;
            }
            c.pb(cur);
            if(used[cur]) {
                while(c.front() != cur) c.pop_front();
            }
            else {
                c.pop_front();
                
                cur = p;
                used[cur] = 0;
                while(!used[cur] && (int)g[cur].size()%2 == 0) {
                    auto it = g[cur].begin();
                    if(!c.empty() && c.front() == *it) it++;
                    c.push_front(cur);
                    used[cur] = 1;
                    cur = *it;
                }
                c.push_front(cur);
                if(used[cur]) {
                    while(c.back() != cur) c.pop_back();
                }
            }
            forn(i,0,c.size() - 1) {
                roads.pb(mp(c[i]+1, c[i+1]+1));
                g[c[i]].erase(c[i+1]);
                g[c[i+1]].erase(c[i]);
            }
        }
        forn(i,0,n) {
            while(!g[i].empty()) {
                int y = *g[i].begin();
                roads.pb(mp(i+1, y+1));
                g[i].erase(y);
                g[y].erase(i);
            }
        }
        printf("%d\n", ans);
        for(auto e:roads) {
            printf("%d %d\n", e.first, e.second);
        }
        
    }
    
}