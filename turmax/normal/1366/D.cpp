#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e7+5;
bool used[maxn];
int is[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    used[0]=true;
    used[1]=true;
    for(int i=2;i<maxn;++i)
    {
        if(!used[i])
        {
            for(int j=2*i;j<maxn;j+=i)
            {
                used[j]=true;
                is[j]=i;
            }
        }
    }
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    pair <int,int> ans[n];
    for(int i=0;i<n;++i)
    {
        int x=a[i];
        if(!used[x])
        {
            ans[i].first=(-1);
            ans[i].second=(-1);
            continue;
        }
        else
        {
            int o=is[x];
            int u=x;
            int c=1;
            while(u%o==0)
            {
                u/=o;
                c*=o;
            }
            if(c==x)
            {
                ans[i].first=(-1);
                ans[i].second=(-1);
                continue;
            }
            ans[i].first=u;ans[i].second=c;
        }
    }
    for(int i=0;i<n;++i) cout<<ans[i].first<<" ";
    cout<<endl;
    for(int i=0;i<n;++i) cout<<ans[i].second<<" ";
    return 0;
}