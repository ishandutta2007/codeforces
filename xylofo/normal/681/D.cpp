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

const int N = 100005;
int res[N],p[N],v[N],cnt;
vi g[N];

bool dfs(int x,int p){
    for(int y:g[x]) if(!dfs(y,x)) return 0;
    if(v[x]!=x && v[x]!=v[p]) return 0;
    if(v[x]==x) res[cnt++]=x;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        p[b]=1;
    }
    rep(i,1,n+1) cin>>v[i];
    rep(i,1,n+1) if(!p[i] && !dfs(i,0)){
        puts("-1");
        return 0;
    }
    cout<<cnt<<'\n';
    rep(i,0,cnt)cout<<res[i]<<'\n';
    return 0;
}