#include <bits/stdc++.h>

using namespace std;
int used[300005];
int r[300005];
vector <vector<int> > a(300005);
int ensum;
int odsum;
void dfs(int x)
{
    used[x]=true;
    if(r[x]%2==0)
    {
        odsum++;
    }
    else
    {
        ensum++;
    }
    for(int i=0;i<a[x].size();++i)
    {
        if(used[a[x][i]]==false)
        {
            r[a[x][i]]=r[x]+1;
            dfs(a[x][i]);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n,m;
    int x,y;
    vector <int> res;
    for(int i=0;i<t;++i)
    {
        vector <int> v;
        for(int i=0;i<n;++i)
        {
            a[i]=v;
        }
        res.clear();
        cin>>n>>m;
        for(int j=0;j<n;++j)
        {
            used[j]=false;
        }
        for(int j=0;j<m;++j)
        {
            cin>>x>>y;
            x--;
            y--;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        r[0]=0;
        used[0]=true;
        ensum=0;
        odsum=0;
        dfs(0);
        if(ensum>=odsum)
        {
            for(int j=0;j<n;++j)
            {
                if(r[j]%2==0)
                {
                    res.push_back(j);
                }
            }
        }
        else
        {
            for(int j=0;j<n;++j)
            {
                if(r[j]%2==1)
                {
                    res.push_back(j);
                }
            }
        }
        cout<<res.size()<<endl;
        for(int j=0;j<res.size();++j)
        {
            cout<<res[j]+1<<" ";
        }
        cout<<""<<endl;
    }
    return 0;
}