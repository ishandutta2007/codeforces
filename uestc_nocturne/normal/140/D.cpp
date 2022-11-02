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
const int S=720;
int a[120],i,n;
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        int ct=0,s=10;
        for(i=0;i<n;i++)
        {
            if(a[i]+s<=S)
            {
                ct++;
                s+=a[i];
            }
            else break;
        }
        int nt=10;
        int p=0;
        for(i=0;i<ct;i++)
        {
            nt+=a[i];
            if(nt>360)
            p+=nt-360;
        }
        printf("%d %d\n",ct,p);
    }
}