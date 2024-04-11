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
const int V=1200;
int t[3],ct[3],a[3][V],mi[10],id[3],K;
int main()
{
    while(~scanf("%d",&K))
    {
        for(int i=0;i<3;i++)
        scanf("%d",&ct[i]);
        for(int i=0;i<3;i++)
        scanf("%d",&t[i]);
        memset(a,0,sizeof(a));
        int now=0;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<3;j++)
            {
                id[j]=-1;
                for(int k=0;k<ct[j];k++)
                if(id[j]==-1||a[j][k]<a[j][id[j]])
                id[j]=k;
                mi[j]=a[j][id[j]];
            }
            now=max(mi[0],max(mi[1]-t[0],mi[2]-t[0]-t[1]));
            a[0][id[0]]=now+t[0];
            a[1][id[1]]=now+t[0]+t[1];
            a[2][id[2]]=now+t[0]+t[1]+t[2];
        }
        printf("%d\n",now+t[0]+t[1]+t[2]);
    }
}