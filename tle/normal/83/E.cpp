#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define yi(n) ((1<<n)-1) //111....1111 length of n
int n,len,value[200001],dp[25][1500000],ans;
char tmp[200001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int rp=0;
        scanf("%s",tmp);
        if(i==1) len=strlen(tmp);
        for(int j=0;tmp[j];j++) rp=(rp<<1)+tmp[j]-'0';
        value[i]=rp;
    }
    ans=len;
    memset(dp,0x40,sizeof(dp)); //MAXINT
    dp[0][0]=0;
    for(int i=2;i<=n;i++)
    {
        int ms,nl=0x7ffffff;
        for(ms=len;ms>0;ms--) {if((value[i-1]&yi(ms))==(value[i]>>(len-ms))) break;} //find
        ans+=len-ms; //add not same
        for(int j=0;j<=len;j++) nl=min(nl,dp[len-j][value[i]>>j]+j);
        for(int j=0;j<=len;j++)
        {
            int& target=dp[j][value[i-1]&yi(j)];
            target=min(target,nl-len+ms);
        }
    } 
    int minn=0x7ffffff;
    for(int i=0;i<=len;i++)
    {
        for(int j=yi(i);j>=0;j--) minn=min(minn,dp[i][j]);
    }
    cout<<minn+ans;
}