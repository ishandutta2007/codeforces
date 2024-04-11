#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int ans[maxn];
void slv(vector <int> v)
{
    sort(v.begin(),v.end());
    int n=v.size();
    int pr[n+1];pr[0]=0;
    for(int i=0;i<n;++i) pr[i+1]=pr[i]+v[i];
    for(int k=1;k<=n;++k)
    {
        ans[k]+=(pr[n]-pr[n%k]);
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
        vector <int> v[n];
        int a[n],b[n];
        for(int i=1;i<=n;++i) ans[i]=0;
        int sum=0;
        for(int i=0;i<n;++i) {cin>>a[i];a[i]--;}
        for(int i=0;i<n;++i) {cin>>b[i];v[a[i]].push_back(b[i]);sum+=b[i];}
        for(int i=0;i<n;++i)
        {
            if(!v[i].empty())
            {
                slv(v[i]);
            }
        }
        for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}