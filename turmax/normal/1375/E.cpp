#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector <pair<int,int> > v(n);
    for(int i=0;i<n;++i) v[i]={a[i],i};
    int l=0;
    vector <pair<int,int> > res;
    while(l<(n-1))
    {
        l=max(l,0LL);
        if(v[l+1].first<v[l].first)
        {
            res.push_back({v[l].second,v[l+1].second});
            swap(v[l],v[l+1]);
            l--;
        }
        else
        {
            ++l;
        }
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i].first+1<<' ' <<res[i].second+1<<'\n';
    }
    return 0;
}