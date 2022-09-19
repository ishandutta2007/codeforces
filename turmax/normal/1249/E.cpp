#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,c;
    cin>>n>>c;
    vector <int> a(n);
    vector <int> b(n);
    vector <pair<int,int> > u(n);
    a[0]=0;
    b[0]=0;
    int x;
    for(int i=1;i<n;++i)
    {
        cin>>x;
        a[i]=x;
    }
    for(int i=1;i<n;++i)
    {
        cin>>x;
        b[i]=x;
    }
    u[0]={c,0};
    for(int i=1;i<n;++i)
    {
        u[i].first=min(u[i-1].first+b[i],u[i-1].second+b[i]+c);
        u[i].second=min(u[i-1].first+a[i],u[i-1].second+a[i]);
    }
    for(int i=0;i<n;++i)
    {
        cout<<min(u[i].first,u[i].second)<<" ";
    }
    return 0;
}