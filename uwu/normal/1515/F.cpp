#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

ll n, m, x;
ll a[MAXN];
struct Edge{ int to, nxt; } adj[2*MAXN];
int h[MAXN], vis[MAXN];
vector<int> v1, v2;

void dfs(int v){
    vis[v]=1;
    for (int i=h[v];i;i=adj[i].nxt){
        int to=adj[i].to;
        if (vis[to]) continue;
        dfs(to);
        if (a[v]+a[to]>=x){
            v1.push_back((i+1)/2);
            a[v]+=a[to]-x;
        }
        else v2.push_back((i+1)/2);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[2*i]={b,h[a]}, h[a]=2*i;
        adj[2*i-1]={a,h[b]}, h[b]=2*i-1;
    }
    if ((n-1)*(x)>accumulate(a+1,a+1+n,0LL)) cout << "NO" << '\n';
    else{
        cout << "YES" << '\n';
        dfs(1);
        reverse(v2.begin(),v2.end());
        for (int x:v1) cout << x << '\n';
        for (int x:v2) cout << x << '\n';
    }
}