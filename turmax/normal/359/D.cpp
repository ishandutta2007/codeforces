#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
int b[maxn][20];
int c[maxn][20];
int a[maxn];
int getb(int l,int r)
{
    if(r==(l+1))
    {
        return b[l][0];
    }
    for(int i=0;i<20;++i)
    {
        if((l+(1<<i))>=r)
        {
            return min(b[l][i-1],b[r-(1<<(i-1))][i-1]);
        }
    }
}
int getc(int l,int r)
{
    if(r==(l+1))
    {
        return c[l][0];
    }
    for(int i=0;i<20;++i)
    {
        if((l+(1<<i))>=r)
        {
            return __gcd(c[l][i-1],c[r-(1<<(i-1))][i-1]);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<maxn;++i)
    {
        b[i][0]=a[i];
        c[i][0]=a[i];
    }
    for(int j=1;j<20;++j)
    {
        for(int i=0;i<maxn-(1<<(j-1));++i)
        {
            b[i][j]=min(b[i][j-1],b[i+(1<<j-1)][j-1]);
            c[i][j]=__gcd(c[i][j-1],c[i+(1<<j-1)][j-1]);
        }
    }
    int low=1;
    int up=(n+1);
    while(true)
    {
        int k=(low+up)/2;
        vector <int> v;
        for(int i=0;i<=(n-k);++i)
        {
            if(getb(i,i+k)==getc(i,i+k))
            {
                v.push_back(i);
            }
        }
        if(!v.empty())
        {
            low=k;
            //cout<<k<<" k "<<endl;
            if((up-low)==1)
            {
                cout<<v.size()<<" "<<low-1<<endl;
                for(int i=0;i<v.size();++i)
                {
                    cout<<v[i]+1<<" ";
                }
                return 0;
            }
        }
        else
        {
            up=k;
        }
    }
    return 0;
}