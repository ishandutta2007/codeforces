#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
int n,n4,n7,i;
int main()
{
    while(~scanf("%d",&n))
    {
        bool can=false;
        for(i=n/7;i>=0;i--)
        {
            if((n-7*i)%4==0)
            {
                can=true;
                n7=i;
                n4=(n-7*i)/4;
                break;
            }
        }
        if(!can)puts("-1");
        else
        {
            for(i=0;i<n4;i++)printf("4");
            for(i=0;i<n7;i++)printf("7");
            puts("");
        }
    }
}