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
const int V=200100;
int n,K,x;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        int ct=0;
        LL pr=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            LL te=pr-(LL)ct*x*(n-i);
            if(te<K)printf("%d\n",i);
            else pr+=(LL)x*ct,ct++;
        }
    }
}