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
        int sum=0;
        int a[n+1];
        for(int i=1;i<=n;++i) a[i]=i;
        vector <pair<int,int> > v;
        for(int i=(n-1);i>=1;--i)
        {
            if((i-1)>=(n-i))
            {
                v.push_back({i,1});
                sum+=((i-1)*(i-1));
            }
            else
            {
                v.push_back({i,n});
                sum+=((n-i)*(n-i));
            }
        }
        cout<<sum<<endl;
        reverse(v.begin(),v.end());
        for(auto h:v) swap(a[h.first],a[h.second]);
        reverse(v.begin(),v.end());
        for(int i=1;i<=n;++i) cout<<a[i]<<' ';
        cout<<endl;
        cout<<v.size()<<endl;
        for(auto h:v) cout<<h.first<<' '<<h.second<<endl;
    }
    return 0;
}