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
    int a[n];
    vector <int> u[501];
    for(int i=0;i<n;++i) {cin>>a[i];u[a[i]].push_back(i);a[i]=1000*a[i]+i;}
    int o=0;
    for(int i=0;i<n;++i)
    {
        for(int j=(i+1);j<n;++j)
        {
            if(a[j]<a[i])
            {
                ++o;
            }
        }
    }
    if(o%2==1)
    {
        bool h=false;
        for(int i=0;i<=500;++i)
        {
            if(u[i].size()>=2)
            {
                swap(a[u[i][0]],a[u[i][1]]);
                h=true;
                break;
            }
        }
        if(!h)
        {
            cout<<(-1)<<endl;
            continue;
        }
    }
    int l=0;
    vector <int> v;
    while(l<n)
    {
        int mi=1e18;
        int h=0;
        for(int i=l;i<n;++i)
        {
            if(a[i]<mi)
            {
                mi=a[i];
                h=i;
            }
        }
        if(h==l)
        {
            ++l;
            continue;
        }
        if(h==(l+1))
        {
            v.push_back(l);v.push_back(l);
            int x=a[l];int y=a[l+1];int z=a[l+2];
            a[l]=y;a[l+1]=z;a[l+2]=x;
            continue;
        }
        v.push_back(h-2);
        int x=a[h-2];int y=a[h-1];int z=a[h];
        a[h-1]=x;a[h]=y;a[h-2]=z;
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<' ';
    }
    cout<<endl;
    }
    return 0;
}