#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int fa[N<<1];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;}
int n,m;
struct edge{
    int w,to,nex;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
void init(int x){
    for(int i=0;i<=(x<<1);i++)fa[i]=i;
    for(int i=0;i<=x;i++)h[i]=0;
    cnt=0;
}
int pop_count(int x){
    int res=0;
    while(x){
        x-=x&-x;
        res++;
    }
    return res;
}
void dfs(int x,int f){
    for(int i=h[x];i;i=ed[i].nex){
        if(ed[i].to==f)continue;
        if(ed[i].w==-1){
            if(find(x)==find(ed[i].to))ed[i].w=0;
            else if(find(x)==find(ed[i].to+n))ed[i].w=1;
            else{
                unnion(find(x),find(ed[i].to));
                unnion(find(x+n),find(ed[i].to+n));
                ed[i].w=0;
            }
        }
        printf("%d %d %d\n",x,ed[i].to,ed[i].w);
        dfs(ed[i].to,x);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init(n);
        for(int i=1;i<n;i++){
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            add(x,y,w);
            add(y,x,w);
            if(w!=-1){
                if(pop_count(w)&1){
                    unnion(find(x),find(y+n));
                    unnion(find(y),find(x+n));
                }
                else{
                    unnion(find(x),find(y));
                    unnion(find(x+n),find(y+n));
                }
            }
        }
        int pd=0;
        for(int i=1;i<=m;i++){
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            if((w&1)){
                if(find(x)==find(y)){
                    pd=1;
                }
                else{
                    unnion(find(x),find(y+n));
                    unnion(find(x+n),find(y));
                }
            }
            else{
                if(find(x)==find(y+n)){
                    pd=1;
                }
                else{
                    unnion(find(x+n),find(y+n));
                    unnion(find(x),find(y));
                }
            }
        }
        if(pd){puts("NO");continue;}
        puts("YES");
        dfs(1,0);
    }
    return  0;
}