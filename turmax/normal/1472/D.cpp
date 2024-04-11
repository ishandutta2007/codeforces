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
        int n;
        cin>>n;
        int a[n];
        vector <int> z0,z1;
        for(int i=0;i<n;++i) {cin>>a[i];if(a[i]%2==0) z0.push_back(a[i]);else z1.push_back(a[i]);}
        sort(z0.begin(),z0.end());sort(z1.begin(),z1.end());
        //reverse(z0.begin(),z0.end());reverse(z1.begin(),z1.end());
        int sum0=0,sum1=0;
        for(auto h:z0) sum0+=h;
        for(auto h:z1) sum1+=h;
        sort(a,a+n);reverse(a,a+n);
        int res1=0;
        for(int i=0;i<n;++i) {if(i%2==0) res1+=a[i];else res1-=a[i];}
        if((res1+sum0)>sum1)
        {
            cout<<"Alice"<<'\n';
        }
        if((res1+sum0)==sum1)
        {
            cout<<"Tie"<<'\n';
        }
        if((res1+sum0)<sum1)
        {
            cout<<"Bob"<<'\n';
        }
    }
    return 0;
}