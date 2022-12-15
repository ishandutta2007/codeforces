#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 55;
int n, i, j, a[MN][MN], d[MN][MN], xr, ok[MN][MN][MN][MN];
int dx[]={-2,-1,0,0,1,2}, dy[]={0,-1,-2,2,1,0};

int qu(int x,int y,int i,int j){
    printf("? %d %d %d %d\n",x,y,i,j);
    fflush(stdout); int g;
    scanf("%d",&g); return g;
}

int rec(int x1,int y1,int x2,int y2){
    if(abs(x1-x2)+abs(y1-y2)<=1) return 1;
    else if(ok[x1][y1][x2][y2]!=-1) return ok[x1][y1][x2][y2];
    int hmmmm = 0;
    for(int i=0;i<2;i++){
        int nx1 = x1+i, ny1 = y1+(!i);
        if(nx1>x2||ny1>y2) continue;
        for(int j=0;j<2;j++){
            int nx2 = x2-j, ny2 = y2-(!j);
            if(nx2<nx1||ny2<ny1) continue;
            if(a[nx1][ny1]==a[nx2][ny2]) hmmmm |= rec(nx1,ny1,nx2,ny2);
        }
    }
    ok[x1][y1][x2][y2] = hmmmm;
    return hmmmm;
}

int main(){
    scanf("%d",&n);
    a[1][1] = 1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if((i==1&&j==1)||(i==n&&j==n)) continue;
            if((i+j)%2==0){
                for(int k=0;k<6;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx<1||nx>i||ny<1||ny>j) continue;
                    if(qu(nx,ny,i,j)) a[i][j]=a[nx][ny];
                    else a[i][j]=!a[nx][ny];
                    break;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if((i+j)%2==0) continue;
            if(i==1&&j==2) d[i][j]=1;
            if(!d[i][j]&&(i!=1||j!=2)){
                for(int k=0;k<6;k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx<1||nx>n||ny<1||ny>n) continue;
                    if(d[nx][ny]){
                        if(qu(min(nx,i),min(ny,j),max(nx,i),max(ny,j))) a[i][j]=a[nx][ny];
                        else a[i][j]=!a[nx][ny];
                        d[i][j] = 1;
                        break;
                    }
                }
            }
            for(int k=0;k<6;k++){
                int nx = i+dx[k], ny = j+dy[k];
                if(nx<1||nx>n||ny<1||ny>n) continue;
                if(!d[nx][ny]){
                    if(qu(min(nx,i),min(ny,j),max(nx,i),max(ny,j))) a[nx][ny]=a[i][j];
                    else a[nx][ny]=!a[i][j];
                    d[nx][ny] = 1;
                }
            }
        }
    }
    for(int k=0;k<2;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if((i+j)&1) a[i][j]^=k;
            }
        }
        memset(ok,-1,sizeof(ok));
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                for(int ii=i;ii<=n;ii++){
                    for(int jj=j;jj<=n;jj++){
                        if(ii-i+jj-j>=2&&a[i][j]==a[ii][jj]&&(i+j)%2!=(ii+jj)%2){
                            if(rec(i,j,ii,jj)){
                                xr = !qu(i,j,ii,jj);
                                printf("!\n");
                                for(i=1;i<=n;i++){
                                    for(j=1;j<=n;j++){
                                        if((i+j)&1) printf("%d",a[i][j]^xr);
                                        else printf("%d",a[i][j]);
                                    }
                                    printf("\n");
                                }
                                fflush(stdout);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}