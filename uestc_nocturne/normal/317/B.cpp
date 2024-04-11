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
int cnt[2][70][70],n,Q,x,y;
const int N=5;
const int M=66;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main()
{
    while(~scanf("%d%d",&n,&Q))
    {
        int ct=0;
        memset(cnt,0,sizeof(cnt));
        cnt[0][ct][ct]=n;
        int fl=0,te=1,ls=0;
        while(1)
        {
            te=1-fl;
            bool dn=false;
            memset(cnt[te],0,sizeof(cnt[te]));
            for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
            if(cnt[fl][i][j]>=4)
            {
                cnt[fl][i][j]-=4;
                for(int k=0;k<4;k++)
                {
                    int tx=i+dx[k];
                    int ty=j+dy[k];
                    if(tx<ct||ty<ct)continue;
                    if((tx==ct&&tx!=i)||(ty==ct&&ty!=j))cnt[te][tx][ty]+=2;
                    else cnt[te][tx][ty]++;
                }
                dn=true;
            }
            if(!dn)break;
            ls++;
            for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
            cnt[te][i][j]+=cnt[fl][i][j];
            fl=te;
            //for(int i=ct;i<ct+N;i++,puts(""))
            //for(int j=ct;j<ct+N;j++)printf("%d ",cnt[te][i][j]);
            //printf("%d\n",ls);
        }
        while(Q--)
        {
            scanf("%d%d",&x,&y);
            if(x<0)x=-x;
            if(y<0)y=-y;
            if(x>=M||y>=M)puts("0");
            else printf("%d\n",cnt[fl][x][y]);
        }
    }
}