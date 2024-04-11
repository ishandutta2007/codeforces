#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll a[100005],b[100005];
int cnt[66],g[205][205],dis[205][205];
int n;
void floyd()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(g[i][j]) dis[i][j]=1;
            else dis[i][j]=1e9;
        }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int tot=0;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) if(a[i]) b[++tot]=a[i];
    if(tot<3) return cout<<-1<<endl,0;
    swap(a,b);n=tot;
    for(int i=1;i<=n;++i)
        for(int j=0;j<61;++j)
        {
            if(a[i] & (1ll<<j)) cnt[j]++;
            if(cnt[j] >= 3) return cout<<3<<endl,0;
        }
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(a[i] & a[j])
                g[i][j]=g[j][i]=1;
    int ans=1e9;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
        {
            if(g[i][j])
            {
                g[i][j]=g[j][i]=0;
                floyd();
                ans=min(ans,dis[i][j]+1);
            }
        }
    if(ans>n) cout<<-1<<endl;
    else cout<<ans<<endl;
}