#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(vector<int> a)
{
    int n=a.size();
    int ans1=0;for(int i=0;i<n-1;++i) ans1=max(ans1,min(a[i],a[i+1]));
    int mi=(*min_element(a.begin(),a.end()));
    return min(2*mi,ans1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;vector<int> a(n);pair<int,int> b[n+1];for(int i=0;i<n;++i) {cin>>a[i];b[i]={a[i],i};} b[n]={1e9,n};
        sort(b,b+n+1);int o=b[k].first;int o1=b[k-1].first;
        if(k==n) {cout<<(int) 1e9<<'\n';continue;}
        if(k==1)
        {
            int pos=(max_element(a.begin(),a.end())-a.begin());
            int pos2=(min_element(a.begin(),a.end())-a.begin());
            vector<int> v={pos2,pos-1,pos,pos+1};
            int res=0;
            for(int pos:v)
            {
                if(pos>=0 && pos<n)
                {
                    int x=a[pos];
                    a[pos]=1e9;res=max(res,go(a));a[pos]=x;
                }
            }
            cout<<res<<'\n';
            continue;
        }
        for(int i=0;i<k;++i) a[b[i].second]=1e9;
        cout<<min((int) 1e9,max(2*o1,go(a)))<<'\n';
    }
    return 0;
}