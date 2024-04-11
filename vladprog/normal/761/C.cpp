#include<bits/stdc++.h>

using namespace std;

bool isb(char c)
{
    return (c>='a')&&(c<='z');
}

bool isc(char c)
{
    return (c>='0')&&(c<='9');
}

bool isz(char c)
{
    return (c=='*')||(c=='#')||(c=='&');
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char s[n][m+1];
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int b[n],c[n],z[n];
    for(int i=0;i<n;i++)
        b[i]=c[i]=z[i]=1e3;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(isb(s[i][j]))
                b[i]=min(b[i],j);
            if(isc(s[i][j]))
                c[i]=min(c[i],j);
            if(isz(s[i][j]))
                z[i]=min(z[i],j);
        }
    for(int i=0;i<n;i++)
        for(int j=m-1;j>=0;j--)
        {
            if(isb(s[i][j]))
                b[i]=min(b[i],m-j);
            if(isc(s[i][j]))
                c[i]=min(c[i],m-j);
            if(isz(s[i][j]))
                z[i]=min(z[i],m-j);
        }
    int ans=1e3;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if(i!=j&&i!=k&&j!=k)
                    ans=min(ans,b[i]+c[j]+z[k]);
    printf("%d",ans);
}