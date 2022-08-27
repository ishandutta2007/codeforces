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

long long mod=1000003;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

    int n,m;
const int MAXN = 100001;
vector<pi> g[MAXN];
bool usedR[MAXN];
bool usedB[MAXN];
vi tocolR(MAXN, 0);
vi tocolB(MAXN, 0);
vector<int> comp;
int ansB = 0;
int ansR = 0;
bool fB = true;
bool fR = true;

void dfsB (int v) {
    usedB[v] = true;
    comp.push_back (v);
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        if (usedB[to]) {
            if (tocolB[v]==tocolB[to]) {
                if(g[v][i].second == 1) fB = false;
            }
            if(tocolB[v]!=tocolB[to]) {
                if(g[v][i].second == 0) fB = false;
            }
        }
        else {
            if(g[v][i].second == 1) tocolB[to] = 1-tocolB[v];
            else tocolB[to]=tocolB[v];
            dfsB (to);
        }
    }
}

void dfsR (int v) {
    usedR[v] = true;
    //comp.push_back (v);
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        if (usedR[to]) {
            if (tocolR[v]==tocolR[to]) {
                if(g[v][i].second == 0) fR = false;
            }
            if(tocolR[v]!=tocolR[to]) {
                if(g[v][i].second == 1) fR = false;
            }
        }
        else {
            if(g[v][i].second == 0) tocolR[to] = 1-tocolR[v];
            else tocolR[to]=tocolR[v];
            dfsR (to);
        }
    }
}

void find_comps() {
    for (int i=0; i<n; ++i){
        usedB[i] = false;
        usedR[i] = false;
    }
    for (int i=0; i<n; ++i)
        if (! usedB[i]) {
            comp.clear();
            dfsB (i);
            dfsR (i);
            int s = comp.size();
            int cntB = 0;
            int cntR = 0;
            for(auto x : comp) {
                if(tocolB[x]) cntB++;
                if(tocolR[x]) cntR++;
            }
            if(2*cntR > s) {
                cntR = s-cntR;
                for(auto x:comp) {
                    tocolR[x] = 1-tocolR[x];
                }
            }
            if(2*cntB > s) {
                cntB = s-cntB;
                for(auto x:comp) {
                    tocolB[x] = 1-tocolB[x];
                }
            }
            ansB += cntB;
            ansR += cntR;
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d %d",&n,&m);
    forn(i,0,m) {
        int u,v;
        char c;
        scanf("%d %d %c",&u,&v,&c);
        u--;
        v--;
        int col;
        if(c=='B') col = 0;
        else col = 1;
        g[u].pb(mp(v,col));
        g[v].pb(mp(u,col));
        
    }
    find_comps();
    if(!fR && !fB) {
        cout<<-1;
        return 0;
    }
    if(fR && fB) {
        if(ansR>ansB) {
            cout<<ansB<<endl;
            forn(i,0,n) if(tocolB[i]) cout<<i+1<<" ";
            cout<<endl;
            return 0;
        }
        else {
            cout<<ansR<<endl;
            forn(i,0,n) if(tocolR[i]) cout<<i+1<<" ";
            cout<<endl;
            return 0;
        }
    }
    if(fR) {
        cout<<ansR<<endl;
        forn(i,0,n) if(tocolR[i]) cout<<i+1<<" ";
        cout<<endl;
        return 0;
    }
    if(fB) {
        cout<<ansB<<endl;
        forn(i,0,n) if(tocolB[i]) cout<<i+1<<" ";
        cout<<endl;
        return 0;
    }
    cout<<"adlk";
    
}