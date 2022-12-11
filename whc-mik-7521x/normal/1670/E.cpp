#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct edge{
    int to,nxt,num;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et,int num){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    ed[cnt].num=num;
    h[st]=cnt;
}
int t,p,n,val[N],ans[N],ct;
void dfs(int x,int fa,int pd){
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        ans[ed[i].num]=pd?n+ct:ct;
        val[v]=pd?ct++:n+(ct++);
        dfs(v,x,!pd);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&p);
        n=1<<p;
        ct=1;
        cnt=0;
        for(int i=1;i<=n;i++)h[i]=0;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y,i);
            add(y,x,i);
        }
        dfs(1,0,1);
        val[1]=n;
        puts("1");
        for(int i=1;i<=n;i++)printf("%d ",val[i]);
        puts("");
        for(int i=1;i<n;i++)printf("%d ",ans[i]);
        puts("");
    }
    return  0;
}