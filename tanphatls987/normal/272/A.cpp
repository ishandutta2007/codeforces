#include <iostream>

using namespace std;

int main()
{
    int n,i,tmp,sum,ans;
    cin>>n;
    sum=0;ans=0;
    for(i=0;i<n;i++) {cin>>tmp;sum+=tmp;}
    for(i=1;i<=5;i++)
    if (n>1) {if ((sum+i)%(n+1)!=1) ans++;}else if ((sum+i)%2==0) ans++;
    cout<<ans;
}