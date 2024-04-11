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
int n,x[120],y[120];
int main()
{
    while(~scanf("%d",&n))
    {
        LL s=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x[i],&y[i],&x[n+i],&y[n+i]);
            s+=(LL)(x[n+i]-x[i])*(y[n+i]-y[i]);
        }
        sort(x,x+2*n);
        sort(y,y+2*n);
        LL all=(LL)(x[2*n-1]-x[0])*(y[2*n-1]-y[0]);
        if(s==all&&(x[2*n-1]-x[0]==y[2*n-1]-y[0]))puts("YES");
        else puts("NO");
    }
    return 0;
}