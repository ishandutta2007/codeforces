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
        int a[n];pair <int,int> mi[n+1];mi[0]={1e18,-1};int curr=1e18;
        for(int i=0;i<n;++i) {cin>>a[i];mi[i+1]=mi[i];if(a[i]<curr) {curr=a[i];mi[i+1]={curr,i};}}
        vector <int> v1,v2;
        int r=n;
        while(true)
        {
            int pos=mi[r].second;
            v1.push_back(a[pos]);for(int i=(r-1);i>pos;--i) v2.push_back(a[i]);
            r=pos;
            if(r==0) break;
        }
        for(auto h:v1) cout<<h<<' ';
        reverse(v2.begin(),v2.end());
        for(auto h:v2) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}