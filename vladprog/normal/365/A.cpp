#include<bits/stdc++.h>

using namespace std;

bool good(string s,int k)
{
    bool ok[k+1];
    memset(ok,0,sizeof(ok));
    for(int i=0;i<s.length();i++)
        if((s[i]-'0')<=k)
            ok[s[i]-'0']=true;
    int sum=0;
    for(int i=0;i<=k;i++)
        if(ok[i])
            sum++;
    return sum==k+1;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        char c[11];
        scanf("%s",c);
        string s=c;
        if(good(s,k))
            ans++;
    }
    printf("%d",ans);
}