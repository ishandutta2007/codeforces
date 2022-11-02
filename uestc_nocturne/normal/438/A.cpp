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
const int V=2100;
const int P=1000000007;
int va[V],n,m,u,v;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        scanf("%d",&va[i]);
        int ret=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            ret+=min(va[u],va[v]);
        }
        printf("%d\n",ret);
    }
}