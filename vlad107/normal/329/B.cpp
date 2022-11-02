#include <stdio.h>
using namespace std;
int n,m,ans,qb,qe,qx[1111111],qy[1111111],d[1111][1111],sx,sy,ex,ey;
int hx[]={0,0,-1,1},hy[]={-1,1,0,0};
char a[1111][1111];
int main(){
    scanf("%d%d\n",&n,&m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%c",&a[i][j]);
            if (a[i][j]=='E'){sx=i;sy=j;}
            if (a[i][j]=='S'){ex=i;ey=j;}
        }
        if (i<n-1)scanf("\n");
    }
    qb=0;qe=1;
    qx[1]=sx;qy[1]=sy;
    for (int i=0;i<n;i++)for (int j=0;j<m;j++)d[i][j]=1000000000;
    d[sx][sy]=0;
    while (qb<qe){
        qb++;
        int x=qx[qb],y=qy[qb];
        for (int i=0;i<4;i++){
            int cx=x+hx[i],cy=y+hy[i];
            if ((cx<0)||(cy<0)||(cx>=n)||(cy>=m))continue;
            if (a[cx][cy]=='T')continue;
            if (d[x][y]+1>=d[cx][cy])continue;
            d[cx][cy]=d[x][y]+1;
            qe++;qx[qe]=cx;qy[qe]=cy;
        }
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if ((a[i][j]>='0')&&(a[i][j]<='9')&&(d[i][j]<=d[ex][ey]))ans+=a[i][j]-'0';
    printf("%d\n",ans);
}