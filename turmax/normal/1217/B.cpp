#include <bits/stdc++.h>

using namespace std;
#define int long long
bool comp(pair <int,int> x,pair <int,int> y)
{
    return x.second>y.second;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n,x;
    vector <pair<int,int> > a;
    int x1,x2;
    int curr;
    int o;
    int v;
    int u1;
    int u2;
    for(int i=0;i<t;++i)
    {
        v=0;
        cin>>n>>x;
        a.resize(n);
        o=0;
        curr=x;
        for(int j=0;j<n;++j)
        {
            cin>>x1>>x2;
            a[j]={x1,x1-x2};
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        u1=a[0].first;
        sort(a.begin(),a.end(),comp);
        u2=a[0].second;
        if(u2<=0 && u1<curr)
        {
            cout<<(-1)<<endl;
        }
        else if(u1>=curr)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<((curr-u1+(u2-1))/u2+1)<<endl;
        }
    }
    return 0;
}