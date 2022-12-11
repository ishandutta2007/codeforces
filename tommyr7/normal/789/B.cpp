#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
long long b1,q,l,m;
int tot;
int main()
{
    b1=read(),q=read(),l=read(),m=read();
if (abs(b1)>l) {cout <<0<<endl;return 0;}
    if (b1==0)
    {
        tot=1;
        for (int i=1;i<=m;i++) if (read()==0) --tot;
        if (tot==0) cout << tot <<endl; else cout << "inf" << endl;
    } else if (q==0)
    {
        bool check=true;
        tot=2;
        for (int i=1;i<=m;i++) 
        {
            long long x=read();
            if (x==0) check=false;
            if (x==b1||x==0) tot-=1;
        }
        if (check) cout << "inf" << endl; else cout << tot << endl;
    } else if (q==1)
    {
        tot=1;
        for (int i=1;i<=m;i++) if (read()==b1) --tot;
        if (tot==0) cout << tot << endl; else cout << "inf" << endl;
    } else if (q==-1)
    {
        tot=2;
        for (int i=1;i<=m;i++)
        {
            long long x=read();
            if (x==b1||x+b1==0) --tot;
        }
        if (tot==0) cout << tot << endl; else cout <<"inf" <<endl;
    } else
    {
        tot=0;
        long long b=b1;
        while (abs(b)<=l)
        {
            ++tot;
            b=1LL*b*q;
        }
        for (int i=1;i<=m;i++)
        {
            long long x=read();
            if (abs(x)%abs(b1)==0&&abs(x)<=l&&x!=0)
            {
                x/=b1;
                while (abs(x)%abs(q)==0) x/=q;
                if (x==1) --tot;
            }
        }
        cout <<tot<<endl;
    }
    return 0;
}