#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    vector <pair<int,int> > v;
    int curr=1;
    int ch=a[0];
    for(int i=1;i<n;++i)
    {
        if(a[i]==ch) ++curr;
        else
        {
            v.push_back({ch,curr});
            curr=1;
            ch=a[i];
        }
    }
    v.push_back({ch,curr});
    vector <int> z;
    int ans=0;
    for(int i=0;i<v.size();++i) ans+=min(2LL,v[i].second);
    for(int i=0;i<v.size()-1;++i)
    {
        if(v[i].second>=2)
        {
            for(int j=(i+1);j<v.size();++j)
            {
                if(v[j].second>=2)
                {
                    if(v[j].first!=v[i].first || ((j-i)%2)!=0) break;
                    bool h=true;
                    for(int k=i;k<=j;k+=2)
                    {
                        if(v[k].first!=v[i].first)
                        {
                            h=false;
                        }
                    }
                    if(h) ans--;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}