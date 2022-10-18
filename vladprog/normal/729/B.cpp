#include<bits/stdc++.h>

using namespace std;

#define print(s,a) \
{ \
    cout<<s; \
    for(int i=1;i<=n;i++) \
    { \
        for(int j=1;j<=m;j++) \
            cout<<a[i][j]<<' '; \
        cout<<endl; \
    } \
    cout<<endl; \
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+2][m+2];
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int l[n+2][m+2],r[n+2][m+2],u[n+2][m+2],d[n+2][m+2];
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(u,0,sizeof(u));
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            l[i][j]=l[i][j-1]|a[i][j-1];
            u[i][j]=u[i-1][j]|a[i-1][j];
        }
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        {
            r[i][j]=r[i][j+1]|a[i][j+1];
            d[i][j]=d[i+1][j]|a[i+1][j];
        }
    int k=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!a[i][j])
                k+=l[i][j]+r[i][j]+u[i][j]+d[i][j];
    /*print("a:\n",a);
    print("l:\n",l);
    print("r:\n",r);
    print("u:\n",u);
    print("d:\n",d);*/
    cout<<k;
}