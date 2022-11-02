#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int V=1200;
struct Point{int x,y,id,flag;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    Point operator-(const Point& p)const
    {return Point(x - p.x, y - p.y);}
}p[V],tmp[V];
int n,id[V][V],ct[V][V];
int AB(int x){if(x<0)return -x;return x;}
bool Less(Point x,Point y)
{return (LL)x.x*y.y<(LL)x.y*y.x;}
bool cmp(Point x,Point y)
{return Less(y,x);}
int N,M,po[V],id2[V][V];
void init()
{
    int i,j,top,tail,un,dn;
    for(i=0;i<N;i++)
    {
        un=0;dn=n-2;
        for(j=0;j<n;j++)
        {
            if(i==j)continue;
            if(p[j].y>=p[i].y)
            {
                tmp[un].x=p[j].x-p[i].x;
                tmp[un].y=p[j].y-p[i].y;
                tmp[un].id=p[j].id;
                tmp[un].flag=p[j].flag;
                un++;
            }
            else
            {
                tmp[dn].x=p[j].x-p[i].x;
                tmp[dn].y=p[j].y-p[i].y;
                tmp[dn].id=p[j].id;
                tmp[dn].flag=p[j].flag;
                dn--;
            }
        }
        sort(tmp,tmp+un,cmp);
        sort(tmp+dn+1,tmp+n-1,cmp);
        top=0;
        for(j=0;j<n-1;j++)
        {
            id[i][tmp[j].id]=top;
            id2[i][tmp[j].id]=j;
            if(tmp[j].flag==0)top++;
            po[j]=tmp[j].id;
        }
        top=0;tail=1;
        bool C=false;
        for(top=0;top<n-1;top++)
        {
            while(Less(tmp[tail],tmp[top])||((!C)&&top==tail))
            {tail++;if(tail==n-1){tail=0;C=true;}}
            if(C)ct[i][tmp[top].id]=id[i][po[tail]]+M-id[i][po[top]];
            else ct[i][tmp[top].id]=id[i][po[tail]]-id[i][po[top]];
        }
    }
}
int d(int x,int y,int z)
{
    if(id2[x][y]<id2[x][z])return id[x][z]-id[x][y];
    else return M+id[x][z]-id[x][y];
}
int Cal(int x,int y,int z)
{
    int ret=0;
    if(Less(p[z]-p[x],p[y]-p[x]))
    ret+=d(x,y,z)+ct[z][y];
    else ret+=d(x,z,y)+ct[y][z];
    if(Less(p[z]-p[y],p[x]-p[y]))
    ret+=d(y,x,z)+ct[z][x];
    else ret+=d(y,z,x)+ct[x][z];
    if(Less(p[y]-p[z],p[x]-p[z]))
    ret+=d(z,x,y)+ct[y][x];
    else ret+=d(z,y,x)+ct[x][y];
    ret-=2*M;
    return ret;
}
int _,ca,i,j,k;
int main()
{
    while(~scanf("%d%d",&N,&M))
    {
        for(i=0;i<N;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
        for(i=0;i<N;i++)p[i].flag=1;
        for(i=0;i<M;i++)
        scanf("%d%d",&p[i+N].x,&p[i+N].y);
        for(i=0;i<M;i++)p[i+N].flag=0;
        if(N<3){puts("0");continue;}
        if(M==0)
        {
            printf("%d\n",N*(N-1)*(N-2)/6);
            continue;
        }
        n=N+M;
        for(i=0;i<n;i++)p[i].id=i;      
        init();
        int ans=0;
        for(i=0;i<N;i++)
        for(j=i+1;j<N;j++)
        for(k=j+1;k<N;k++)
        if(Cal(i,j,k)==0)ans++;
        printf("%d\n",ans);
    }
}