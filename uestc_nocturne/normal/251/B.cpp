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
const int V=120;
int a[V],q[V],tmp[2][V],s[V],n,K;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        for(int i=1;i<=n;i++)
        scanf("%d",&q[i]);
        for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
        for(int i=1;i<=n;i++)
        tmp[0][i]=i;
        int fl,te;
        int R=-1;
        fl=0;
        for(int i=0;i<=K;i++)
        {
            te=1-fl;
        //  for(int j=1;j<=n;j++)printf("%d ",tmp[fl][j]);puts("");
            bool can=true;
            for(int j=1;j<=n;j++)
            if(tmp[fl][j]!=s[j])can=false;
            if(can){R=i;break;}
            for(int j=1;j<=n;j++)
            tmp[te][j]=tmp[fl][q[j]];
            fl=te;
        }
        for(int i=1;i<=n;i++)
        tmp[0][i]=i;
        int L=-1;
        fl=0;
        for(int i=0;i<=K;i++)
        {
            te=1-fl;
            bool can=true;
            for(int j=1;j<=n;j++)
            if(tmp[fl][j]!=s[j])can=false;
            if(can){L=i;break;}
            for(int j=1;j<=n;j++)
            tmp[te][q[j]]=tmp[fl][j];
            fl=te;
        }
    //  printf("%d %d\n",L,R);
        if(L==-1&&R==-1)puts("NO");
        else if(L==0||R==0)puts("NO");
        else if(L==1&&R==1)
        {
            if(K==1)puts("YES");
            else puts("NO");
        }
        else if((L!=-1&&(K-L)%2==0&&(K>=L))||(R!=-1&&(K>=R)&&(K-R)%2==0))puts("YES");
        else puts("NO");
    }
}