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
LL n;
int nu[120],t;
int main()
{
    while(cin>>n)
    {
        t=0;
        memset(nu,0,sizeof(nu));
        while(n)
        {
            nu[t++]=n%3;
            n/=3;
        }
        int id=-1;
        for(int i=0;i<t;i++)
        if(nu[i]!=0)
        {id=i;break;}
        nu[id]=0;nu[id+1]++;
        LL ret=0;
        for(int i=t;i>id;i--)
        ret*=3,ret+=nu[i];
        cout<<ret<<endl;
    }
}