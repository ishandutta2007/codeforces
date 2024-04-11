#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
vector <bool> used;
vector <vector<int> > b;
vector <map<int,int> > c;
vector <vector<int> > d;
vector <int> a;
int gcd(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    if(x==0)
    {
        return y;
    }
    if(x>=y)
    {
        return gcd(x%y,y);
    }
    else
    {
        return gcd(y%x,x);
    }
}
void dfs(int pr,int x)
{
    used[x]=true;
    int g=a[x];
    c[x][g]=1;
    d[x].push_back(g);
    int z;
    if(pr!=(-1))
    {
        int o=d[pr].size();
        for(int i=0;i<o;++i)
        {
            z=gcd(d[pr][i],g);
            if(c[x].count(z)==0)
            {
                c[x][z]=c[pr][d[pr][i]];
                d[x].push_back(z);
            }
            else
            {
                c[x][z]+=c[pr][d[pr][i]];
            }
        }
    }
    for(int i=0;i<b[x].size();++i)
    {
        if(!used[b[x][i]])
        {
            dfs(x,b[x][i]);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    a.resize(n);
    b.resize(n);
    int x,y;
    int k;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        a[i]=k;
    }
    for(int i=1;i<n;++i)
    {
        cin>>x>>y;
        x--;
        y--;
        b[x].push_back(y);
        b[y].push_back(x);
    }
    for(int i=0;i<n;++i)
    {
        used.push_back(false);
    }
    c.resize(n);
    d.resize(n);
    dfs(-1,0);
    int sum=0;
    int y1;
    for(int i=0;i<n;++i)
    {
        y1=d[i].size();
        for(int j=0;j<y1;++j)
        {
            sum+=d[i][j]*c[i][d[i][j]];
            sum%=p;
        }
    }
    cout<<sum;
    return 0;
}