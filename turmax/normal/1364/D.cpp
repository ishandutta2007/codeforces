#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector <int> a[maxn];
vector <int> b[maxn];
bool used[maxn];
int corn[maxn];
int pr[maxn];
vector <int> v1;
vector <int> v2;
int k;
void dfs(int x)
{
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        //cout<<v<<" v "<<endl;
        if(!used[v])
        {
            corn[v]=corn[x]+1;
            pr[v]=x;
            dfs(v);
        }
        else
        {
            if(corn[v]>=(corn[x]-k+1) && corn[v]<corn[x] && v!=pr[x])
            {
                //cout<<x<<" "<<v<<" x v "<<endl;
                cout<<2<<endl;
                vector <int> h;
                int u=x;
                while(u!=v)
                {
                    h.push_back(u);
                    //cout<<u<<" u "<<endl;
                    u=pr[u];
                }
                h.push_back(v);
                cout<<h.size()<<endl;
                for(int i=0;i<h.size();++i)
                {
                    cout<<h[i]+1<<' ';
                }
                exit(0);
            }
        }
    }
    if(corn[x]<k)
    {
        if(corn[x]%2==0)
        {
            v1.push_back(x);
        }
        else
        {
            v2.push_back(x);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        b[x].push_back(i);b[y].push_back(i);
    }
    corn[0]=0;
    dfs(0);
    if(v1.size()>=(k+1)/2)
    {
        cout<<1<<endl;
        for(int i=0;i<(k+1)/2;++i)
        {
            cout<<v1[i]+1<<' ';
        }
        return 0;
    }
    else
    {
        cout<<1<<endl;
        for(int i=0;i<(k+1)/2;++i)
        {
            cout<<v2[i]+1<<' ';
        }
        return 0;
    }
    return 0;
}