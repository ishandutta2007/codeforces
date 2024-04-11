#include<bits/stdc++.h>
using namespace std;
bool a[105];
int b[105];
int s;
int main()
{
    int m,n,t;
    cin>>m>>n;
    s=1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&t);
        if(a[t]==false)
        {
            b[s++]=i;
        }
        a[t]=true;
    }
    int ans=0;
    s--;
    if(s<n)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}