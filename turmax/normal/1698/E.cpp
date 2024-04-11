#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,s;cin>>n>>s;
        int a[n],a1[n+1],b[n],b1[n+1];set<int> o;set<int> h;for(int i=0;i<n;++i) b1[i]=(-1);for(int i=0;i<n;++i) {cin>>a[i];a1[a[i]]=i;}
        for(int i=0;i<n;++i) {cin>>b[i];if(b[i]!=(-1)) h.insert(i); if(b[i]!=(-1)) o.insert(b[i]); if(b[i]!=(-1)) b1[b[i]]=i;}
        set<int> d;int c=0;
        for(int i=1;i<=s;++i)
        {
            if(h.count(a1[i])) d.insert(a1[i]);
            else ++c;
        }
        int ans=1;
        for(int i=1;i<=n;++i)
        {
            if(i+s<=n)
            {
                if(h.count(a1[i+s])) d.insert(a1[i+s]);
                else ++c;
            }
            if(!o.count(i))
            {
                ans*=c;ans%=p;--c;
            }
            else
            {
                if(!d.count(b1[i])) ans=0;
                else d.erase(b1[i]);
            }
        }
        cout<<(ans%p+p)%p<<'\n';
    }
    return 0;
}