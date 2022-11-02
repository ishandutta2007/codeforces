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
const int N=2000;
const int P=1000000007;
int a[V],h[V],m[V],use[V],n,x;
int main()
{
    while(~scanf("%d%d",&n,&x))
    {
        int ret=0;
        for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&h[i],&m[i]);
        int pr=0,now=x,cnt=0;
        memset(use,0,sizeof(use));
        while(1)
        {
            int id=-1;
            for(int i=1;i<=n;i++)
            if(!use[i]&&a[i]!=pr&&(id==-1||m[id]<m[i])&&h[i]<=now)
            id=i;
            if(id==-1)break;
            now+=m[id];use[id]=1;cnt++;pr^=1;
        }
        ret=max(ret,cnt);
        pr=1,now=x,cnt=0;
        memset(use,0,sizeof(use));
        while(1)
        {
            int id=-1;
            for(int i=1;i<=n;i++)
            if(!use[i]&&a[i]!=pr&&(id==-1||m[id]<m[i])&&h[i]<=now)
            id=i;
            if(id==-1)break;
            now+=m[id];use[id]=1;cnt++;pr^=1;
        }
        ret=max(ret,cnt);
        printf("%d\n",ret);
    }
}