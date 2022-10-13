#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
vector<int> adj[100001];
ll dpS[100001][20][2], dpT[100001][20][2];
int a[100001];
void dfs(int curr, int par) {
    vector<ll> x[20], y[20];
    for(int next : adj[curr]) {
        if(next!=par) {
            dfs(next,curr);
            for(int bit=19;bit>=0;bit--) {
                if(a[curr]&(1<<bit)) {
                    dpS[curr][bit][0]+=dpS[next][bit][1];
                    dpS[curr][bit][1]+=dpS[next][bit][0];
                }
                else {
                    dpS[curr][bit][0]+=dpS[next][bit][0];
                    dpS[curr][bit][1]+=dpS[next][bit][1];
                }
                x[bit].push_back(dpS[next][bit][0]);
                y[bit].push_back(dpS[next][bit][1]);
            }
        }
    }
    //calc dpT here
    for(int bit=19;bit>=0;bit--) {
        ll suma = 0, sumb = 0;
        ll sumsqa = 0, sumsqb = 0;
        ll prodab = 0;
        for(int i=0;i<x[bit].size();i++) {
            suma+=x[bit][i];
            sumb+=y[bit][i];
            prodab+=x[bit][i]*1LL*y[bit][i];
            sumsqa+=x[bit][i]*1LL*x[bit][i];
            sumsqb+=y[bit][i]*1LL*y[bit][i];
        }
        if(a[curr]&(1<<bit)) {
            dpS[curr][bit][1]++;
            dpT[curr][bit][0]+=suma*1LL*sumb-prodab;
            dpT[curr][bit][1]+=(suma*1LL*suma-sumsqa)/2+(sumb*1LL*sumb-sumsqb)/2;
        }
        else {
            dpS[curr][bit][0]++;
            dpT[curr][bit][1]+=suma*1LL*sumb-prodab;
            dpT[curr][bit][0]+=(suma*1LL*suma-sumsqa)/2+(sumb*1LL*sumb-sumsqb)/2;
        }
    }
}
int main() {
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++) {
        int u,v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    ll ans = 0;
    for(int bit=0;bit<20;bit++) {
        for(int i=0;i<n;i++) {
            ans+=(dpS[i][bit][1]+dpT[i][bit][1])*1LL*(1<<bit);
        }
    }
    cout << ans << endl;
}