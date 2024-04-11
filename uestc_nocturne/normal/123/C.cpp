#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL ooo=1000000001;
const LL oo=ooo*ooo;
LL K,dp[210][210];
struct Node{int id,va;}q[210];
bool cmp(Node x,Node y)
{return x.va<y.va;}
int ans[210],n,m,i,j,k,x,N,mi[210];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        cin>>K;
        for(i=0;i<n+m;i++)mi[i]=1000000000;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf("%d",&x);
            mi[i+j]=min(mi[i+j],x);
        }
        N=n+m-1;
        for(i=0;i<N;i++)
        {
            q[i].id=i;
            q[i].va=mi[i];
        }
    //  K--;
        sort(q,q+N,cmp);
        memset(ans,-1,sizeof(ans));
        ans[0]=0;ans[N-1]=1;
        for(i=0;i<N;i++)
        {
            if(q[i].id==0||q[i].id==N-1)continue;
            ans[q[i].id]=0;
            memset(dp,0,sizeof(dp));
            dp[1][1]=1;
            for(j=1;j<N;j++)
            {
                for(k=0;k<=N;k++)
                {
                    if(dp[j][k]==0)continue;
                    if(ans[j]==-1)
                    {
                        if(dp[j+1][k+1]>=oo-dp[j][k])
                        dp[j+1][k+1]=oo;
                        else dp[j+1][k+1]+=dp[j][k];
                        if(k>0)
                        {
                            if(dp[j+1][k-1]>=oo-dp[j][k])
                            dp[j+1][k-1]=oo;
                            else dp[j+1][k-1]+=dp[j][k];                        
                        }
                    }
                    else if(ans[j]==0)
                    {
                        if(dp[j+1][k+1]>=oo-dp[j][k])
                        dp[j+1][k+1]=oo;
                        else dp[j+1][k+1]+=dp[j][k];
                    }
                    else if(k>0)
                    {
                        if(dp[j+1][k-1]>=oo-dp[j][k])
                        dp[j+1][k-1]=oo;
                        else dp[j+1][k-1]+=dp[j][k];
                    }
                }
            }
        //  cout<<q[i].id<<" "<<dp[N][0]<<" "<<K<<endl;
            if(dp[N][0]<K){ans[q[i].id]=1;K-=dp[N][0];}
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ans[i+j]==0)printf("(");
                else printf(")");
            }puts("");
        }
    }
}