#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    pair <int,int> a[k];
    pair <int,int> b[k];
    for(int i=0;i<k;++i)
    {
        cin>>a[i].first>>a[i].second;
        a[i].first--;a[i].second--;
    }
    for(int i=0;i<k;++i)
    {
        cin>>b[i].first>>b[i].second;
        b[i].first--;b[i].second--;
    }
    string ans;
    for(int i=0;i<(m-1);++i)
    {
        ans+='L';
    }
    for(int i=0;i<(n-1);++i)
    {
        ans+='U';
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<(m-1);++j)
        {
            if(i%2==0)
            {
                ans+='R';
            }
            else
            {
                ans+='L';
            }
        }
        ans+='D';
    }
    cout<<ans.size()<<endl;
    cout<<ans;
    return 0;
}