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
char s[V][V];
int n;
int id[V];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        scanf("%s",s[i]);
        bool can=true;
        memset(id,-1,sizeof(id));
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(s[i][j]=='.')id[i]=j;
        for(int i=0;i<n;i++)
        if(id[i]==-1)can=false;
        if(can)
        {
            for(int i=0;i<n;i++)
            printf("%d %d\n",i+1,id[i]+1);
            continue;
        }
        can=true;
        memset(id,-1,sizeof(id));
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(s[j][i]=='.')id[i]=j;
        for(int i=0;i<n;i++)
        if(id[i]==-1)can=false;
        if(can)
        {
            for(int i=0;i<n;i++)
            printf("%d %d\n",id[i]+1,i+1);
            continue;
        }
        puts("-1");
    }
}