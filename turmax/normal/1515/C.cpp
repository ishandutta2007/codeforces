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
        int n,m,x;
        cin>>n>>m>>x;
        int a[n];
        int ans[n];
        for(int i=0;i<n;++i) {cin>>a[i];ans[i]=(-1);}
        set <pair<int,int> > tow;
        for(int i=0;i<m;++i) tow.insert({0,i});
        for(int i=0;i<n;++i)
        {
            pair <int,int> o=(*tow.begin());
            tow.erase(o);
            ans[i]=o.second;
            o.first+=a[i];
            tow.insert(o);
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i) cout<<ans[i]+1<<' ';
        cout<<endl;
    }
    return 0;
}