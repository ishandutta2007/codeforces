#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int sum(int x)
{
    return x*(x+1)/2;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"YES\n";
        cout<<n<<endl;
        return 0;
    }
    if(n<(k*(k+1)/2))
    {
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        a[i]=i;
    }
    n-=k*(k+1)/2;
    int res=0;
    a[0]=100000000;
    for(int i=1;i<=k;i++)
    {
        // cout<<i<<endl;
        int add=min(a[i-1]*2-a[i],n/(k-i+1));
        // cout<<"Passed\n";
        n-=add*(k-i+1);
        res+=add;
        a[i]+=res;
    }
    if(n!=0)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1;i<=k;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}