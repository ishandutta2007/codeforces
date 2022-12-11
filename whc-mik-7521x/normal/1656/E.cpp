#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N],val[N],deg[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
void dfs(int x,int fa,int col){
    val[x]=col*deg[x];
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x,-col);
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
            add(x,y);
            add(y,x);
            deg[x]++;
            deg[y]++;
        }
        val[1]=1;
        dfs(1,0,1);
        for(int i=1;i<=n;i++){
            printf("%d%c",val[i],i==n?'\n':' ');
        }
    }
    return  0;
}