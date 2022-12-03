#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
struct point
{
    int x;
    int y;
    int sym;
    point (int xx=0,int yy=0)
    {
        x=xx;
        y=yy;
    }
    friend long long operator * (const point &a,const point &b)
    {
        return (long long)a.x*b.y-(long long)b.x*a.y;
    }
    void get_symbol()
    {
        if ((x>=0)&&(y>0))
        {
            sym=1;
        }
        else if ((x<0)&&(y>=0))
        {
            sym=2;
        }
        else if ((x<=0)&&(y<0))
        {
            sym=3;
        }
        else if ((x>0)&&(y<=0))
        {
            sym=4;
        }
        else
        {
            sym=0;
        }
    }
    friend point operator - (const point &a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator < (const point &a,const point &b)
    {
        if (a.sym!=b.sym)
        {
            return a.sym<b.sym;
        }
        return a*b>0;
    }
    void read()
    {
        scanf("%d%d",&x,&y);
    }
};
point a[2505];
point b[5005];
void get_sort(int x)
{
    int i;
    for (i=0;i<n;i++)
    {
        b[i]=a[i]-a[x];
        b[i].get_symbol();
    }
    swap(b[0],b[x]);
    sort(b+1,b+n);
    for (;i<n+n;i++)
    {
        b[i]=b[i-n+1];
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        a[i].read();
    }
    long long ans=0;
    for (i=0;i<n;i++)
    {
        get_sort(i);
        ans+=(long long)(n-1)*(n-2)*(n-3)/6;
        int j;
        int now_loc=1;
        for (j=1;j<n;j++)
        {
            if (j==now_loc)
            {
                now_loc++;
            }
            for (;b[j]*b[now_loc]>0;)
            {
                now_loc++;
            }
            ans-=(long long)(now_loc-j-1)*(now_loc-j-2)/2;
        }
    }
    cout<<ans*(n-4)/2<<endl;
    return 0;
}