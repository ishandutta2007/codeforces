#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;

struct A
{
    int a,id;
}arr[maxn];
int ans[maxn],dp[maxn],lst[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i].a);
        arr[i].id=i;
    }
    sort(arr,arr+n,[](A a,A b){return a.a<b.a;});

    int sum=0;
    for(int i=n-1;i;i--)
    {
        arr[i].a-=arr[i-1].a;
        sum+=arr[i].a;
    }
    if(n<6)
    {
        cout<<sum<<" 1"<<endl;
        for(int i=0;i<n;i++)cout<<1<<' ';
        return 0;
    }
    for(int i=3;i<n-2;i++)
    {
        if(dp[i-1]>dp[i-3]+arr[i].a)
        {
            dp[i]=dp[i-1];
            lst[i]=i-1;
        }
        else
        {
            dp[i]=dp[i-3]+arr[i].a;
            lst[i]=i-3;
        }
    }
    sum-=dp[n-3];
    int cnt=1;
    for(int i=n-1;i>=0;i--)
    {
        if(lst[i]==i-3)
        {
            ans[arr[i].id]=cnt++;
            lst[i]=-1;
            i=i-2;
        }
    }
    ans[arr[0].id]=cnt;
    for(int i=1;i<n;i++)
    {
        if(lst[i]!=-1)
        {
            ans[arr[i].id]=ans[arr[i-1].id];
        }
    }
    cout<<sum<<' '<<cnt<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}