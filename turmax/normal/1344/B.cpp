#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1000;
pair <int,int> parent[maxn][maxn];
int lp[maxn][maxn];
pair <int,int> glav(pair <int,int> a)
{
    while(true)
    {
        pair <int,int> u=parent[a.first][a.second];
        if(u.first==(-1))
        {
            return a;
        }
        a=u;
    }
}
void merg(pair <int,int> a,pair <int,int> b)
{
    a=glav(a);
    b=glav(b);
    if(a==b)
    {
        return;
    }
    if(lp[a.first][a.second]>=lp[b.first][b.second])
    {
        parent[b.first][b.second]=a;
        lp[a.first][a.second]+=lp[b.first][b.second];
    }
    else
    {
        swap(a,b);
        parent[b.first][b.second]=a;
        lp[a.first][a.second]+=lp[b.first][b.second];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool a[n][m];
    char s;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>s;
            if(s=='#')
            a[i][j]=true;
            else
            a[i][j]=false;
        }
    }
    bool h1=false,h2=false;
    for(int i=0;i<n;++i)
    {
        int s=0;
        int mi=1e18;
        int ma=(-1);
        for(int j=0;j<m;++j)
        {
            if(a[i][j])
            {
                ++s;
                mi=min(mi,j);
                ma=max(ma,j);
            }
        }
        if(s!=0 && s!=(ma-mi+1))
        {
            cout<<(-1);
            return 0;
        }
        if(s==0)
        {
            h1=true;
        }
    }
    for(int i=0;i<m;++i)
    {
        int s=0;
        int mi=1e18;
        int ma=(-1);
        for(int j=0;j<n;++j)
        {
            if(a[j][i])
            {
                ++s;
                mi=min(mi,j);
                ma=max(ma,j);
            }
        }
        if(s!=0 && s!=(ma-mi+1))
        {
            cout<<(-1);
            return 0;
        }
        if(s==0)
        {
            h2=true;
        }
    }
    if(h1 && !h2)
    {
        cout<<(-1);
        return 0;
    }
    if(h2 && !h1)
    {
        cout<<(-1);
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            lp[i][j]=1;
            parent[i][j]={-1,-1};
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int x=i;
            int y=j;
            if(!a[x][y])
            {
                continue;
            }
            if(x<(n-1) && a[x+1][y])
            {
                merg({x,y},{x+1,y});
            }
            if(x>=1 && a[x-1][y])
            {
                merg({x,y},{x-1,y});
            }
            if(y<(m-1) && a[x][y+1])
            {
                merg({x,y},{x,y+1});
            }
            if(y>=1 && a[x][y-1])
            {
                merg({x,y},{x,y-1});
            }
        }
    }
    set <pair<int,int> > h;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            pair <int,int> o=glav({i,j});
            //cout<<o.first<<" "<<o.second<<endl;
            if(a[i][j])
            {
                h.insert(o);
            }
        }
    }
    cout<<h.size()<<endl;
    return 0;
}