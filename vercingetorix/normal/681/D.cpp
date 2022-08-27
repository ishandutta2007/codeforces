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
    //int n,m;
    scanf("%d %d", &n, &m);
    vi par(n,-1);
    vvi ch(n);
    vpi e;
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--; y--;
        e.pb(mp(x,y));
        par[y] = x;
        ch[x].pb(y);
    }
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
        forn(i,0,n) a[i]--;
    deque<int> ans;
    vi u(n,0);
    forn(i,0,n) {
        if(!u[i]) {
            int k = i;
            while(par[k] != -1) k=par[k];
            deque<int> q;
            if(a[k] != k) {
                cout <<-1;
                return 0;
            }
            else {
                ans.push_front(k);
            }
            q.pb(k);
            while(!q.empty()) {
                int v= q.front();
                q.pop_front();
                u[v] = 1;
                for(auto c : ch[v]) {
                    if(a[c] == c) ans.push_front(c);
                    else if(a[c] != a[v]) {
                        cout<<-1;
                        return 0;
                    }
                    q.pb(c);
                }
            }
        }
    }
    
//    forn(i,0,n) a[i]--;
//    vi boss(n,0);
//    forn(i,0,n) if(a[i]==i) boss[i]=1;
//    forn(i,0,n) if(boss[a[i]] != 1) {
//        cout<<-1;
//        return 0;
//    }
//    for(auto p : e) {
//        int x = p.first;
//        if(boss[x]) continue;
//        int y = p.second;
//        int bx = a[x];
//        int by = a[y];
//        if(bx!=by) {
//            cout<<-1;
//            return 0;
//        }
//    }
//    //int ans =0;
//    for (int i=0; i<n; ++i) {
//        used[i] = true;
//        if(boss[i]) {
//            used[i] = false;
//            if(par[i] >= 0) g[i].pb(a[par[i]]);
//        }
//    }
//    topological_sort();
//    //forn(i,0,n) ans+=boss[i];
    printf("%d\n", ans.size());
    for(auto x:ans) printf("%d\n", x+1);
}