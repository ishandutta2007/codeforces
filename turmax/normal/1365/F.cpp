#include <bits/stdc++.h>

using namespace std;
#define int long long
pair <int,int> s(pair <int,int> a)
{
    if(a.second>=a.first)
    {
        return a;
    }
    else
    {
        return {a.second,a.first};
    }
}
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
    int b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    if(n%2==1)
    {
        if(a[(n-1)/2]!=b[(n-1)/2])
        {
            cout<<"No"<<endl;
            continue;
        }
    }
    vector <pair<int,int> > ua;
    for(int i=0;i<n/2;++i)
    {
        ua.push_back(s({a[i],a[n-i-1]}));
    }
    vector <pair<int,int> > ub;
    for(int i=0;i<n/2;++i)
    {
        ub.push_back(s({b[i],b[n-i-1]}));
    }
    sort(ua.begin(),ua.end());sort(ub.begin(),ub.end());
    bool h=true;
    for(int i=0;i<ua.size();++i)
    {
        if(ua[i]!=ub[i])
        {
            h=false;
            break;
        }
    }
    if(h)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    }
    return 0;
}