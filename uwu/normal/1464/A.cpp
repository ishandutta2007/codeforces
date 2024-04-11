#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int r[MAXN], c[MAXN], p[MAXN], val[MAXN], ans;

int Find(int x){ return (p[x]==x?x:p[x]=Find(p[x])); }
void Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a==b) ans++;
    p[b]=a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        ans=0;
        for (int i=1;i<=n;++i) r[i]=c[i]=val[i]=0, p[i]=i;
        for (int i=1;i<=m;++i){
            cin >> r[i] >> c[i];
            if (r[i]==c[i]){ val[r[i]]=i, p[i]=0; continue; }
            ans++;
            if (val[r[i]]==0) val[r[i]]=i;
            else Union(val[r[i]],i);
            if (val[c[i]]==0) val[c[i]]=i;
            else Union(val[c[i]],i);
        }
        cout << ans << '\n';
    }
}