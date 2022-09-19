#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=1005;const int maxm=1005;
int is[maxn][maxm];
bool used[maxn][maxm];
int a[maxn][maxm];
bool z[maxn][maxm];
deque <pair<int,int> > v;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;++j)
        {
            if(s[j]=='0')
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
             pair <int,int> curr=make_pair(i,j);
             if(((i-1)>=0 && a[i][j]==a[i-1][j]) || (((j-1)>=0 && a[i][j]==a[i][j-1])) || ((i+1)<n && a[i][j]==a[i+1][j]) || ((j+1)<m && a[i][j]==a[i][j+1]))
             {
                 z[i][j]=true;
                 v.push_back(curr);
             }
             else
             {
                 z[i][j]=false;
             }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(!z[i][j])
            {
            used[i][j]=false;
            is[i][j]=1e9;
            }
            else
            {
                used[i][j]=true;
                is[i][j]=0;
            }
        }
    }
    while(!v.empty())
    {
        deque <pair<int,int> > v1;
        while(!v.empty())
        {
            pair <int,int> curr=v.front();
            v.pop_front();
            int x=curr.first;int y=curr.second;
            if((x+1)<n && !used[x+1][y])
            {
                used[x+1][y]=true;
                is[x+1][y]=is[x][y]+1;
                v1.push_back({x+1,y});
            }
            if((x-1)>=0 && !used[x-1][y])
            {
                used[x-1][y]=true;
                is[x-1][y]=is[x][y]+1;
                v1.push_back({x-1,y});
            }
            if((y+1)<m && !used[x][y+1])
            {
                used[x][y+1]=true;
                is[x][y+1]=is[x][y]+1;
                v1.push_back({x,y+1});
            }
            if((y-1)>=0 && !used[x][y-1])
            {
                used[x][y-1]=true;
                is[x][y-1]=is[x][y]+1;
                v1.push_back({x,y-1});
            }
        }
        v=v1;
    }
    while(t--)
    {
        int x,y,u;
        cin>>x>>y>>u;
        x--;y--;
        //cout<<is[x][y]<<" is "<<endl;
        if(!used[x][y])
        {
            cout<<a[x][y]<<endl;
            continue;
        }
        int o=is[x][y];
        if(u<=o)
        {
            cout<<a[x][y]<<endl;
            continue;
        }
        else
        {
            if((u-o)%2==0)
            {
                cout<<a[x][y]<<endl;
            }
            else
            {
                cout<<(a[x][y]+1)%2<<endl;
            }
        }
    }
    return 0;
}