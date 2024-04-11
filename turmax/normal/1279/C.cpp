#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n,m;
    cin>>n>>m;
    vector <int> c(n);
    int x;
    vector <int> b(m);
    for(int i=0;i<n;++i)
    {
        cin>>x;
        x--;
        c[x]=i;
    }
    for(int i=0;i<m;++i)
    {
        cin>>x;
        x--;
        b[i]=c[x];
    }
    int ma=(-1e18);
    int sum=0;
    int u=0;
    for(int i=0;i<m;++i)
    {
        if(b[i]>ma)
        {
            ma=b[i];
            sum+=2*(ma-i);
        }
        ++sum;
    }
    cout<<sum<<endl;
    }
    return 0;
}