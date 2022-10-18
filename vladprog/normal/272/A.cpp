#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int s=0;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        s+=t;
    }
    int ans=0;
    for(int i=1;i<=5;i++)
        if(((s+i)%(n+1))!=1)
            ans++;
    printf("%d",ans);
}