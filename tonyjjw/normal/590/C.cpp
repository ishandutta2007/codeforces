//*

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef long long ll;

int N,M;

const int MN = 1000;

char buf[MN][MN+1];
int A[MN][MN];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

bool isin(int x,int y){
    return x>=0 && y>=0 && x<N && y<M;
}

int con[4][4];

int V[MN][MN];
int D[4][MN][MN];
int d[4][4];

const int INF = 1e8;

void dist(int s){
    queue<pair<int,int> > Q;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)V[i][j]=0,D[s][i][j]=INF;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(A[i][j]==s){
        V[i][j]=1;
        D[s][i][j]=0;
        Q.push(make_pair(i,j));
    }
    while(!Q.empty()){
        auto p=Q.front();
        int x=p.first;
        int y=p.second;
        for(int k=0;k<4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if(isin(nx,ny) && A[nx][ny]!=-1 && !V[nx][ny]){
                V[nx][ny]=1;
                D[s][nx][ny]=D[s][x][y]+1;
                Q.push(make_pair(nx,ny));
            }
        }
        Q.pop();
    }
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%s",buf[i]);
        for(int j=0;j<M;j++){
            if(buf[i][j]=='#')A[i][j]=-1;
            else if(buf[i][j]=='.')A[i][j]=0;
            else A[i][j]=buf[i][j]-'0';
        }
    }
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(A[i][j]>0){
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(isin(x,y) && A[x][y]>0)con[A[i][j]][A[x][y]]=1;
        }
    }
    dist(1);
    dist(2);
    dist(3);
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++)if(i!=j){
            d[i][j]=INF;
            for(int x=0;x<N;x++)for(int y=0;y<M;y++)if(A[x][y]==j){
                if(d[i][j]>D[i][x][y])d[i][j]=D[i][x][y];
            }
        }
    }
    int ans=INF;
    for(int i=1;i<=3;i++){
        if(ans>d[i][1]+d[i][2]+d[i][3]-2)ans=d[i][1]+d[i][2]+d[i][3]-2;
    }
    for(int x=0;x<N;x++)for(int y=0;y<M;y++)if(A[x][y]==0){
        if(ans>D[1][x][y]+D[2][x][y]+D[3][x][y]-2)ans=D[1][x][y]+D[2][x][y]+D[3][x][y]-2;
    }
    if(ans>INF/2)puts("-1");
    else printf("%d\n",ans);
    return 0;
}

//*/