#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=55;
int n,m,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
char s[N][N];
bool was[N][N];
bool Valid(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
void BFS(int x,int y){
    deque<pair<int,int>> q;
    q.pb({x,y});
    was[x][y]=1;
    while(!q.empty()){
        auto c=q[0];
        was[c.first][c.second]=1;
        for(int dir=0;dir<4;dir++){
            int nx=c.first+dx[dir],ny=c.second+dy[dir];
            if(Valid(nx,ny)&&s[nx][ny]!='#'&&!was[nx][ny]){
                q.pb({nx,ny}),was[nx][ny]=1;
            }
        }
        q.pop_front();
    }
}
int main(){
    int t;scanf("%i",&t);
    while(t--){
        scanf("%i %i",&n,&m);
        for(int i=0;i<n;i++)scanf("%s",&s[i]);
        bool ok=1;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]=='B'){
            for(int dir=0;dir<4;dir++){
                int x=i+dx[dir],y=j+dy[dir];
                if(Valid(x,y)&&s[x][y]=='G')ok=0;
                else if(Valid(x,y)&&s[x][y]=='.')s[x][y]='#';
            }
        }
        if(!ok){
            printf("No\n");
            continue;
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)was[i][j]=0;
        if(s[n-1][m-1]!='#')BFS(n-1,m-1);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(was[i][j]&&s[i][j]=='B')ok=0;
            if(!was[i][j]&&s[i][j]=='G')ok=0;
        }
        if(ok)printf("Yes\n");
        else printf("No\n");
    }
}