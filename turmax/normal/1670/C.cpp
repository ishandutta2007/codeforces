#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=5e5+5;
int t[maxn];bool h[maxn];bool used[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1;cin>>t1;
    while(t1--)
    {
        int n;cin>>n;
        int a[n],b[n],c[n];for(int i=0;i<n;++i) {cin>>a[i];} for(int i=0;i<n;++i) {cin>>b[i];} for(int i=0;i<n;++i) {cin>>c[i];}
        for(int i=0;i<=n;++i) {t[i]=0;h[i]=0;used[i]=0;}
        for(int i=0;i<n;++i) {t[a[i]]=b[i];if(c[i]!=0) h[a[i]]=1;}
        int ans=1;
        for(int i=1;i<=n;++i)
        {
            if(!used[i])
            {
                vector<int> v;
                int cur=t[i];
                while(true)
                {
                    v.push_back(cur);
                    if(cur==i) break;
                    cur=t[cur];
                }
                for(auto h:v) used[h]=true;
                bool ok=(v.size()!=1);
                for(auto x:v) {ok=(ok && !h[x]);}
                if(ok) {ans*=2;if(ans>=p) ans-=p;}
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}