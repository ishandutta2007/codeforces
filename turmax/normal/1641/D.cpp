#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
int cnt[1<<20];
int col[maxn];
int mask[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    mt19937 rnd(228228);
    int n,m;
    cin>>n>>m;
    set <int> moms1;
    vector <int> moms;
    vector <int> a[n];for(int i=0;i<n;++i) {a[i].resize(m);for(auto &h:a[i]) cin>>h; for(auto h:a[i]) moms1.insert(h); int w;cin>>w;a[i].push_back(w);}
    for(auto h:moms1) moms.push_back(h);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int pos=lower_bound(moms.begin(),moms.end(),a[i][j])-moms.begin();
            a[i][j]=pos;
        }
    }
    int ans=1e18;
    for(int it=0;it<35;++it)
    {
        for(int j=0;j<moms.size();++j)
        {
            col[j]=(rnd()%20);
        }
        for(int j=0;j<(1<<20);++j) cnt[j]=1e18;
        for(int i=0;i<n;++i)
        {
            mask[i]=0;
            for(int j=0;j<m;++j)
            {
                mask[i] |= (1LL<< col[a[i][j]]);
            }
            cnt[mask[i]]=min(cnt[mask[i]],a[i].back());
        }
        int n1=20;
        for(int i=0;i<n1;++i)
        {
            for(int mask=0;mask<(1<<n1);++mask)
            {
                if(mask & (1<<i))
                {
                    cnt[mask]=min(cnt[mask],cnt[mask-(1<<i)]);
                }
            }
        }
        for(int mask=0;mask<(1<<n1);++mask)
        {
            ans=min(ans,cnt[mask]+cnt[(1<<n1)-1-mask]);
        }
    }
    if(ans==1e18) {cout<<(-1);return 0;}
    cout<<ans;
    return 0;
}