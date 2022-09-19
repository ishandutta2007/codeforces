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
        int n,m,k;
        cin>>n>>m>>k;
        if(n%2==0 && m%2==0)
        {
            if(k%2==0 && k>=0 && k<=(n*m)/2) cout<<"YES";
            else cout<<"NO";
            cout<<'\n';
            continue;
        }
        if(n%2==1 && m%2==1)
        {
             cout<<"NO"<<'\n';
             return 0;
        }
        if(n%2==0 && m%2==1)
        {
            if(k%2==0 && k>=0 && k<=(n*m-n)/2) cout<<"YES";
            else cout<<"NO";
            cout<<'\n';
            continue;
        }
        if(n%2==1 && m%2==0)
        {
            if(k%2==(n*m/2)%2 && k>=(m/2) && k<=(n*m)/2) cout<<"YES";
            else cout<<"NO";
            cout<<'\n';
            continue;
        }
    }
    return 0;
}