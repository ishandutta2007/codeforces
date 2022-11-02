#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,a[N];
struct pp{int val,id;}p[N];
bool cmp(pp x,pp y){return x.val<y.val;}
int f[N],siz[N],vis[N];
int find(int x){return x==f[x]?x:(f[x]=find(f[x]));}
bool merge(int u,int v){
    if(!vis[u]||!vis[v]) return 0;
    int fu=find(u),fv=find(v);
    if(fu==fv) return 0;
    f[fu]=fv;siz[fv]+=siz[fu];
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) p[i].val=a[i],p[i].id=i;
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
    int mx=0,cnt=0,ans=1,num=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        cnt++;int x=p[i].id;vis[x]=1;
        if(x<n&&merge(x,x+1)) cnt--;
        if(x>1&&merge(x,x-1)) cnt--;
        int fa=find(x);mx=max(mx,siz[fa]);
        if(1ll*cnt*mx==i){
            if(cnt>num) num=cnt,ans=p[i].val+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
max(r-l+1)sum...
*/