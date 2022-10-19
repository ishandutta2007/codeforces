#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
int main()
{
    int t,n,m;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
        n=read();
        m=read();
        if(n>m)swap(n,m);
        if(n==1)printf("YES\n");
        else if(n==2&&m==2)printf("YES\n");
        else printf("NO\n");
    }
    //system("pause");
    return 0;
}