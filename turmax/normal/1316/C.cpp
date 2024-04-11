#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,p;
    cin>>n>>m>>p;
    vector <int> a(n);
    vector <int> b(m);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int ans=0;
    while(true)
    {
        if(b[b.size()-1]%p==0)
        {
            b.erase(b.begin()+b.size()-1);
            ++ans;
            continue;
        }
        if(a[a.size()-1]%p==0)
        {
            a.erase(a.begin()+a.size()-1);
            ++ans;
            continue;
        }
        cout<<ans;
        exit(0);
    }
    return 0;
}