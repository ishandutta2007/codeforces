#include <bits/stdc++.h>

using namespace std;
#define int long long
bool valid(pair <int,int> u,int n)
{
    return u.first<n && u.first>=0 && u.second<n && u.second>=0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> a[n][n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j].first>>a[i][j].second;
            if(a[i][j].first!=(-1))
            a[i][j].first--;
            if(a[i][j].second!=(-1))
            a[i][j].second--;
        }
    }
    char res[n][n];
    bool used[n][n];
    bool ans=true;
    deque <pair<int,int> > h;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            used[i][j]=false;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j].first==i && a[i][j].second==j)
            {
                h.push_back(a[i][j]);
                used[i][j]=true;
                res[i][j]='X';
            }
        }
    }
    while(!h.empty())
    {
        deque <pair<int,int> > h1;
        while(!h.empty())
        {
            pair <int,int> u=h.front();
            pair <int,int> z=a[u.first][u.second];
            //cout<<u.first<<" "<<u.second<<" this is "<<endl;
            h.pop_front();
            u.first--;
            if(valid(u,n) && !used[u.first][u.second] && a[u.first][u.second]==z)
            {
                h1.push_back(u);
                res[u.first][u.second]='D';
                used[u.first][u.second]=true;
            }
            u.first++;
            u.first++;
            if(valid(u,n) && !used[u.first][u.second] && a[u.first][u.second]==z)
            {
                h1.push_back(u);
                res[u.first][u.second]='U';
                used[u.first][u.second]=true;
            }
            u.first--;
            u.second--;
            if(valid(u,n) && !used[u.first][u.second] && a[u.first][u.second]==z)
            {
                h1.push_back(u);
                res[u.first][u.second]='R';
                used[u.first][u.second]=true;
            }
            u.second++;
            u.second++;
            if(valid(u,n) && !used[u.first][u.second] && a[u.first][u.second]==z)
            {
                h1.push_back(u);
                res[u.first][u.second]='L';
                used[u.first][u.second]=true;
            }
            u.second--;
        }
        h=h1;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j].first==(-1))
            {
                //cout<<i<<" "<<j<<" now "<<endl;
                if(i>=1 && a[i-1][j].first==(-1))
                {
                    used[i][j]=true;
                    res[i][j]='U';
                }
                else if(i<(n-1) && a[i+1][j].first==(-1))
                {
                    used[i][j]=true;
                    res[i][j]='D';
                }
                else if(j>=1 && a[i][j-1].first==(-1))
                {
                    used[i][j]=true;
                    res[i][j]='L';
                }
                else if(j<=(n-1) && a[i][j+1].first==(-1))
                {
                    used[i][j]=true;
                    res[i][j]='R';
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            ans=(ans && used[i][j]);
        }
    }
    if(!ans)
    {
        cout<<"INVALID";
        return 0;
    }
    else
    {
        cout<<"VALID"<<endl;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cout<<res[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}