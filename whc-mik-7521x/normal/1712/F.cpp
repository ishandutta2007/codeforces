#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
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
int n,ans[N],q,dep[N],f[N],deg[N],X[N],len[N],hs[N];
void solve(int x,int fa){
    dep[x]=dep[fa]+1;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        solve(v,x);
        len[x]=max(len[x],len[v]+1);
        if(len[v]>=len[hs[x]])hs[x]=v;
    }
}
void merge(vector<int>&res,vector<int>now,int lca){
    if(res.size()<now.size())res.swap(now);
    for(int kk=1;kk<=q;kk++){
        for(int i=0;i<(int)now.size();i++)while(max(0,ans[kk]-i-X[kk])<(int)res.size()&&res[max(0,ans[kk]-i-X[kk])]+now[i]-2*lca>=ans[kk])ans[kk]++;
    }
    for(int i=0;i<(int)now.size();i++)res[i]=max(res[i],now[i]);
}
vector<int>dfs(int x,int fa){
    vector<int>res;
    if(hs[x])merge(res,dfs(hs[x],x),dep[x]);
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa||v==hs[x])continue;
        auto it=dfs(v,x);
        merge(res,it,dep[x]);
    }
    int j;
    for(int i=1;i<=q;i++){
        while(j=max(0,ans[i]-f[x]-X[i]),j<(int)res.size()&&res[j]-dep[x]>=ans[i])ans[i]++;
        if(f[x]>=(int)res.size())res.push_back(dep[x]);
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        add(x,i);
        add(i,x);
        deg[x]++;
        deg[i]++;
    }
    queue<int>que;
    memset(f,-1,sizeof f);
    for(int i=1;i<=n;i++)if(deg[i]==1)que.push(i),f[i]=0;
    while(que.size()){
        int x=que.front();
        que.pop();
        for(int i=h[x];i;i=ed[i].nxt){
            int v=ed[i].to;
            if(f[v]==-1)f[v]=f[x]+1,que.push(v);
        }
    }
    solve(1,0);
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&X[i]);
    }
    dfs(1,0);
    for(int i=1;i<=q;i++)printf("%d ",ans[i]-1);
    return 0;
}