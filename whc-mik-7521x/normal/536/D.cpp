#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,s,t,p[N];
struct edge{
    int w,to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
long long dis1[N],dis2[N],mp1[2005][2005],mp2[2005][2005];
struct node{
    long long vl;
    int num;
    bool operator<(const node b)const{
        return vl>b.vl;
    }
};
void dijkstra(long long dis[N],int st){
    for(int i=1;i<=n;i++)dis[i]=1e18;
    priority_queue<node>q;
    q.push({0,st});
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
}
long long q1(int xi,int yi,int xx,int yx){
    return mp1[xx][yx]-(xi?mp1[xi-1][yx]:0)-(yi?mp1[xx][yi-1]:0)+(xi&&yi?mp1[xi-1][yi-1]:0);
}
long long q2(int xi,int yi,int xx,int yx){
    return mp2[xx][yx]-(xi?mp2[xi-1][yx]:0)-(yi?mp2[xx][yi-1]:0)+(xi&&yi?mp2[xi-1][yi-1]:0);
}
long long dp[2005][2005][2];
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        add(x,y,w);
        add(y,x,w);
    }
    dijkstra(dis1,s);
    dijkstra(dis2,t);
    vector<long long>vec1,vec2;
    for(int i=1;i<=n;i++)vec1.push_back(dis1[i]),vec2.push_back(dis2[i]);
    stable_sort(vec1.begin(),vec1.end());
    stable_sort(vec2.begin(),vec2.end());
    vec1.erase(unique(vec1.begin(),vec1.end()),vec1.end());
    vec2.erase(unique(vec2.begin(),vec2.end()),vec2.end());
    for(int i=1;i<=n;i++)dis1[i]=lower_bound(vec1.begin(),vec1.end(),dis1[i])-vec1.begin()+1;
    for(int i=1;i<=n;i++)dis2[i]=lower_bound(vec2.begin(),vec2.end(),dis2[i])-vec2.begin()+1;
    int m1=vec1.size(),m2=vec2.size();
    for(int i=1;i<=n;i++)mp1[dis1[i]][dis2[i]]+=p[i],mp2[dis1[i]][dis2[i]]+=1;
    for(int i=1;i<=m1+1;i++){
        for(int o=1;o<=m2+1;o++){
            mp1[i][o]+=mp1[i-1][o]+mp1[i][o-1]-mp1[i-1][o-1];
            mp2[i][o]+=mp2[i-1][o]+mp2[i][o-1]-mp2[i-1][o-1];
        }
    }
    memset(dp,-63,sizeof dp);
    for(int i=1;i<=m1;i++)dp[i][m2+1][0]=dp[i][m2+1][1]=0;
    for(int i=1;i<=m2;i++)dp[m1+1][i][0]=dp[m1+1][i][1]=0;
    for(int i=m1;i>=1;i--){
        for(int o=m2;o>=1;o--){
            dp[i][o][0]=q1(i,o,i,m2)+dp[i+1][o][0];
            if(q2(i,o,i,m2))dp[i][o][0]=max(dp[i][o][0],q1(i,o,i,m2)-dp[i+1][o][1]);
            dp[i][o][1]=q1(i,o,m1,o)+dp[i][o+1][1];
            if(q2(i,o,m1,o))dp[i][o][1]=max(dp[i][o][1],q1(i,o,m1,o)-dp[i][o+1][0]);
        }
    }
    puts(dp[1][1][0]>0?"Break a heart":dp[1][1][0]==0?"Flowers":"Cry");
    return 0;
}