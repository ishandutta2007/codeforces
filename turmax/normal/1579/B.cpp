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
        for(int i=0;i<n;++i) cin>>a[i];
        vector <vector <int> > v;
        for(int i=0;i<(n-1);++i)
        {
            int mi=1e18;int curr=(-1);
            for(int j=i;j<n;++j)
            {
                if(a[j]<mi) {mi=a[j];curr=j;}
            }
            if(curr==i) continue;
            if(curr!=i) v.push_back({i+1,n,curr-i});
            vector <int> g;
            int b[n];
            for(int j=0;j<n;++j) b[j]=a[j];
            for(int j=i;j<n;++j) b[(j+n-curr-i)%(n-i)+i]=a[j];
            for(int j=0;j<n;++j) a[j]=b[j];
        }
        cout<<v.size()<<endl;
        for(auto h:v) {for(auto h1:h) cout<<h1<<' '; cout<<endl;}
    }
    return 0;
}