#include <iostream>
using namespace std;
int a[1000],n,l,r,ans;
int main()
{
    cin>>n; 
    for(int i=1; i<n; i++)
    cin>>a[i];
    cin>>l>>r;
    for(int i=l; i<=r-1; i++)	ans+=a[i];
    cout<<ans<<endl;
    return 0;
}