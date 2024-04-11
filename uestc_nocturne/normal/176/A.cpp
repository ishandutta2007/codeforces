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
struct Node
{
    int d,ct;
}q[100100];
bool cmp(Node x,Node y)
{return x.d>y.d;}
int a[20][120],b[20][120],c[20][120];
int n,m,K,i,j,k;
int main()
{
    while(~scanf("%d%d%d",&n,&m,&K))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            for(j=0;j<m;j++)
            scanf("%d%d%d",&a[i][j],&b[i][j],&c[i][j]);
        }
        int ans=0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                q[k].d=b[j][k]-a[i][k];
                q[k].ct=c[i][k];
            }
            sort(q,q+m,cmp);
            int tmp=0,re=K;
            for(k=0;k<m;k++)
            {
                if(re==0||q[k].d<0)break;
                int use=min(q[k].ct,re);
                re-=use;tmp+=q[k].d*use;
            }
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
}