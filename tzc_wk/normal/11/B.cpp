#include<iostream>
using namespace std;
int n,ans=0,i;
int main()
{
    cin>>n;
    int st;
    if(n>0)	st=n;
    else st=-n;
    for(n=st;i<n||i%2!=n%2;i+=ans)	ans++;
    cout<<ans;
}