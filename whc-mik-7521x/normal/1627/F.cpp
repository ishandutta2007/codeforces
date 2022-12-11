#include<bits/stdc++.h>
using namespace std;
const int N=520;
int dis[N][N],t,n,k,mov[N][N][4];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
void add(int x,int y,int xx,int yy){
    if(x==xx){
        if(y>yy)swap(y,yy);
        mov[xx][yy][2]++;
        mov[xx+1][yy][0]++;
    }
    else{
        if(x>xx)swap(x,xx);
        mov[xx][yy][1]++;
        mov[xx][yy+1][3]++;
    }
}
struct node{
    int x,y,dis;
    bool operator<(const node b)const{
        return dis>b.dis;
    }
};
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k+1;i++){
            for(int o=1;o<=k+1;o++){
                for(int j=0;j<4;j++){
                    mov[i][o][j]=0;
                }
                dis[i][o]=-1;
            }
        }
        for(int i=1;i<=n;i++){
            int x,y,xx,yy;
            scanf("%d%d%d%d",&x,&y,&xx,&yy);
            add(x,y,xx,yy);
            add(k+1-x,k+1-y,k+1-xx,k+1-yy);
        }
        priority_queue<node>q;
        q.push({k/2+1,k/2+1,0});
        while(q.size()){
            node now=q.top();
            q.pop();
            if(dis[now.x][now.y]!=-1)continue;
            dis[now.x][now.y]=now.dis;
            for(int i=0;i<4;i++){
                int nx=now.x+dx[i],ny=now.y+dy[i];
                if(nx>0&&nx<=k+1&&ny>0&&ny<=k+1)q.push({nx,ny,now.dis+mov[now.x][now.y][i]});
            }
        }
        int ans=1e9;
        for(int i=1;i<=k+1;i++)ans=min(ans,min(dis[1][i],dis[i][1]));
        printf("%d\n",n-ans);
    }
    return  0;
}