#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int vis[200000];
vvi g;
int cnt;

bool dfs(int x){
    if(vis[x]) return true;
    vis[x] = 1;
    cnt++;
    for(int y:g[x]) {
        if(g[x].size() != g[y].size()) 
            return false;
        if(!dfs(y)) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    g.resize(n);
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    rep(x,0,n){
        if(!vis[x]){
            cnt = 0;
            if(dfs(x) && cnt == 1 + g[x].size()) continue;
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}