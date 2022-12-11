#include <iostream>

using namespace std;

int main()
{
    long int i,j,ans,tmp,n,a[100];
    long int s[100]={0};
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++)
        for(j=0;j<a[i];j++) {cin>>tmp;s[i]+=(5*tmp+15);}
    ans=5000000;
    for(i=0;i<n;i++) if (s[i]<ans) ans=s[i];
    cout<<ans;
}