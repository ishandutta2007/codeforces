#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,r;
        cin>>n>>r;
        long long ans=0;
        if(n<=r)
        {
            ans+=(n-1)*(n)/2;
            ans+=1;
        }
        else
        {
            ans+=r*(r+1)/2;
        }
        cout<<ans<<'\n';
    }
}