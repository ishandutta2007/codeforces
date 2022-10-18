#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int l=1,r=n;
    if(a[1]!=a[n])
    {
        cout<<n-1<<endl;
        return 0;
    }
    while(a[l+1]==a[l])
    {
        l++;
    }
    while(a[r-1]==a[r])
    {
        r--;
    }
    int ans=max(r-1,n-(l+1)+1);
    cout<<ans-1<<endl;
    return 0;
}