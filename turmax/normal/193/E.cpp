#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int mod=1e13;
int mul(int x,int y)
{
    __int128 o=x;o*=y;
    return (o%mod);
}
int ans=1e18;
int d;
int a[2][2];
int b[2][2];
int c[2][2];
int b2[2][2];
void po(int x)
{
    if(x==1) {for(int i=0;i<2;++i) for(int j=0;j<2;++j) b[i][j]=a[i][j]; return;}
    if(x%2==0) {
        po(x/2);
        for(int i=0;i<2;++i) for(int j=0;j<2;++j) c[i][j]=0;
        for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) {c[i][k]+=mul(b[i][j],b[j][k]);c[i][k]%=mod;}
        for(int i=0;i<2;++i) for(int j=0;j<2;++j) b[i][j]=c[i][j];
        return;
    }
    else
    {
        po(x-1);
        for(int i=0;i<2;++i) for(int j=0;j<2;++j) c[i][j]=0;
        for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) {c[i][k]+=mul(b[i][j],a[j][k]);c[i][k]%=mod;}
        for(int i=0;i<2;++i) for(int j=0;j<2;++j) b[i][j]=c[i][j];
        return;
    }
}
int f(int x)
{
    if(x==0) return 0;
    if(x==1) return 1;
    --x;
    a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=0;
    po(x);
    return b[0][0];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>d;
    if(d==0) {cout<<0;return 0;} if(d==1) {cout<<1;return 0;}
    int cnt=15e7;int mod1=1e8;
    a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=0;po(cnt);for(int i=0;i<2;++i) for(int j=0;j<2;++j) b2[i][j]=b[i][j];
    int d1=(d%mod1);
    set <pair<int,int> > o;
    //int x1=0,y1=1;for(int i=0;i<2000;++i) {x1+=y1;x1%=mod;swap(x1,y1);}
    //cout<<y1<<endl;
    int x=0,y=1;o.insert({0,1});
    int ans1=0;
    for(int i=2;i<cnt;++i)
    {
        x+=y;if(x>=mod1) x-=mod1;swap(x,y);
        if(y==d1)
        {
            a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=0;po(i);
            for(int j=i;j<15e12+cnt;j+=cnt)
            {
                if(b[0][1]==d) {ans=min(ans,j);}
                for(int i=0;i<2;++i) for(int j=0;j<2;++j) c[i][j]=0;
                for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) {c[i][k]+=mul(b[i][j],b2[j][k]);c[i][k]%=mod;}
                for(int i=0;i<2;++i) for(int j=0;j<2;++j) b[i][j]=c[i][j];
            }
        }
    }
    if(ans==1e18) cout<<(-1);
    else cout<<ans;
    return 0;
}