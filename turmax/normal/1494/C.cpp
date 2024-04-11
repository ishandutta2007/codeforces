#include <bits/stdc++.h>

using namespace std;
#define int long long
int slv(vector <int> a,vector <int> b)
{
    for(auto &h:a) h=(-h);
    for(auto &h:b) h=(-h);
    /*for(auto h:a) cout<<h<<' ';
    cout<<endl;
    for(auto h:b) cout<<h<<' ';
    cout<<endl;*/
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    int u=0;
    int ans=0;
    int cnt=b.size();
    for(int i=((int) b.size())-1;i>=0;i--)
    {
        int h=b[i];
        if(upper_bound(a.begin(),a.end(),h)-lower_bound(a.begin(),a.end(),h))
        {
            ++u;
            ans=max(ans,u);
            continue;
        }
        else
        {
            int cnt=lower_bound(a.begin(),a.end(),h)-a.begin();
            ans=max(ans,u+(upper_bound(b.begin(),b.end(),h)-upper_bound(b.begin(),b.end(),h-cnt)));
        }
    }
    //cout<<ans<<" ans1 "<<endl;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<m;++i) cin>>b[i];
        sort(a,a+n);sort(b,b+m);
        vector <int> a1,a2;
        vector <int> b1,b2;
        for(auto h:a) {if(h>0) a2.push_back(-h);else a1.push_back(h);}
        for(auto h:b) {if(h>0) b2.push_back(-h);else b1.push_back(h);}
        cout<<slv(a1,b1)+slv(a2,b2)<<'\n';
    }
    return 0;
}