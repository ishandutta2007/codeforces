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
        int n,x;
        cin>>n>>x;
        int a[n];
        bool used[n];
        int sum=0;
        for(int i=0;i<n;++i) {cin>>a[i];used[i]=0;sum+=a[i];}
        if(sum==x)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        int curr=x;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(!used[j] && a[j]!=curr)
                {
                    curr-=a[j];
                    used[j]=true;
                    cout<<a[j]<<' ';
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}