#pragma GCC optimize("O3","unroll-loops")
#pragma GCC optimize("avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=2005;
bitset<maxn> a[maxn];
bitset<maxn> b[maxn];
bitset<maxn> res[maxn];
bitset<maxn> d;bitset<maxn> db;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,int> > v;for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;v.push_back({x,y});a[x][y]=1;}
    for(int i=0;i<n;++i) b[i][i]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[i][i]==0 && a[j][i]==1)
            {
                swap(a[i],a[j]);swap(b[i],b[j]);
            }
        }
        for(int j=i+1;j<n;++j)
        {
            if(a[j][i]==1)
            {
                a[j]^=a[i];b[j]^=b[i];
            }
        }
    }
    /*for(int i=0;i<n;++i) {for(int j=0;j<n;++j) {cout<<a[i][j]<<' ';} cout<<endl;}
    for(int i=0;i<n;++i) {for(int j=0;j<n;++j) {cout<<b[i][j]<<' ';} cout<<endl;}*/
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) {d[j]=0;db[j]=0;}
        d[i]=1;db[i]=0;
        while(d.count()!=0)
        {
            for(int j=0;j<n;++j)
            {
                if(d[j])
                {
                    d^=a[j];db^=b[j];
                }
            }
        }
        for(int j=0;j<n;++j)
        {
            res[j][i]=db[j];
        }
    }
    for(auto h:v)
    {
        puts(res[h.first][h.second] ? "NO" : "YES");
    }
    return 0;
}