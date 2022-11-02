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
const int V=100100;
int a[V],b[V],top,tail,q[V];
int ans[2][V],ct,i,n,m,x,y;
int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&x,&y))
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<m;i++)
        scanf("%d",&b[i]);
        top=tail=0;ct=0;
        int p=0;
        for(i=0;i<m;i++)
        {
            while(p<n&&a[p]-x<=b[i])
            q[++tail]=p++;
            while(top!=tail&&a[q[top+1]]+y<b[i])top++;
            //printf("%d %d %d %d\n",i,top,tail,p);
            if(top!=tail)
            {
                ans[0][ct]=q[top+1]+1;
                ans[1][ct++]=i+1;
                top++;
            }
        }
        printf("%d\n",ct);
        for(i=0;i<ct;i++)
        printf("%d %d\n",ans[0][i],ans[1][i]);
    }
}