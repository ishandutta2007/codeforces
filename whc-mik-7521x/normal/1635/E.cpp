#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct edge{
    int to,nex;
};
edge ed[N<<1],de[N<<1];
int cnt,h[N],col[N],ct,head[N],deg[N],pos[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
void ad(int st,int et){
    ct++;
    de[ct].to=et;
    de[ct].nex=head[st];
    head[st]=ct;
    deg[et]++;
}
struct stm{
    int tp,x,y;
}a[N];
int n,m,pd;
void dfs(int x){
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(!col[v]){
            col[v]=3-col[x];
            dfs(v);
        }
        else{
            if(col[v]+col[x]!=3)pd=1;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].tp,&a[i].x,&a[i].y);
        add(a[i].x,a[i].y);
        add(a[i].y,a[i].x);
    }
    for(int i=1;i<=n;i++){
        if(!col[i])col[i]=1,dfs(i);
    }
    if(pd)return puts("NO"),0;
    for(int i=1;i<=m;i++){
        if(a[i].tp==1){
            if(col[a[i].x]==1){
                ad(a[i].x,a[i].y);
            }
            else{
                ad(a[i].y,a[i].x);
            }
        }
        else{
            if(col[a[i].x]==1){
                ad(a[i].y,a[i].x);
            }
            else{
                ad(a[i].x,a[i].y);
            }
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!deg[i])q.push(i);
    }
    int lty=0;
    while(q.size()){
        int now=q.front();
        q.pop();
        pos[now]=++lty;
        for(int i=head[now];i;i=de[i].nex){
            int v=de[i].to;
            deg[v]--;
            if(!deg[v])q.push(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(!pos[i])return puts("NO"),0;
    }
    puts("YES");
    for(int i=1;i<=n;i++){
        printf("%c %d\n",col[i]==1?'L':'R',pos[i]);
    }
    return  0;
}