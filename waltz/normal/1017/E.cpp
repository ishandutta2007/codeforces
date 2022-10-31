#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct point
{
    int x;
    int y;
    point (int xx=0,int yy=0)
    {
        x=xx;
        y=yy;
    }
    friend point operator - (const point &a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend long long operator * (const point &a,const point &b)
    {
        return (long long)a.x*b.y-(long long)b.x*a.y;
    }
    long long length() const
    {
        return (long long)x*x+(long long)y*y;
    }
    friend bool operator < (const point &a,const point &b)
    {
        if (a*b==0)
        {
            return a.length()<b.length();
        }
        return a*b<0;
    }
    void read()
    {
        scanf("%d%d",&x,&y);
    }
};
point a[100005];
point b[100005];
const int p[5]={131,149,191,233,271};
const int modo[5]={200003,300007,400009,500009,700001};
int power(int x,int y,int modo)
{
    if (y==0) return 1;
    int t=power(x,y/2,modo);
    t=(long long)t*t%modo;
    if (y%2==1)
    {
        t=(long long)t*x%modo;
    }
    return t;
}
bool check(int n,int m)
{
    if (n!=m)
    {
        return false;
    }
    a[n]=a[0];
    a[n+1]=a[1];
    b[m]=b[0];
    b[m+1]=b[1];
    int i,j;
    long long val_a[15];
    long long val_b[15];
    long long val_c[15];
    long long val_d[15];
    for (i=0;i<5;i++)
    {
        val_a[i]=0;
    }
    for (i=0;i<5;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            val_a[i]=(val_a[i]*p[i]+(a[j]-a[j+1]).length())%modo[i];
        }
    }
    for (i=0;i<5;i++)
    {
        val_b[i]=0;
    }
    for (i=0;i<5;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            val_b[i]=(val_b[i]*p[i]+(b[j]-b[j+1]).length())%modo[i];
        }
    }
    for (i=0;i<5;i++)
    {
        val_c[i]=0;
    }
    for (i=0;i<5;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            val_c[i]=(val_c[i]*p[i]+(a[j]-a[j+1])*(a[j+1]-a[j+2]))%modo[i];
            if (val_c[i]<0) val_c[i]+=modo[i];
        }
    }
    for (i=0;i<5;i++)
    {
        val_d[i]=0;
    }
    for (i=0;i<5;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            val_d[i]=(val_d[i]*p[i]+(b[j]-b[j+1])*(b[j+1]-b[j+2]))%modo[i];
            if (val_d[i]<0) val_d[i]+=modo[i];
        }
    }
    for (j=0;j<n;j++)
    {
        int i;
        for (i=0;i<5;i++)
        {
            if (val_a[i]!=val_b[i]) break;
            if (val_c[i]!=val_d[i]) break;
        }
        if (i==5) break;
        for (i=0;i<5;i++)
        {
            val_a[i]=(val_a[i]-((a[j]-a[j+1]).length())%modo[i]*power(p[i],n-1,modo[i]))%modo[i];
            val_a[i]=(val_a[i]*p[i]+(a[j]-a[j+1]).length())%modo[i];
            val_a[i]=(val_a[i]+modo[i])%modo[i];
            val_c[i]=(val_c[i]-((a[j]-a[j+1])*(a[j+1]-a[j+2]))%modo[i]*power(p[i],n-1,modo[i]))%modo[i];
            val_c[i]=(val_c[i]*p[i]+(a[j]-a[j+1])*(a[j+1]-a[j+2]))%modo[i];
            val_c[i]=(val_c[i]+modo[i])%modo[i];
        }
    }
    if (j==n) return false;
    return true;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        a[i].read();
    }
    int min_x=1000000005,min_y=1000000005,id=-1;
    for (i=0;i<n;i++)
    {
        if ((a[i].x<min_x)||((a[i].x==min_x)&&(a[i].y<min_y)))
        {
            min_x=a[i].x;
            min_y=a[i].y;
            id=i;
        }
    }
    swap(a[id],a[0]);
    for (i=1;i<n;i++)
    {
        a[i]=a[i]-a[0];
    }
    a[0]=point(0,0);
    sort(a+1,a+n);
    static point que[1000005];
    que[0]=a[0];
    int front=0,rail=1;
    for (i=1;i<n;i++)
    {
        for (;rail>=2;rail--)
        {
            if ((que[rail-1]-que[rail-2])*(a[i]-que[rail-1])<0)
            {
                break;
            }
        }
        que[rail++]=a[i];
    }
    n=rail;
    for (i=0;i<n;i++)
    {
        b[i]=que[i];
    }
    //////////////////////
    for (i=0;i<m;i++)
    {
        a[i].read();
    }
    min_x=1000000005,min_y=1000000005,id=-1;
    for (i=0;i<m;i++)
    {
        if ((a[i].x<min_x)||((a[i].x==min_x)&&(a[i].y<min_y)))
        {
            min_x=a[i].x;
            min_y=a[i].y;
            id=i;
        }
    }
    swap(a[id],a[0]);
    for (i=1;i<m;i++)
    {
        a[i]=a[i]-a[0];
    }
    a[0]=point(0,0);
    sort(a+1,a+m);
    que[0]=a[0];
    front=0;
    rail=1;
    for (i=1;i<m;i++)
    {
        for (;rail>=2;rail--)
        {
            if ((que[rail-1]-que[rail-2])*(a[i]-que[rail-1])<0)
            {
                break;
            }
        }
        que[rail++]=a[i];
    }
    m=rail;
    for (i=0;i<m;i++)
    {
        a[i]=que[i];
    }
    if (check(m,n))
    {
        puts("YeS");
    }
    else
    {
        puts("nO");
    }
    return 0;
}