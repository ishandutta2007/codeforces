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
const int V=60;
int a[V][V],c[V],s,n;
int x[V*V],y[V*V],t;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<c[i];j++)
            scanf("%d",&a[i][j]);
        }
        t=0;int now=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<c[i];j++)
            {
                if(a[i][j]!=now)
                {
                    bool find=false;
                    for(int ii=0;ii<n&&!find;ii++)
                    for(int jj=0;jj<c[ii];jj++)
                    {
                        if(a[ii][jj]==now)
                        {
                            find=true;
                            x[t]=i*V+j;
                            y[t++]=ii*V+jj;
                            swap(a[i][j],a[ii][jj]);
                            break;
                        }
                    }
                }
                now++;
            }
        }
        printf("%d\n",t);
        for(int i=0;i<t;i++)
        printf("%d %d %d %d\n",x[i]/V+1,x[i]%V+1,y[i]/V+1,y[i]%V+1);
    }
}