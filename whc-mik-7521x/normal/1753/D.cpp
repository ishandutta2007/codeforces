#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
int n,m,p,q;
int num(int x,int y){
    return (x-1)*m+y;
}
long long dis[N];
vector<int>mp[N];
string mpp[N];
struct edge{
    int w,to,nxt;
};
edge ed[N<<2];
int cnt,h[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
bool pd(int x,int y){
    if(x<1||x>n||y<1||y>m||mp[x][y])return 0;
    return 1;
}
void ad(int x,int y,int xx,int yy,int w){
    if(pd(x,y)&&pd(xx,yy))add(num(xx,yy),num(x,y),w);
}
struct node{
    long long vl;
    int num;
    bool operator<(const node b)const{
        return vl>b.vl;
    }
};
int main(){
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=1;i<=n;i++){
        cin>>mpp[i];
        mp[i].resize(m+1);
        for(int o=1;o<=m;o++){
            mp[i][o]=mpp[i][o-1]=='#';
        }
    }
    for(int i=1;i<=n;i++){
        for(int o=1;o<=m;o++){
            char s=mpp[i][o-1];
            if(s=='L')ad(i,o+1,i+1,o,p),ad(i,o+1,i-1,o,p),ad(i,o+1,i,o-1,q);
            if(s=='R')ad(i,o-1,i+1,o,p),ad(i,o-1,i-1,o,p),ad(i,o-1,i,o+1,q);
            if(s=='U')ad(i+1,o,i,o+1,p),ad(i+1,o,i,o-1,p),ad(i+1,o,i-1,o,q);
            if(s=='D')ad(i-1,o,i,o+1,p),ad(i-1,o,i,o-1,p),ad(i-1,o,i+1,o,q);
        }
    }
    memset(dis,63,sizeof dis);
    priority_queue<node>q;
    for(int i=1;i<=n;i++){
        for(int o=1;o<=m;o++){
            if(mpp[i][o-1]=='.')q.push(node{0,num(i,o)});
        }
    }
    while(q.size()){
        auto [vl,x]=q.top();
        q.pop();
        if(vl>=dis[x])continue;
        dis[x]=vl;
        for(int i=h[x];i;i=ed[i].nxt){
            int v=ed[i].to;
            q.push(node{vl+ed[i].w,v});
        }
    }
    long long ans=1e18;
    for(int i=1;i<=n;i++){
        for(int o=1;o<m;o++){
            ans=min(ans,dis[num(i,o)]+dis[num(i,o+1)]);
        }
    }
    for(int i=1;i<n;i++){
        for(int o=1;o<=m;o++){
            ans=min(ans,dis[num(i,o)]+dis[num(i+1,o)]);
        }
    }
    printf("%lld",ans<1e17?ans:-1ll);
    return 0;
}