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
bool a[400001];
int main()
{
    int t,n;
    bool flag;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
        n=read();
        for(int i=1;i<=n;i++)a[((i+read())%n+n)%n]=1;
        flag=false;
        for(int i=0;i<=n-1;i++)
        {
                if(a[i]==0)
                {
                    flag=true;
                    break;
                }
        }
        if(flag==false)printf("YES\n");
        else printf("NO\n");
        for(int i=0;i<=n-1;i++)a[i]=0;
    }
    //system("pause");
    return 0;
}