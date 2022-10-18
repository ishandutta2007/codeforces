#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char c[n+1];
    scanf("%s",c);
    string s=c,m=s;
    s+=s;
    string inc[10];
    for(int i=0;i<10;i++)
    {
        inc[i]=s;
        for(int j=0;j<s.length();j++)
            inc[i][j]=(inc[i][j]-'0'+i)%10+'0';
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<n;j++)
            m=min(m,inc[i].substr(j,n));
    printf("%s",m.c_str());
}