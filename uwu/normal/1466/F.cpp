#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e5+5;

int a[MAXN], b[MAXN], one[MAXN];
int p[MAXN], sz[MAXN], req, ways=1;
bool vis[MAXN];
vector<int> ans;

int Find(int a){ return p[a]==a?a:p[a]=Find(p[a]); }
bool Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a==b) return 0;
    if (sz[b]>sz[a]) swap(a,b);
    sz[a]+=sz[b];
    p[b]=a;
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i) sz[i]=1, p[i]=i;
    for (int i=1;i<=n;++i){
        int k; cin >> k; a[i]=0;
        if (k==1) cin >> a[i];
        else cin >> a[i] >> b[i];
        if (Union(a[i],b[i])) ans.push_back(i);
    }
    req=ans.size();
    for (int i=1;i<=req;++i) ways*=2, ways%=mod;
    cout << ways << " " << req << '\n';
    for (int x:ans) cout << x << " ";
    cout << '\n';
}