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
        int c1=0,c2=0;
        int a[n];
        for(int i=0;i<n;++i) {cin>>a[i];if(a[i]==1) ++c1;else ++c2;}
        if(c1%2==1) {cout<<"NO"<<'\n';continue;}
        if(c1==0 && c2%2==1) {cout<<"NO"<<'\n';continue;}
        cout<<"YES"<<'\n';
    }
    return 0;
}