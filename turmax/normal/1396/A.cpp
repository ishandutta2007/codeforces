#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cout<<1<<" "<<1<<endl;
    cout<<(n-a[0])<<endl;
    a[0]=n;
    if(n==1)
    {
        cout<<1<<" "<<1<<endl;
        cout<<(n-a[0])<<endl;
        a[0]=n;
    }
    else
    {
        cout<<2<<" "<<n<<endl;
        for(int i=1;i<n;++i)
        {
            cout<<(a[i]*(n-1))<<' ';
            a[i]*=n;
        }
        cout<<endl;
    }
    cout<<1<<" "<<n<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<-a[i]<<' ';
    }
    return 0;
}