#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=605;
int ans[maxn][maxn];
int is[maxn];
bool used[maxn];
vector <pair<int,int> > a[maxn];
int d[maxn];
int mi1;
int suf[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        a[x].push_back({y,w});
    }
    for(int i=0;i<n;++i)
    {
        is[i]=0;
        for(int j=0;j<n;++j)
        {
            used[j]=0;
            if(j!=i)
            {
                is[j]=1e18;
            }
        }
        for(int k=0;k<n;++k)
        {
            int mi=2e18;
            int z=(-1);
            mi1=1e18;
            for(int l=0;l<n;++l)
            {
                suf[l]=1e18;
                if(!used[l] && is[l]<mi)
                {
                    mi=is[l];
                    z=l;
                }
            }
            used[z]=1;
            for(int l=0;l<n;++l) d[l]=(is[l]-l);
            int t=is[z];
            for(auto h:a[z])
            {
                int s=(h.first+t)%n;int c=h.second;
                suf[s]=min(suf[s],c+t-s);
                mi1=min(mi1,c+t+n-s);
            }
            int curr=mi1;
            for(int l=0;l<n;++l)
            {
                curr=min(curr,suf[l]);
                d[l]=min(d[l],curr);
            }
            for(int l=0;l<n;++l)
            {
                is[l]=min(is[l],d[l]+l);
            }
        }
        for(int j=0;j<n;++j) ans[i][j]=is[j];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}