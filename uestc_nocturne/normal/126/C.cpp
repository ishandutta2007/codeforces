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
char ch[V][V];
int sr[V][V],su[V][V],sl[V][V],sd[V][V];
int n,ans,i,j,k,te;
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        scanf("%s",ch[i]);
        if(n==1)
        {
            if(ch[0][0]=='0')ans=0;
            else ans=1;
            printf("%d\n",ans);
            continue;
        }
        ans=0;
        memset(sr,0,sizeof(sr));
        memset(sl,0,sizeof(sl));
        memset(su,0,sizeof(su));
        memset(sd,0,sizeof(sd));
        if(ch[0][n-1]=='0')sr[0][n-1]=su[0][n-1]=0;
        else sr[0][n-1]=su[0][n-1]=1,ans++;
        for(k=n-2;k>0;k--)
        {
            for(i=0;k+i<n;i++)
            {
                j=k+i;
                te=ch[i][j]-'0';
                if(i!=0)te+=su[i-1][j];
                if(j!=n-1)te+=sr[i][j+1];
                te%=2;
                if(te==0)
                {
                    if(i!=0)su[i][j]=su[i-1][j];
                    if(j!=n-1)sr[i][j]=sr[i][j+1];
                }
                else
                {
                    if(i!=0)su[i][j]=su[i-1][j]+1;
                    else su[i][j]=1;
                    if(j!=n-1)sr[i][j]=sr[i][j+1]+1;
                    else sr[i][j]=1;
                    ans++;
                }
            }
        }
        if(ch[n-1][0]=='0')sl[n-1][0]=sd[n-1][0]=0;
        else sl[n-1][0]=sd[n-1][0]=1,ans++;
        for(k=n-2;k>0;k--)
        {
            for(i=n-1;i-k>=0;i--)
            {
                j=i-k;
                te=ch[i][j]-'0';
                if(i!=n-1)te+=sd[i+1][j];
                if(j!=0)te+=sl[i][j-1];
                te%=2;
            //  if(te==1)
            //  printf("%d %d\n",i,j);
                if(te==0)
                {
                    if(i!=n-1)sd[i][j]=sd[i+1][j];
                    if(j!=0)sl[i][j]=sl[i][j-1];
                }
                else
                {
                    if(i!=n-1)sd[i][j]=sd[i+1][j]+1;
                    else sd[i][j]=1;
                    if(j!=0)sl[i][j]=sl[i][j-1]+1;
                    else sl[i][j]=1;
                    ans++;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            te=ch[i][i]-'0';
            if(i!=0)te+=sl[i][i-1]+su[i-1][i];
            if(i!=n-1)te+=sr[i][i+1]+sd[i+1][i];
            te%=2;
        //  if(te==1)printf("%d\n",i);
            if(te==1)ans++;
        }
        printf("%d\n",ans);
    }
}