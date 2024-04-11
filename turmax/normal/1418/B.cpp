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
        vector <int> v;
        vector <int> v1;
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            if(x==0) {v.push_back(a[i]);v1.push_back(i);}
        }
        sort(v.begin(),v.end());reverse(v.begin(),v.end());
        for(int i=0;i<v.size();++i) a[v1[i]]=v[i];
        for(int i=0;i<n;++i) cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}