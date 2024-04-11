#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> slv(int x,int y)
{
    return {-y,x};
}
vector <int> slv(int x,int y,int z)
{
    if((y+z)!=0)
    return {-y-z,x,x};
    else if((x+z)!=0)
    return {y,-x-z,y};
    else if((x+y)!=0)
    return {z,z,-x-y};
}
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
        for(int i=0;i<n;++i) cin>>a[i];
        vector <int> ans;
        if(n%2==0)
        {
            for(int i=0;i<n/2;++i) {vector <int> v=(slv(a[2*i],a[2*i+1]));for(auto h:v) ans.push_back(h);}
        }
        else
        {
            ans=slv(a[0],a[1],a[2]);
            for(int i=1;i<n/2;++i) {vector <int> v=(slv(a[2*i+1],a[2*i+2]));for(auto h:v) ans.push_back(h);}
        }
        for(auto h:ans) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}