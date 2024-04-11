#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=51;
pair <int,int> parent[51][51];
int lp[51][51];
pair <int,int> glav(pair <int,int> a)
{
    while(true)
    {
        if(parent[a.first][a.second]==(pair<int,int>) make_pair(-1,-1))
        {
            return a;
        }
        a=parent[a.first][a.second];
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
        lp[a.first][a.second]+=lp[b.first][b.second];
        parent[b.first][b.second]=a;
    }
    else
    {
        swap(a,b);
        lp[a.first][a.second]+=lp[b.first][b.second];
        parent[b.first][b.second]=a;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<maxn;++i)
            for(int j=0;j<maxn;++j)
            {
                parent[i][j]={-1,-1};
                lp[i][j]=1;
            }
        int n,m;
        cin>>n>>m;
        vector <pair<int,int> > b;
        bool a[n][m];
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) a[i][j]=true;
        for(int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;++j)
            {
                if(s[j]=='#')
                {
                    a[i][j]=false;
                }
                if(s[j]=='G')
                {
                    b.push_back({i,j});
                }
                if(s[j]=='B')
                {
                    a[i][j]=false;
                    if(i>=1)
                    {
                        a[i-1][j]=false;
                    }
                    if(j>=1)
                    {
                        a[i][j-1]=false;
                    }
                    if(i<(n-1))
                    {
                        a[i+1][j]=false;
                    }
                    if(j<(m-1))
                    {
                        a[i][j+1]=false;
                    }
                }
            }
        }
        pair <int,int> parent[n][m];
        int lp[n][m];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(a[i][j] && i>=1 && a[i-1][j])
                {
                    merg({i-1,j},{i,j});
                }
                if(a[i][j] && j>=1 && a[i][j-1])
                {
                    merg({i,j-1},{i,j});
                }
                if(a[i][j] && i<(n-1) && a[i+1][j])
                {
                    merg({i+1,j},{i,j});
                }
                if(a[i][j] && j<(m-1) && a[i][j+1])
                {
                    merg({i,j+1},{i,j});
                }
            }
        }
        pair <int,int> x=glav({n-1,m-1});
        bool h=true;
        for(int i=0;i<b.size();++i)
        {
            if(x!=glav(b[i]))
            {
                h=false;
                break;
            }
        }
        if(h)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}