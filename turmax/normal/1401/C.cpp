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
    int mi=1e18;
    vector <int> b;
    for(int i=0;i<n;++i) {cin>>a[i];mi=min(mi,a[i]);b.push_back(a[i]);}
    sort(b.begin(),b.end());
    vector <int> v;
    vector <int> l;
    vector <int> r;
    for(int i=0;i<n;++i)
    {
        if((a[i]%mi)!=0)
        {
            v.push_back(a[i]);
        }
        else
        {
            l.push_back(b[i]);
            r.push_back(a[i]);
        }
    }
    sort(r.begin(),r.end());
    sort(l.begin(),l.end());
    vector <int> u=v;
    sort(u.begin(),u.end());
    if(u==v && l==r)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}