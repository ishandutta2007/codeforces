#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    int n;
    vector <pair<int,int> > a;
    int x,y;
    set <pair<int,int> > d;
    int curr;
    int sum;
    for(int i=0;i<q;++i)
    {
        cin>>n;
        a.resize(n);
        d.clear();
        curr=n;
        sum=0;
        for(int i=0;i<n;++i)
        {
            cin>>x>>y;
            a[i]={x,y};
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        for(int i=0;i<n;++i)
        {
            d.insert({a[i].second,i});
            if(a[i].first>=curr)
            {
                sum+=(*d.begin()).first;
                d.erase(d.begin());
                curr++;
            }
            curr--;
        }
        cout<<sum<<endl;
    }
    return 0;
}