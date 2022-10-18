#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int n;
    cin>>n;
    int p;
    cin>>p;
    n--;
    int ans=0;
    while(n--)
    {
        int t;
        cin>>t;
        if(t<p)
            ans+=p-t;
        p=t;
    }
    cout<<ans;
}