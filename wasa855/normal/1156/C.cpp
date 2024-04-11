#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool used[200005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int ans=0;
    int x=1;
    for(int i=n/2+1;i<=n;i++)
    {
        if(a[i]-k>=a[x])
        {
            ans++;
            x++;
        }
    }
    cout<<min(n/2,ans)<<endl;
    return 0;
}