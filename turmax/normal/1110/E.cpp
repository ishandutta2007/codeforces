#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    vector <int> b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    vector <int> v1(n-1);
    vector <int> v2(n-1);
    map <int,int> o1;
    map <int,int> o2;
    for(int i=1;i<n;++i)
    {
        v1[i-1]=a[i]-a[i-1];
        v2[i-1]=b[i]-b[i-1];
        if(o1.count(v1[i-1]))
        {
            o1[v1[i-1]]++;
        }
        else
        {
            o1[v1[i-1]]=1;
        }
        if(o2.count(v2[i-1]))
        {
            o2[v2[i-1]]++;
        }
        else
        {
            o2[v2[i-1]]=1;
        }
    }
    /*for(int i=0;i<(n-1);++i)
    {
        cout<<v1[i]<<" "<<v2[i]<<endl;
    }*/
    bool ans=true;
    if(a[0]!=b[0] || a[n-1]!=b[n-1])
    {
        ans=false;
    }
    for(int i=0;i<(n-1);++i)
    {
        if(!o2.count(v1[i]) || o1[v1[i]]!=o2[v1[i]])
        {
            ans=false;
        }
    }
    for(int i=0;i<(n-1);++i)
    {
        if(!o1.count(v2[i]) || o1[v2[i]]!=o2[v2[i]])
        {
            ans=false;
        }
    }
    if(ans)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}