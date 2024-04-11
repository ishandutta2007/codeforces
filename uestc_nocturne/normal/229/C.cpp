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
const int V=1000100;
int d[V],n,m,x,y;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(d,0,sizeof(d));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            d[x]++;d[y]++;
        }
        LL ret=(LL)n*(n-1)*(n-2)/6;
        LL tmp=0;
        for(int i=1;i<=n;i++)
        {
            tmp+=(LL)d[i]*(n-1-d[i]);
        }
        ret-=tmp/2;
        cout<<ret<<endl;
    }
}