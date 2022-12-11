#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k,tot;
int main()
{
    n=read(),k=read();
    tot=0;
    for (int i=1;i<=n;i++) tot+=(read()+k-1)/k;
    tot=(tot+1)/2;
    cout << tot <<endl;
    return 0;
}