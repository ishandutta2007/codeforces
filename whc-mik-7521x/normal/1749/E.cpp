#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,dx[]={1,1,-1,-1},dy[]={-1,1,-1,1};
int n,m;
vector<int>mp[N],dis[N];
vector<pair<int,int>>pre[N];
struct node{
    int x,y,val,fx,fy;
    bool operator<(const node b)const{
        return val>b.val;
    }
};
char s[N];
bool check(int x,int y){
    if(x>n||y>m||x<1||y<1)return 0;
    return !(mp[x-1][y]+mp[x][y-1]+mp[x+1][y]+mp[x][y+1]);
}
void print(){
    for(int i=1;i<=n;i++){
        for(int o=1;o<=m;o++){
            printf(mp[i][o]?"#":".");
        }
        puts("");
    }
}
void calc(int x,int y){
    if(!x||!y)return;
    mp[x][y]=1;
    calc(pre[x][y].first,pre[x][y].second);
}
int main(){
    int t;
    scanf("%d",&t);
    mp[0].resize(N);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            mp[i].resize(m+2);
            dis[i].resize(m+1);
            pre[i].resize(m+1);
            for(int o=1;o<=m;o++){
                mp[i][o]=s[o]=='#';
                dis[i][o]=1e9;
            }
            mp[i][m+1]=0;
        }
        mp[n+1].resize(m+2);
        for(int i=1;i<=m+1;i++)mp[n+1][i]=0;
        priority_queue<node>q;
        for(int i=1;i<=n;i++){
            if(check(i,1))q.push({i,1,1-mp[i][1],0,0});
        }
        while(q.size()){
            auto [x,y,vl,fx,fy]=q.top();
            q.pop();
            if(vl>=dis[x][y])continue;
            dis[x][y]=vl;
            pre[x][y]={fx,fy};
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(check(nx,ny))
                q.push({nx,ny,vl+1-mp[nx][ny],x,y});
            }
        }
        int ans=1e9;
        for(int i=1;i<=n;i++)ans=min(ans,dis[i][m]);
        if(ans>1e8){puts("NO");continue;}
        puts("YES");
        for(int i=1;i<=n;i++){
            if(dis[i][m]==ans){calc(i,m);print();break;}
        }
    }
    return 0;
}