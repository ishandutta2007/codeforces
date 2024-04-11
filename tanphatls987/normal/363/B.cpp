#include <iostream>

using namespace std;

int main()
{
    int a[200000],n,k,tmp,i,ans;
    long int sans,sum;
    cin>>n>>k;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<k;i++) sum+=a[i];
    ans=0;sans=sum;
    for(i=k;i<n;i++)
    {sum=sum+a[i]-a[i-k];if (sum<sans) {sans=sum;ans=i-k+1;}}
    cout<<ans+1;
}