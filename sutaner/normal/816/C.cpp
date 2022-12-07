#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 2000000005
#define maxn 105
#define maxn2 1000005
int grid[maxn][maxn];
struct ope{
    int type,idx,num;
    ope(int type,int idx,int num):type(type),idx(idx),num(num){}
    ope(){}
}save[maxn2];
int cnt=0;
int main(){
    /*freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);*/
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    int ans=0;
    if(n<m){
        for(int i=1;i<=n;i++){
            int minnum=INF;
            for(int j=1;j<=m;j++){
                minnum=min(minnum,grid[i][j]);
            }
            if(minnum>0){
                for(int j=1;j<=m;j++){
                    grid[i][j]-=minnum;
                }
                save[++cnt]=ope(1,i,minnum);
                ans+=minnum;
            }
        }
        for(int j=1;j<=m;j++){
            int minnum=INF;
            for(int i=1;i<=n;i++){
                minnum=min(minnum,grid[i][j]);
            }
            if(minnum>0){
                for(int i=1;i<=n;i++){
                    grid[i][j]-=minnum;
                }
                save[++cnt]=ope(2,j,minnum);
                ans+=minnum;
            }
        }
    }
    else{
        for(int j=1;j<=m;j++){
            int minnum=INF;
            for(int i=1;i<=n;i++){
                minnum=min(minnum,grid[i][j]);
            }
            if(minnum>0){
                for(int i=1;i<=n;i++){
                    grid[i][j]-=minnum;
                }
                save[++cnt]=ope(2,j,minnum);
                ans+=minnum;
            }
        }
        for(int i=1;i<=n;i++){
            int minnum=INF;
            for(int j=1;j<=m;j++){
                minnum=min(minnum,grid[i][j]);
            }
            if(minnum>0){
                for(int j=1;j<=m;j++){
                    grid[i][j]-=minnum;
                }
                save[++cnt]=ope(1,i,minnum);
                ans+=minnum;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]!=0){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<save[i].num;j++){
            if(save[i].type==1)printf("row %d\n",save[i].idx);
            else printf("col %d\n",save[i].idx);
        }
    }
    return 0;
}