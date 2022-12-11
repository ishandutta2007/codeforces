#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,len[N],loson[N],fa[N],siz[N],k;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;siz[x]+=siz[y];}
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
void dfs(int x,int fa){
    int lg=0,ls=0;
    len[x]=1;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        len[x]=max(len[x],len[v]+1);
        if(len[v]>lg)lg=len[v],ls=v;
    }
    loson[x]=ls;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(!loson[i])continue;
        if(find(i)!=find(loson[i]))unnion(find(i),find(loson[i]));
    }
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(fa[i]==i)v.push_back(siz[i]);
    }
    sort(v.begin(),v.end(),[](int b1,int b2){return b1>b2;});
    long long tot=0;
    for(int i=0;i<(int)v.size()&&i<k;i++){
        tot+=v[i];
    }
    long long b=min(n>>1,n-(int)tot),r=k;
    if((int)v.size()<=k)r=max(min(n>>1,k),(int)v.size());
    printf("%lld",(n*1ll-r-b)*(r-b));
    return  0;
}