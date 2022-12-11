#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
struct edge{
    int to,nex;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
int t,n,dis[N];
int dfs(int x,int fa,int dep){
    int mx=dep,cx=dep;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        int res=dfs(v,x,dep+1);
        if(mx<res)cx=mx,mx=res;
        else cx=max(cx,res);
    }
    int dp=min(cx,mx)-1;
    if(dp>=0)dis[dp]=max(dis[dp],mx+cx-dep*2+1);
    return mx;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=n+1;i++)dis[i]=0,h[i]=0;
        cnt=0;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        int mxl;
        mxl=dfs(1,0,0);
        for(int i=n;i>=0;i--)dis[i]=max(dis[i],dis[i+1]);
        int ans=0;
        for(int i=1;i<=n;i++){
            while(ans<mxl&&dis[ans]/2+i>ans)ans++;
            printf("%d ",ans);
        }
        puts("");
    }
    return  0;
}