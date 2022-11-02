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
const int V=200100;
char s[V],t[V];
LL sl[V][26],sr[V][26];
int n;
int main()
{
//  freopen("129C.in","r",stdin);
    while(~scanf("%d",&n))
    {
        memset(sl,0,sizeof(sl));
        memset(sr,0,sizeof(sr));
        scanf("%s%s",s,t);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            sl[i+1][j]=sl[i][j];
            sl[i+1][s[i]-'A']+=i+1;
        }       
        for(int i=n;i>0;i--)
        {
            for(int j=0;j<26;j++)
            sr[i][j]=sr[i+1][j];
            sr[i][s[i-1]-'A']+=n-i+1;
        }
        double ret=0.0;
        LL way=0;
        for(int i=1;i<=n;i++)
        way+=(LL)i*i;
        for(int i=1;i<=n;i++)
        {
            ret+=1.0*sl[i][t[i-1]-'A']*(n-i+1)/way;
            ret+=1.0*sr[i+1][t[i-1]-'A']*i/way;
        }
        printf("%.10f\n",ret);
    }
}