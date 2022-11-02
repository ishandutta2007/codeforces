/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=3010;
struct Point
{
    int x,y;
};
struct Rec
{
    Point a,b;
}a[100100];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int mx[V][V][4];
bool dr[V][V][4];
Point ls[V];
int ret[100100];
int cl[V][V],s[V][V];
int sum(int lx,int ly,int l)
{
    int rx=lx+l;
    int ry=ly+l;
    return s[rx][ry]+s[lx][ly]-s[lx][ry]-s[rx][ly];
}
int va[V];
struct Node{int l,r,id;}tr[V*4];
void init(int id,int l,int r)
{
    //printf("%d %d %d\n",id,l,r);
    tr[id].l=l;
    tr[id].r=r;
    if(l==r)
    {
        tr[id].id=l;
        return;
    }
    int mid=(l+r)/2;
    init(id*2,l,mid);
    init(id*2+1,mid+1,r);
    if(va[tr[id*2].id]<va[tr[id*2+1].id])
    tr[id].id=tr[id*2].id;
    else tr[id].id=tr[id*2+1].id;
}
int Min(int id,int l,int r)
{
    //printf("%d %d %d\n",id,l,r);
    if(tr[id].l==l&&tr[id].r==r)
    return tr[id].id;
    int mid=(tr[id].l+tr[id].r)/2;
    if(r<=mid)return Min(id*2,l,r);
    else if(l>mid)return Min(id*2+1,l,r);
    else
    {
        int a=Min(id*2,l,mid);
        int b=Min(id*2+1,mid+1,r);
        if(va[a]<va[b])return a;
        else return b;
    }
}
int m,sa[V];
int main()
{
    while(~scanf("%d",&m))
    {
        int n=3001;
        //n=10;
        memset(dr,0,sizeof(dr));
        memset(cl,0,sizeof(cl));
        memset(s,0,sizeof(s));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&a[i].a.x,&a[i].a.y,&a[i].b.x,&a[i].b.y);
            for(int j=a[i].a.x;j<a[i].b.x;j++)
            dr[j][a[i].a.y][1]=1,dr[j][a[i].b.y][1]=1;
            for(int j=a[i].a.x+1;j<=a[i].b.x;j++)
            dr[j][a[i].a.y][3]=1,dr[j][a[i].b.y][3]=1;
            for(int j=a[i].a.y;j<a[i].b.y;j++)
            dr[a[i].a.x][j][0]=1,dr[a[i].b.x][j][0]=1;
            for(int j=a[i].a.y+1;j<=a[i].b.y;j++)
            dr[a[i].a.x][j][2]=1,dr[a[i].b.x][j][2]=1;

            for(int j=a[i].a.x+1;j<=a[i].b.x;j++)
            for(int k=a[i].a.y+1;k<=a[i].b.y;k++)
            cl[j][k]=1;
        }

        for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
        s[i][j]=s[i][j-1]+s[i-1][j]+cl[i][j]-s[i-1][j-1];

        for(int x=0;x<n;x++)
        {
            mx[x][0][2]=0;
            for(int y=1;y<n;y++)
            if(dr[x][y][2])
            mx[x][y][2]=mx[x][y-1][2]+1;
            else mx[x][y][2]=0;

            mx[x][n-1][0]=0;
            for(int y=n-2;y>=0;y--)
            if(dr[x][y][0])
            mx[x][y][0]=mx[x][y+1][0]+1;
            else mx[x][y][0]=0;
        }

        for(int y=0;y<n;y++)
        {
            mx[0][y][3]=0;
            for(int x=1;x<n;x++)
            if(dr[x][y][3])
            mx[x][y][3]=mx[x-1][y][3]+1;
            else mx[x][y][3]=0;

            mx[n-1][y][1]=0;
            for(int x=n-2;x>=0;x--)
            if(dr[x][y][1])
            mx[x][y][1]=mx[x+1][y][1]+1;
            else mx[x][y][1]=0;
        }
        //for(int i=n-1;i>=0;i--,puts(""))
        //for(int j=0;j<n;j++)printf("%d ",mx[j][i][0]);
        //printf("%d %d %d %d\n",mx[8][8][0],mx[8][8][1],mx[8][8][2],mx[8][8][3]);
        int lx=-1,ly=-1,rx=-1,ry=-1;
        for(int ds=n-1;ds>=-(n-1);ds--)
        {
            if(lx!=-1)break;
            int nx,ny;
            if(ds>=0)nx=0,ny=ds;
            else ny=0,nx=-ds;
            int t=0;
            //printf("%d %d %d\n",ds,nx,ny);
            for(int i=0;;i++)
            {
                if(nx+i>=n||ny+i>=n)break;
                ls[t].x=nx+i;
                ls[t++].y=ny+i;
            }

            sa[0]=0;
            while(sum(ls[0].x,ls[0].y,sa[0]+1)==(sa[0]+1)*(sa[0]+1))
            sa[0]++;
            for(int i=1;i<t;i++)
            {
                sa[i]=max(0,sa[i-1]-1);
                while(sum(ls[i].x,ls[i].y,sa[i]+1)==(sa[i]+1)*(sa[i]+1))
                sa[i]++;
            }

            for(int i=0;i<t;i++)
            {
                va[i]=i-min(mx[ls[i].x][ls[i].y][2],mx[ls[i].x][ls[i].y][3]);
            }
            //printf("\nD %d\n",ds);
            //for(int i=0;i<t;i++)printf("%d ",va[i]);puts("");
            init(1,0,t-1);
            for(int i=0;i<t;i++)
            {
                int d=min(sa[i],min(mx[ls[i].x][ls[i].y][0]
                    ,mx[ls[i].x][ls[i].y][1]));
                    //printf("%d",d);
                if(d==0)continue;
                int id=Min(1,i+1,i+d);
                if(va[id]<=i)
                {
                    lx=ls[i].x;
                    ly=ls[i].y;
                    rx=ls[id].x;
                    ry=ls[id].y;
                    break;
                }
            }
        }
        if(lx==-1)puts("NO");
        else
        {
            int t=0;
            for(int i=0;i<m;i++)
            if(a[i].a.x>=lx&&a[i].a.x<=rx&&a[i].a.y>=ly&&a[i].a.y<=ry
                &&a[i].b.x>=lx&&a[i].b.x<=rx&&a[i].b.y>=ly&&a[i].b.y<=ry)
            {
                ret[t++]=i+1;
            }
            printf("YES %d\n",t);
            //printf("%d %d %d %d\n",lx,ly,rx,ry);
            for(int i=0;i<t;i++)printf("%d ",ret[i]);puts("");
        }
    }
    return 0;
}