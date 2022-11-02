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
LL n,t;
int nu[120],ct;
LL C[120][102];
int main()
{
    memset(C,0,sizeof(C));
    for(int i=0;i<50;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    while(~scanf("%I64d%I64d",&n,&t))
    {
        int id=0;
        for(int i=0;i<50;i++)
        if((1LL<<i)==t)
        {id=i+1;break;}
        if(id==0){puts("0");continue;}
        LL ret=0;
        ct=0;n++;
        while(n)
        {
            nu[ct++]=n%2;
            n/=2;
        }
        int pr=0;
        for(int i=ct-1;i>=0;i--)
        {
            if(pr>id)break;
            if(nu[i]==1)
            {
                ret+=C[i][id-pr];
                pr++;
            }
        }
        if(pr==id)ret++;
        if(id==1)ret--;
        //cout<<id<<endl;
        printf("%I64d\n",ret);
    }
}