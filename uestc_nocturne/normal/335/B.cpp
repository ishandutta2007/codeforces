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
const int V=50100;
const int N=2700;
char s[V];
int ct[V];
int dp[N][N];
int ret[N];
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        memset(ct,0,sizeof(ct));
        for(int i=0;i<n;i++)
        ct[s[i]-'a']++;
        int id=-1;
        for(int i=0;i<26;i++)
        if(ct[i]>=100)
        {id=i;break;}
        if(id!=-1)
        {
            for(int i=0;i<100;i++)
            printf("%c",id+'a');
            puts("");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        dp[i][i]=1;
        for(int l=2;l<=n;l++)
        for(int i=0;i+l-1<n;i++)
        {
            int j=i+l-1;
            if(s[i]==s[j])
            dp[i][j]=max(dp[i][j],dp[i+1][j-1]+2);
            else dp[i][j]=max(dp[i][j],dp[i+1][j-1]);
            dp[i][j]=max(dp[i][j],dp[i+1][j]);
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
        int mx=0,L=-1,R=-1;
        for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        if(dp[i][j]>mx)
        {mx=dp[i][j],L=i,R=j;}
        int t=0;
        id=-1;
        //printf("%d\n",mx);
        while(1)
        {
            if(L==R)
            {
                id=s[L]-'a';
                break;
            }
            else if(L>R) break;
            else if(dp[L][R]==dp[L+1][R])L++;
            else if(dp[L][R]==dp[L][R-1])R--;
            else
            {
                ret[t++]=s[L]-'a';
                L++;R--;
            }
        }
        if(t>=50)
        {
            for(int i=0;i<50;i++)printf("%c",ret[i]+'a');
            for(int i=49;i>=0;i--)printf("%c",ret[i]+'a');
        }
        else
        {
            for(int i=0;i<t;i++)printf("%c",ret[i]+'a');
            if(id!=-1)printf("%c",id+'a');
            for(int i=t-1;i>=0;i--)printf("%c",ret[i]+'a');
        }
        puts("");
    }
    return 0;
}