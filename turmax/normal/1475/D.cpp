#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> pr(vector <int> v)
{
    vector <int> z={0};
    for(auto h:v) z.push_back(z.back()+h);
    return z;
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
        int a[n],b[n];
        vector <int> v1,v2;
        int sum=0;
        for(int i=0;i<n;++i) {cin>>a[i];sum+=a[i];}
        for(int i=0;i<n;++i) {cin>>b[i];if(b[i]==1) v1.push_back(a[i]); else v2.push_back(a[i]);}
        sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());reverse(v1.begin(),v1.end());reverse(v2.begin(),v2.end());
        vector <int> pr1=pr(v1);vector <int> pr2=pr(v2);
        int ans=1e18;
        //cout<<pr2.back()<<" back "<<endl;
        for(int i=0;i<pr1.size();++i)
        {
            if((m-pr1[i])>pr2.back()) continue;
            int j=lower_bound(pr2.begin(),pr2.end(),m-pr1[i])-pr2.begin();
            ans=min(ans,i+2*j);
        }
        if(ans==1e18) ans=(-1);
        cout<<ans<<endl;
    }
    return 0;
}