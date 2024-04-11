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
int nu[120];
LL Cal(LL x)
{
    if(x==0)return 0;
    LL xx=x;
    int t=0;
    while(xx)
    {
        nu[t++]=xx%10;
        xx/=10;
    }
    LL ret=0,pp=9;
    for(int i=1;i<t;i++)
    {
        if(i>2)pp*=10;
        ret+=pp;
    //  cout<<ret<<" "<<pp<<endl;
    }
    //cout<<ret<<endl;
    if(t>2)
    {
        pp=1;
        for(int i=0;i<t-2;i++)pp*=10;
        ret+=pp*(nu[t-1]-1);
        int tt=t,f=nu[t-1];
        while(nu[t-1]>nu[0])
        {
            x--;
            xx=x;t=0;
            while(xx)
            {
                nu[t++]=xx%10;
                xx/=10;
            }
        }
        pp=1;
        for(int i=0;i<t-1;i++)pp*=10;
        if(tt==t&&nu[t-1]==f)ret+=(x-pp*nu[t-1])/10+1;
    }
    else if(t==2)
    {
        for(int i=11;i<=x;i+=11)
        ret++;
    }
    else if(t==1)ret+=x;
    //cout<<x<<" "<<ret<<endl;
    return ret;
}
LL A,B;
int main()
{
    while(cin>>A>>B)
    {
        cout<<Cal(B)-Cal(A-1)<<endl;
    }
}