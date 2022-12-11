#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,t,fa[N],siz[N];
struct edge{
    int x,y,w;
}ed[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;siz[x]+=siz[y];}
void init(int x){for(int i=0;i<=x;i++)fa[i]=i,siz[i]=1;}
bool check(int now){
    init(n);
    for(int i=1;i<=m;i++){
        if(!(ed[i].w&now))if(find(ed[i].x)!=find(ed[i].y))unnion(find(ed[i].x),find(ed[i].y));
    }
    return siz[find(1)]==n;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&ed[i].x,&ed[i].y,&ed[i].w);
        }
        int ans=0;
        for(int i=30;i>=0;i--){
            ans|=(1<<i);
            if(!check(ans))ans^=(1<<i);
        }
        printf("%lld\n",(1ll<<31)-1-ans);
    }   
    return  0;
}