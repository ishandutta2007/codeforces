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
int ct[120];
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        memset(ct,0,sizeof(ct));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')cnt++;
            if(s[i]>='A'&&s[i]<='Z')ct[s[i]-'A']++;
        }
        int has=0;
        for(int i=0;i<10;i++)
        if(ct[i]!=0)has++;
        int ret=1;
        bool az=false;
        if(s[0]=='?')ret=9,cnt--;
        if(s[0]>='A'&&s[0]<='Z')
        {
            az=true;
            ret=9;
        }
        if(az)
        {
            for(int i=1;i<has;i++)
            ret*=(10-i);
        }
        else
        {
            for(int i=0;i<has;i++)
            ret*=(10-i);
        }
        printf("%d",ret);
        for(int i=0;i<cnt;i++)printf("0");
        puts("");
    }
}