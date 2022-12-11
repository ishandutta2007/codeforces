#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
bool ans;
int main()
{
    n=read(),m=read(),ans=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            char ch=getchar();
            while (ch!='C'&&ch!='M'&&ch!='Y'&&ch!='W'&&ch!='G'&&ch!='B') ch=getchar();
            if (ch!='B'&&ch!='W'&&ch!='G') ans=0;
        }
    if (ans==0) printf("#Color\n"); else printf("#Black&White\n");
    return 0;
}