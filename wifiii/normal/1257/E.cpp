#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int c[200005];
int a[4][200005],b[4][200005];
int aa[200005],bb[200005];
int main()
{
    int k1,k2,k3;
    cin>>k1>>k2>>k3;
    for(int i=1;i<=k1;++i)
    {
        int t;
        cin>>t;
        c[t]=1;
    }
    for(int i=1;i<=k2;++i)
    {
        int t;
        cin>>t;
        c[t]=2;
    }
    for(int i=1;i<=k3;++i)
    {
        int t;
        cin>>t;
        c[t]=3;
    }
    int n = k1+k2+k3;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=3;++j) a[j][i]=a[j][i-1];
        a[c[i]][i]=a[c[i]][i-1]+1;
    }
    for(int i=n;i>=1;--i)
    {
        for(int j=1;j<=3;++j) b[j][i]=b[j][i+1];
        b[c[i]][i]=b[c[i]][i+1]+1;
    }
    for(int i=0;i<=n+1;++i) aa[i]=a[2][i]-a[1][i],bb[i]=b[2][i]-b[3][i];
//    ii cout<<aa[i]<<" ";cout<<endl;
//    ii cout<<bb[i]<<" ";cout<<endl;
    for(int i=n;i>=0;--i) bb[i]=min(bb[i],bb[i+1]);
//    ii cout<<bb[i]<<" ";cout<<endl;
    int ans=1e9;
    for(int i=0;i<=n+1;++i) ans=min(ans,aa[i]+bb[i]);
    cout<<ans+n-k2<<endl;
}