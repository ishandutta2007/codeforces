#include <bits/stdc++.h>

using namespace std;
#define int long long
int parent[4]={-1,-1,-1,-1};
int sum1[4]={0};
int get(int x)
{
    if(parent[x]==(-1)) return x;
    int ans=get(parent[x]);
    parent[x]=ans;
    return ans;
}
void merg(int x,int y)
{
    x=get(x);y=get(y);
    if(x==y) return;
    sum1[y]+=sum1[x];
    parent[x]=y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int deq[4];
    int cnt[4][4];
    for(int i=0;i<4;++i) for(int j=0;j<4;++j) cnt[i][j]=0;
    for(int i=0;i<4;++i) deq[i]=0;
    vector <pair<int,pair<int,int> > > a(n);
    int sum=0;
    for(int i=0;i<n;++i)
    {
        int z1,x,z2;
        cin>>z1>>x>>z2;
        sum+=x;
        z1--;z2--;
        merg(z1,z2);
        cnt[z1][z2]++;
        sum1[get(z1)]+=x;
        a[i]={x,{z1,z2}};
        deq[z1]^=1;deq[z2]^=1;
    }
    set <int> o;
    for(int i=0;i<4;++i) o.insert(get(i));
    if(o.size()>=2)
    {
        int ans=0;
        for(auto h:o) ans=max(ans,sum1[h]);
        cout<<ans;
        return 0;
    }
    int ans=0;
    int ok[4];
    for(int i=0;i<4;++i) ok[i]=0;
    int h=0;for(int i=0;i<4;++i) if(ok[i]!=deq[i]) ++h;
    if(h<=2) ans=max(ans,sum);
    for(int i=0;i<n;++i)
    {
        ok[a[i].second.first]^=1;ok[a[i].second.second]^=1;
        cnt[a[i].second.first][a[i].second.second]--;
        if(!cnt[a[i].second.first][a[i].second.second])
        {
            for(int k=0;k<4;++k) parent[k]=(-1);
            for(int i=0;i<4;++i) for(int j=0;j<4;++j) if(cnt[i][j]) merg(i,j);
            set <int> o;
            for(int i=0;i<4;++i) o.insert(get(i));
            if(o.size()!=1) continue;
        }
        int h=0;for(int i=0;i<4;++i) if(ok[i]!=deq[i]) ++h;
        if(h<=2) ans=max(ans,sum-a[i].first);
        cnt[a[i].second.first][a[i].second.second]--;
        ok[a[i].second.first]^=1;ok[a[i].second.second]^=1;
    }
    cout<<ans;
    return 0;
}