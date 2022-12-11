#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct edge{
    int to,nex;
};
edge ed[N<<1];
int cnt,h[N],ans[N],fi1[N],fi2[N],cnt1,cnt2,len1,len2,siz[N];
bool cz[40];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
void solve(int x){
    memset(cz,0,sizeof cz);
    int now=len1,au1=0,au2=0;
    while(now){
        int kk=now&-now;
        now-=kk;
        cz[siz[kk]]=1;
        for(int i=kk;i<kk<<1;i++)fi1[++au1]=i;
    }
    int i;
    for(i=1;i<=x>>1;i<<=1){
        if(cz[siz[i]])continue;
        for(int k=i;k<i<<1;k++)fi2[++au2]=k;
    }
    for(;i<=x;i++)fi2[++au2]=i;
}
int dfn(int x,int f,int tt){
    int res=0;
    if(!tt)res=1;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==f)continue;
        res+=dfn(v,x,1-tt);
    }
    return res;
}
void dfs(int x,int f,int nu){
    if(!nu){
        ans[x]=(cnt1==len1)?fi2[++cnt2]:fi1[++cnt1];
    }
    else ans[x]=(cnt2==len2)?fi1[++cnt1]:fi2[++cnt2];
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==f)continue;
        dfs(v,x,1-nu);
    }
}
int main(){
    int ll=0;
    for(int i=1;i<N;i<<=1)siz[i]=++ll; 
    int t;
    scanf("%d",&t);
    while(t--){
        cnt1=cnt2=0;
        int n;
        cnt=0;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        len1=dfn(1,0,0);
        len2=n-len1;
        int kkk=0;
        if(len1>len2)swap(len1,len2),kkk=1;
        solve(n);
        dfs(1,0,kkk);
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        puts("");
        for(int i=1;i<=n;i++)h[i]=0;
    }
    return  0;
}