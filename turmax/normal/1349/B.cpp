#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    int a[n];
    int curr=(-5);
    int curr1=(-5);
    bool h=true;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            curr1=i;
        }
        if(a[i]>=k)
        {
            if(i<=(curr+2))
            {
                h=false;
            }
            else
            {
                curr=i;
            }
        }
    }
    if(curr1==(-5) || (h && n!=1))
    {
        cout<<"no"<<endl;
        continue;
    }
    else
    {
        cout<<"yes"<<endl;
    }
    }
    return 0;
}