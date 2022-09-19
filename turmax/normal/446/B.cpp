#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    int a[n][m];
    int b[n]={0};
    int c[m]={0};
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {cin>>a[i][j];b[i]+=a[i][j];c[j]+=a[i][j];}
    set <pair<int,int> > d;
    int v1[k+1];
    for(int i=0;i<n;++i) {d.insert({-b[i],i});}
    set <pair<int,int> > h;
    int v2[k+1];
    for(int i=0;i<m;++i) h.insert({-c[i],i});
    int curr1=0;
    v1[0]=0;
    for(int i=0;i<k;++i)
    {
        pair <int,int> o=(*d.begin());
        d.erase(d.begin());
        curr1+=(-o.first);
        o.first+=(m*p);
        d.insert(o);
        v1[i+1]=curr1;
    }
    int curr2=0;
    v2[0]=0;
    for(int i=0;i<k;++i)
    {
        pair <int,int> o=(*h.begin());
        h.erase(h.begin());
        curr2+=(-o.first);
        o.first+=(n*p);
        h.insert(o);
        v2[i+1]=curr2;
    }
    int ans=(-1e18);
    for(int i=0;i<=k;++i)
    {
        ans=max(ans,v1[i]+v2[k-i]-i*(k-i)*p);
    }
    cout<<ans;
    return 0;
}