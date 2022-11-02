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
char s[1200];
int rev(int x)
{
    int ret=0;
    for(int i=0;i<8;i++)
    {
        ret*=2;
        ret+=x%2;
        x/=2;
    }
    return ret;
}
int i,n;
int main()
{
    while(gets(s))
    {
        int te=0;
        n=strlen(s);
        for(i=0;i<n;i++)
        {
            int x=s[i];
            int ret=rev(x);
            ret=(te-ret+512)%256;
            printf("%d\n",ret);
            te=rev(x);
        }
    }
}