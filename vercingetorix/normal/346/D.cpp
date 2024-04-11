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
    int n,m;
    scanf("%d %d", &n, &m);
    vvi g(n);
    vvi grev(n);
    vi out(n);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x,&y);
        x--;y--;
        out[x]++;
        g[x].pb(y);
        grev[y].pb(x);
    }
    
    int s,t;
    scanf("%d %d", &s,&t);
    s--;
    t--;
    deque<int> q;
    deque<int> nq;
    vi used(n,0);
    q.pb(t);
    used[t] = 1;
    int ans = 0;
    while(1) {
        if(q.empty()) break;
        int pt = 0;
        while(pt < q.size()) {
            int u =q[pt];
            for(auto v:grev[u]) {
                out[v]--;
                if(out[v] == 0 && !used[v]) {
                    q.pb(v);
                    used[v] = 1;
                }
            }
            pt++;
        }
        if(used[s]) break;
        ans++;
        for(auto u : q) {
            for(auto v : grev[u]) if(!used[v]) {
                used[v] = 1;
                nq.pb(v);
            }
        }
        q.clear();
        q=move(nq);
        nq.clear();
    }
    if(used[s]) cout<<ans;
    else cout<<-1;
}