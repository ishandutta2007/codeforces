#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int cnt[N],ans[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        int vis[n+2][m+2];
        memset(vis,-1,sizeof vis);
        for(int i=1;i<=n+m;i++)cnt[i]=0;
        for(int i=1;i<=n*m;i++)ans[i]=0;
        int ord=0;
        queue<pair<int,int> >q;
        if(n%2==0&&m%2==0){
            ord=n/2+m/2;
            q.push({n/2,m/2});
            q.push({n/2+1,m/2});
            q.push({n/2,m/2+1});
            q.push({n/2+1,m/2+1});
            vis[n/2][m/2]=1;
            vis[n/2+1][m/2]=1;
            vis[n/2][m/2+1]=1;
            vis[n/2+1][m/2+1]=1;
        }
        if(n%2==0&&m%2==1){
            ord=n/2+m/2;
            q.push({n/2,m/2+1});
            q.push({n/2+1,m/2+1});
            vis[n/2][m/2+1]=1;
            vis[n/2+1][m/2+1]=1;
        }
        if(m%2==0&&n%2==1){
            ord=n/2+m/2;
            q.push({n/2+1,m/2});
            q.push({n/2+1,m/2+1});
            vis[n/2+1][m/2]=1;
            vis[n/2+1][m/2+1]=1;
        }
        if(m%2==1&&n%2==1){
            ord=n/2+m/2;
            q.push({n/2+1,m/2+1});
            vis[n/2+1][m/2+1]=1;
        }
        while(q.size()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            cnt[vis[x][y]]++;
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>0&&nx<=n&&ny>0&&ny<=m&&vis[nx][ny]==-1)q.push({nx,ny}),vis[nx][ny]=vis[x][y]+1;
            }
        }
        for(int i=1;i<=n+m;i++)cnt[i]+=cnt[i-1],ans[cnt[i]]=1;
        ans[0]=ord;
        for(int i=1;i<n*m;i++)ans[i]+=ans[i-1];
        for(int i=0;i<n*m;i++)printf("%d ",ans[i]);
        puts("");
    }
    return  0;
}