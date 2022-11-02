#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int V=100100;
char ch[V];
int a[V],n,k,p,i;
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        scanf("%s",ch);
        for(i=0;i<n;i++)
        a[i]=ch[i]-'0';
        p=0;
        while(k>0)
        {
            if(p==n-1)break;
            if(a[p]==4&&a[p+1]==7)
            {
                if(p%2==0)
                {
                    a[p+1]=4;p++;k--;
                }
                else
                {
                    a[p]=7;k--;
                    if(p>0&&a[p-1]==4)
                    {
                        k%=2;p--;
                    }
                }
            }
            else p++;
        }
        for(i=0;i<n;i++)printf("%d",a[i]);puts("");
    }
}