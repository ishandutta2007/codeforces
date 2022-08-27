#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
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
vvi ch;
vi par;
vi st;
void dfs(int v) {
    if(ch[v].empty()) st[v] = 1;
    else st[v] = 0;
    for(auto u : ch[v]) dfs(u);
    for(auto u : ch[v]) st[v] += st[u];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    a--;b--;c--;d--;
    
    par.resize(n);
    st.resize(n);
    ch.resize(n);
    forn(i,0,n-1) {
        scanf("%d", &par[i+1]);
        par[i+1]--;
        ch[par[i+1]].pb(i+1);
    }
    int lcnt=0;
    forn(i,0,n) if(ch[i].empty()) lcnt++;
    dfs(0);
    bitset<5000> can;
    vi ind(4);
    ind[0]=a; ind[1]=b;ind[2]=c;ind[3]=d;
    vector<bitset<5000>> cans(2);
    forn(i,0,5000) can[i] = 0;
    vi special(n,0);
    int cur = a;
    vi suka(4);
    while(par[cur]!=0) cur=par[cur]; special[cur] = 1; suka[0]=st[cur];
    cur=b; while(par[cur]!=0) cur=par[cur]; special[cur] = 2; suka[1]=st[cur];
    cur=c; while(par[cur]!=0) cur=par[cur]; special[cur] = 3; suka[2]=st[cur];
    cur=d; while(par[cur]!=0) cur=par[cur]; special[cur] = 4; suka[3]=st[cur];
    can[0] = 1;
    for(auto u : ch[0]) if(special[u]==0) can|=(can<<st[u]);
    cans[0][0]=1;
    cans[1][0]=1;
    forn(i,0,4) {
        int v = ind[i];
        while(1) {
            int p = par[v];
            if(p==0) break;
            for(auto u:ch[p]) if(u!=v) cans[i/2]|=(cans[i/2]<<st[u]);
            v=p;
        }
    }
    if(lcnt%2!=0) {
        cout<<"NO";
        return 0;
    }
    int bet = (lcnt-2)/2;
    bool ab=false,cd=false;
    forn(i,suka[2],bet+1) {
        if(cans[0][i-suka[2]] && can[bet-i]) ab=true;
    }
    forn(i,suka[0],bet+1) {
        if(cans[1][i-suka[0]] && can[bet-i]) cd=true;
    }
    if(ab&&cd) cout<<"YES";
    else cout<<"NO";
    
    
    
}