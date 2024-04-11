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
    int h[n+1];
    for(int i=0;i<=n;++i) h[i]=1;
    for(int i=0;i<n;++i) h[a[i]]--;
    set <int> d;
    for(int i=0;i<=n;++i)
    {
        if(h[i]>0)
        {
            d.insert(i);
        }
    }
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        int x=*d.begin();
        v.push_back(x);
        d.erase(d.begin());
        h[x]--;
        h[a[i]]++;
        if(h[a[i]]>0)
        {
            d.insert(a[i]);
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<v[i]<<' ';
    }
    return 0;
}