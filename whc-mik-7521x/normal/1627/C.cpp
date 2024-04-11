#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct edge{
    int w,to,nex;
};
edge ed[N<<1];
int cnt,h[N],deg[N],ans[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
void dfs(int x,int fa,int nx){
    for(int i=h[x];i;i=ed[i].nex){
        if(ed[i].to==fa)continue;
        ans[ed[i].w]=13-nx;
        dfs(ed[i].to,x,13-nx);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)h[i]=0,deg[i]=0;
        cnt=0;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y,i);
            add(y,x,i);
            deg[x]++,deg[y]++;
        }
        int pd=0;
        for(int i=1;i<=n;i++)if(deg[i]>2)pd=1;
        if(pd){puts("-1");continue;}
        for(int i=1;i<=n;i++){
            if(deg[i]==1){dfs(i,0,2);break;}
        }
        for(int i=1;i<n;i++)printf("%d ",ans[i]);
        puts("");
    }   
    return  0;
}