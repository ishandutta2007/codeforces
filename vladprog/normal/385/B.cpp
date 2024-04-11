#include<bits/stdc++.h>

using namespace std;

int main()
{
    char c[5001];
    scanf("%s",c);
    string s=c;
    int n=s.length();
    int l[n],r[n];
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    for(int i=0;i<n-3;i++)
        if(s.substr(i,4)=="bear")
            l[i+1]=l[i]+1,r[i+3]=r[i+2]+1;
        else
            l[i+1]=l[i],r[i+3]=r[i+2];
    l[n-1]=l[n-2]=l[n-3];
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(r[j]-l[i]>0)
                ans++;
    printf("%d",ans);
}