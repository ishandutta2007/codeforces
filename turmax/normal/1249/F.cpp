#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> b;
vector <vector<int> > a;
vector <vector <int> > d;
vector <bool> used;
vector <int> corn;
int n,k;
void dfs(int x)
{
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        if(!used[a[x][i]])
        {
            corn[a[x][i]]=corn[x]+1;
            dfs(a[x][i]);
        }
    }
    int ma;
    int sum1;
    int sum2;
    for(int i=0;i<=k;++i)
    {
        ma=0;
        sum1=0;
        sum2=0;
        if(a[x].size()==1 && x!=0)
        {
            if(i==0)
            {
                d[x][i]=b[x];
            }
            else
            {
                d[x][i]=0;
            }
        }
        else
        {
            for(int l=max(i-1,0ll);l<=k;++l)
            {
            sum1=0;
            for(int j=0;j<a[x].size();++j)
            {
                if(corn[a[x][j]]>corn[x])
                {
                    sum1+=d[a[x][j]][max(l,k-l-1)];
                }
            }
            ma=max(ma,sum1);
            if(l==k)
            {
                continue;
            }
            for(int j=0;j<a[x].size();++j)
            {
                if(corn[a[x][j]]>corn[x])
                {
                    sum1+=d[a[x][j]][l]-d[a[x][j]][k-l-1];
                    ma=max(ma,sum1);
                    sum1-=d[a[x][j]][l]-d[a[x][j]][k-l-1];
                }
            }
            }
            if(i==0)
            {
                sum2=b[x];
                for(int j=0;j<a[x].size();++j)
                {
                    if(corn[a[x][j]]>corn[x])
                    {
                        sum2+=d[a[x][j]][k];
                    }
                }
            }
            ma=max(ma,sum2);
            d[x][i]=ma;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    b.resize(n);
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        b[i]=x;
    }
    a.resize(n);
    int y;
    for(int i=0;i<(n-1);++i)
    {
        cin>>x>>y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    d.resize(n);
    used.resize(n);
    corn.resize(n);
    corn[0]=0;
    for(int i=0;i<n;++i)
    {
        used[i]=false;
        d[i].resize(k+1);
    }
    dfs(0);
    cout<<d[0][0];
    return 0;
}