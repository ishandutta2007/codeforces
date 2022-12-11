#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int n,k;
int a[2000007];
bool check;
int main()
{
    n=read(),k=read();
    for (int i=1;i<=n;i++) a[i]=read();
    check=true;int n1=k;
    for (int i=2;i*i<=k;i++)
    if (k%i==0)
    {
        int cnt=0;
        while (n1%i==0){++cnt;n1/=i;}
        bool flag=false;
        for (int j=1;j<=n;j++)
        {
            int tot=0;
            while (a[j]%i==0){++tot;a[j]/=i;}
            if (tot>=cnt) flag=true;
        }
        if (!flag) check=false;
    }
    if (n1!=1)
    {
        bool flag=false;
        for (int j=1;j<=n;j++) if (a[j]%n1==0) flag=true;
        if (!flag) check=false;
    }
    if (check) cout << "Yes" << endl; else cout << "No" << endl;
}