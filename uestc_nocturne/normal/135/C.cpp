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
char s[1000100];
int on,zn,qn,n,i,can[120];
int main()
{
    while(~scanf("%s",s))
    {
        n=strlen(s);
        on=zn=qn=0;
        for(i=0;i<n;i++)
        if(s[i]=='0')zn++;
        else if(s[i]=='1')on++;
        else qn++;
        memset(can,0,sizeof(can));
        if(n%2==0)
        {
            if(zn+qn>=on+2)can[0]=1;
            if(zn+qn>=on&&zn<=on+qn)
            {
                if(s[n-1]=='1')can[1]=1;
                else if(s[n-1]=='0')can[2]=1;
                else
                {
                    if(zn+qn>on)can[1]=1;
                    if(zn<on+qn)can[2]=1;
                }
            }
            if(zn+2<=on+qn)can[3]=1;
        }
        else
        {
            if(zn+qn>=on+1)can[0]=1;
            if(zn+qn+1>=on&&zn<on+qn)
            {
                if(s[n-1]=='1')can[1]=1;
                else if(s[n-1]=='0')can[2]=1;
                else
                {
                    if(zn+qn+1>on)can[1]=1;
                    if(zn+1<on+qn)can[2]=1;
                }
            }
            if(zn+2<on+qn)can[3]=1;
        }
        if(can[0])puts("00");
        if(can[1])puts("01");
        if(can[2])puts("10");
        if(can[3])puts("11");
    }
}