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
int can[V][V],tr[V],tl[V],str[V],stl[V];
char s[V];
int i,j;
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        memset(can,0,sizeof(can));
        memset(tr,0,sizeof(tr));
        memset(tl,0,sizeof(tl));
        for(i=0;i<n;i++)
        {
            can[i][i]=1;
            for(j=1;;j++)
            {
                if(i-j<0)break;
                if(i+j>=n)break;
                if(s[i-j]!=s[i+j])break;
                can[i-j][i+j]=1;
            }
        }
        for(i=1;i<n;i++)
        {
            for(j=1;;j++)
            {
                if(i-j<0)break;
                if(i+j-1>=n)break;
                if(s[i-j]!=s[i+j-1])break;
                can[i-j][i+j-1]=1;
            }
        }
    //  for(i=0;i<n;i++){for(j=i;j<n;j++)printf("%d ",can[i][j]);puts("");}
        for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        if(can[i][j])tr[i]++,tl[j]++;
        stl[0]=tl[0];
        for(i=1;i<n;i++)
        stl[i]=stl[i-1]+tl[i];
        str[n-1]=tr[n-1];
        for(i=n-2;i>=0;i--)
        str[i]=str[i+1]+tr[i];
        LL ans=0;
        for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        if(can[i][j])
        {
            if(j!=n-1)ans+=str[j+1];
            if(i!=0)ans+=stl[i-1];
        }
        cout<<ans/2<<endl;
    }
}