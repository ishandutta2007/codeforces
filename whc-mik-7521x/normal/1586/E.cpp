#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;}
void init(int x){for(int i=0;i<=x;i++)fa[i]=i;}
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int n,m,q,ct[N];
pair<int,int>qu[N];
int f[N],dep[N];
void dfs(int x,int y){
    f[x]=y;
    dep[x]=dep[y]+1;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==y)continue;
        dfs(v,x);
    }
}
vector<int>sea(int x,int y){
    vector<int>v1,v2;
    v1.push_back(x);
    v2.push_back(y);
    while(x!=y){
        if(dep[x]>=dep[y])x=f[x],v1.push_back(x);
        else y=f[y],v2.push_back(y);
    }
    v2.pop_back();
    reverse(v2.begin(),v2.end());
    v1.insert(v1.end(),v2.begin(),v2.end());
    return v1;
}
void print(vector<int>x){
    printf("%d\n",(int)x.size());
    for(int i:x)printf("%d ",i);
    puts("");
}
int main(){
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(find(x)!=find(y))add(x,y),add(y,x),unnion(find(x),find(y));
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        auto &[x,y]=qu[i];
        scanf("%d%d",&x,&y);
        ct[x]++;
        ct[y]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(ct[i]&1)ans++;
    }
    if(!ans){
        dfs(1,0);
        puts("YES");
        for(int i=1;i<=q;i++)print(sea(qu[i].first,qu[i].second));
    }
    else{
        printf("NO\n%d",(ans>>1));
    }
    return  0;
}