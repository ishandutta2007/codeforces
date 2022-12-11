#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,cnt;
int main()
{
    n=read(),cnt=0;int n1=n;
if (n<=2) cout << -1 << endl; else
{
    while (n%2==0)
    {
        ++cnt;
        n/=2;
    }
    if (n==1)
    {
        long long ans1=(n1/4)*3,ans2=(n1/4)*5;
        cout <<ans1<<' '<<ans2<<endl;
    }else
    {
        long long ans1=(1LL*n*n-1)/2,ans2=(1LL*n*n+1)/2;
        for (int i=1;i<=cnt;i++)
            ans1=ans1+ans1,ans2=ans2+ans2;
        cout << ans1 << ' '<< ans2<<endl;
    }
}
    return 0;
}