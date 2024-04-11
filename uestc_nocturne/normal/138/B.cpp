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
char s[V];
int ct[120],ct2[120];
int re[120];
int ans[2][2*V];
int i,j,id,st,ed,po;
int main()
{
    while(1==scanf("%s",s))
    {
        int n=strlen(s);
        memset(ct,0,sizeof(ct));
        memset(re,0,sizeof(re));
        for(i=0;i<n;i++)ct[s[i]-'0']++;
        for(i=0;i<5;i++)
        {
            id=-1;
            if(ct[i]>ct[9-i])id=9-i;
            else if(ct[i]<ct[9-i])id=i;
            if(id!=-1)re[9-id]=1;
        }
        id=-1;
        for(i=1;i<=5;i++)
        if(re[i]&&re[10-i])id=i;
        if(id==-1)
        {
            for(i=1;i<=9;i++)
            if(re[i]&&ct[10-i])id=i;
        }
        if(id==-1)
        {
            for(i=1;i<=9;i++)
            if(ct[i]&&ct[10-i])id=i;
        }
        po=n;
        if(id==-1)
        {
            for(i=0;i<=9;i++)
            while(ct[i])
            {
                ans[0][po]=ans[1][po]=i;
                po--;ct[i]--;
            }
            st=1;ed=n;
        }
        else
        {
        //  for(i=0;i<9;i++)printf("%d ",ct[i]);puts("");
            for(i=0;i<=9;i++)ct2[i]=ct[i];
            ans[0][po]=id;ans[1][po]=10-id;
            ct[id]--;ct2[10-id]--;po--;
            for(i=0;i<=9;i++)
            {
                while(ct[i]&&ct2[9-i])
                {
                    ans[0][po]=i;ans[1][po]=9-i;
                    po--;ct[i]--;ct2[9-i]--;
                }
            }
            ed=n;
            while(ct[0]&&ct2[0])
            {
                ed++;
                ans[0][ed]=ans[1][ed]=0;
                ct[0]--;ct2[0]--;
            }
            st=po;
            
            for(i=0;i<=9;i++)
            while(ct[i])
            {
                ans[0][po]=i;
                po--;ct[i]--;
            }
            for(i=0;i<=9;i++)
            while(ct2[i])
            {
                ans[1][st]=i;
                st--;ct2[i]--;
            }
            st++;
        }
        //printf("%d %d\n",st,ed);
        for(i=st;i<=ed;i++)printf("%d",ans[0][i]);puts("");
        for(i=st;i<=ed;i++)printf("%d",ans[1][i]);puts("");
    }
}