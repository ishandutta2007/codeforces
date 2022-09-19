#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <pair<int,int> > u[81][81];
int e[81];
int n;
int go(vector <int> g)
{
    g.push_back(0);
    int x,y;
    int ans=0;
    for(int i=0;i<g.size()-1;++i)
    {
        x=g[i];
        y=g[i+1];
        bool f=false;
        for(auto z:u[x][y])
        {
            if(!e[z.second])
            {
                f=true;
                ans+=z.first;
                break;
            }
        }
        if(!f)
        {
            ans+=1e12;
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;
    cin>>n>>k;
    vector <vector <int> > a(n);
    vector <int> v(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>v[j];
            if(i==j)
            {
                v[j]=1e15;
            }
        }
        a[i]=v;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) {
            for (int k = 0; k < n; ++k) {
                if(k!=i && k!=j)
                    u[i][j].push_back({a[i][k] + a[k][j],k});
            }
            sort(u[i][j].begin(),u[i][j].end());
        }
    }
    int x=(k/2-1);
    int ans=1e18;
    {
        vector <int> g;
        g.push_back(0);
        e[0]++;
        if(x!=0)
        {
            for(int i=0;i<n;++i)
            {
                e[i]++;
                g.push_back(i);
                if(x!=1)
                {
                    for(int j=0;j<n;++j)
                    {
                        e[j]++;
                        g.push_back(j);
                        if(x!=2)
                        {
                            for(int t=0;t<n;++t)
                            {
                                e[t]++;
                                g.push_back(t);
                                if(x!=3) {
                                    for (int d = 0; d < n; ++d) {
                                        e[d]++;
                                        g.push_back(d);
                                        //int r=ans;
                                        if (x == 4) {
                                            int x1,y;
                                            int s=0;
                                            g.push_back(0);
                                            for(int i=0;i<g.size()-1;++i)
                                            {
                                                x1=g[i];
                                                y=g[i+1];
                                                bool f=false;
                                                for(auto z:u[x1][y])
                                                {
                                                    if(!e[z.second])
                                                    {
                                                        f=true;
                                                        s+=z.first;
                                                        break;
                                                    }
                                                }
                                                if(!f) {
                                                    s += 1e12;
                                                }
                                            }
                                            ans=min(ans,s);
                                            g.erase(g.begin()+g.size()-1);
                                        }
                                        /*if(ans<r)
                                        {
                                            for(int i=0;i<g.size();++i)
                                            {
                                                cout<<g[i]<<" ";
                                            }
                                            cout<<endl;
                                        }*/
                                        g.erase(g.begin() + g.size() - 1);
                                        e[d]--;
                                    }
                                }
                                if(x==3)
                                {
                                    int r=ans;
                                    ans=min(ans,go(g));
                                }
                                g.erase(g.begin()+g.size()-1);
                                e[t]--;
                            }
                        }
                        if(x==2)
                        {
                            ans=min(ans,go(g));
                        }
                        g.erase(g.begin()+g.size()-1);
                        e[j]--;
                    }
                }
                if(x==1)
                {
                    ans=min(ans,go(g));
                }
                g.erase(g.begin()+g.size()-1);
                e[i]--;
            }
        }
        if(x==0)
        {
            ans=min(ans,go(g));
        }
        g.erase(g.begin()+g.size()-1);
        e[0]--;
    }
    cout<<ans;
    return 0;
}