#include <iostream>
using namespace std;
int main()
{
    long int i,j,n,sum,ans,t,a[100001];
    cin>>n>>t;
    for(i=0;i<n;i++) cin>>a[i];
    ans=0;j=n-1;sum=0;i=n-1;
    while (i>=0)
    {
        while ((i>=0)&&(sum+a[i]<=t)) {sum+=a[i];i--;}
        if (j-i>ans) ans=j-i;
        if (sum) sum=sum-a[j];j--;
        if (j<i) i=j;
    }
    cout<<ans;
}