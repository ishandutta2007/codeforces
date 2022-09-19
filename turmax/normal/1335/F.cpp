#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.size();++j)
        {
            a[i][j]=s[j]-'0';
        }
    }
    pair <int,int> b[n][m];
    vector <pair<int,int> > pot[n][m];
    int deq[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            char s;
            cin>>s;
            if(s=='U')
            {
                b[i][j]={i-1,j};
            }
            else if(s=='D')
            {
                b[i][j]={i+1,j};
            }
            else if(s=='L')
            {
                b[i][j]={i,j-1};
            }
            else
            {
                b[i][j]={i,j+1};
            }
            pot[b[i][j].first][b[i][j].second].push_back({i,j});
        }
    }
    bool used1[n][m];
    set <pair<int,pair<int,int> > > o;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            used1[i][j]=false;
            deq[i][j]=pot[i][j].size();
            o.insert({deq[i][j],{i,j}});
        }
    }
    while(!o.empty())
    {
        pair <int,pair<int,int> > u=(*o.begin());
        //cout<<u.second.first<<" "<<u.second.second<<" pairerase "<<endl;
        if(u.first>=1)
        {
            break;
        }
        used1[u.second.first][u.second.second]=true;
        o.erase(o.begin());
        pair <int,int> z=b[u.second.first][u.second.second];
        //cout<<z.first<<" "<<z.second<<" goto "<<endl;
        if(used1[z.first][z.second])
        {
            //cout<<" BAN "<<endl;
            continue;
        }
        o.erase({deq[z.first][z.second],z});
        deq[z.first][z.second]--;
        o.insert({deq[z.first][z.second],z});
    }
    bool used[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            used[i][j]=false;
        }
    }
    int is[n][m];
    int sum=0;
    int sum2=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(!used1[i][j] && !used[i][j])
            {
                //cout<<i<<" "<<j<<endl;
                deque <pair<int,int> > q;
                vector <pair<int,int> > h;
                q.push_back({i,j});
                is[i][j]=0;
                int sz=0;
                while(!q.empty())
                {
                    //cout<<" rfd "<<endl;
                    deque <pair<int,int> > q1;
                    q1.clear();
                    while(!q.empty())
                    {
                        pair <int,int> o=q.front();
                        used[o.first][o.second]=true;
                        //cout<<o.first<<" "<<o.second<<endl;
                        q.pop_front();
                        h.push_back(o);
                        for(int i=0;i<pot[o.first][o.second].size();++i)
                        {
                            pair <int,int> z=pot[o.first][o.second][i];
                            if(!used[z.first][z.second])
                            {
                                is[z.first][z.second]=is[o.first][o.second]+1;
                                q1.push_back(z);
                                used[z.first][z.second]=true;
                            }
                            else
                            {
                                sz=is[o.first][o.second]+1;
                            }
                        }
                    }
                    q=q1;
                }
                //cout<<sz<<" sz "<<endl;
                int ans[sz];
                for(int i=0;i<sz;++i)
                {
                    ans[i]=1;
                }
                for(int i=0;i<h.size();++i)
                {
                    pair <int,int> o=h[i];
                    ans[is[o.first][o.second]%sz]=min(ans[is[o.first][o.second]%sz],a[o.first][o.second]);
                }
                sum+=sz;
                for(int i=0;i<sz;++i)
                {
                    sum2+=(1-ans[i]);
                }
            }
        }
    }
    cout<<sum<<" "<<sum2<<endl;
    }
    return 0;
}