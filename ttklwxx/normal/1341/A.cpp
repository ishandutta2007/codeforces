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
    int t,n,a,b,c,d;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
        n=read();
        a=read();
        b=read();
        c=read();
        d=read();
        if((c-d>n*(a+b))||(c+d<n*(a-b)))
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }    
    //system("pause>nul");
    return 0;
}