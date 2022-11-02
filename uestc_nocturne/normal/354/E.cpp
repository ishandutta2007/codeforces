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
int can[10][5],ls[10][5][7];
void init()
{
    for(int i=0;i<=6;i++)
    for(int j=0;j+i<=6;j++)
    {
        int k=6-i-j;
        int s=i*7+j*4;
        int jw=s/10;
        int re=s%10;
        can[re][jw]=1;
        for(int l=0;l<6;l++)
        if(l<i)ls[re][jw][l]=7;
        else if(l<i+j)ls[re][jw][l]=4;
        else ls[re][jw][l]=0;
    }
}
int dp[30][11],pr[30][11];
LL n;
int num[30],t;
int ret[30][30];
int main()
{
    init();
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        t=0;
        while(n)
        {
            num[t++]=n%10;
            n/=10;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<t;i++)
        for(int j=0;j<6;j++)
        if(dp[i][j])
        {
            int d=(num[i]-j+10)%10;
            for(int k=0;k<5;k++)
            if(can[d][k])
            {
                int s=k*10+d+j;
                int jw=s/10;
                dp[i+1][jw]=1;
                pr[i+1][jw]=j;
            }
        }
        if(dp[t][0]==0)puts("-1");
        else
        {
            int nj=0;
            for(int i=t;i>0;i--)
            {
                int j=pr[i][nj];
                int d=(num[i-1]-j+10)%10;
                for(int k=0;k<5;k++)
                if(can[d][k])
                {
                    int s=k*10+d+j;
                    int jw=s/10;
                    if(jw==nj)
                    {
                        for(int l=0;l<6;l++)
                        ret[l][i]=ls[d][k][l];
                        break;
                    }
                }
                nj=j;
            }
            for(int i=0;i<6;i++)
            {
                if(i)
                printf(" ");
                bool nz=false;
                for(int j=t;j>0;j--)
                {
                    if(ret[i][j]==0)
                    {
                        if(j==1||nz)
                        printf("0");
                    }
                    else
                    {
                        nz=true;
                        printf("%d",ret[i][j]);
                    }
                }
            }
            puts("");
        }
    }
    return 0;
}