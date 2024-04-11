#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=405;
vector<int> a[maxn];
bool used[maxn];int d[maxn][maxn];bitset<maxn> pr[maxn][maxn];bool ok[maxn];
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);
    }
    for(int i=0;i<n;++i)
    {
        fill(used,used+maxn,0);
        fill(d[i],d[i]+maxn,1e9);
        queue<int> q;
        q.push(i);d[i][i]=0;used[i]=1;
        while(!q.empty())
        {
            int x=q.front();q.pop();
            for(int v:a[x])
            {
                if(!used[v])
                {
                    d[i][v]=d[i][x]+1;
                    pr[i][v][x]=1;
                    used[v]=1;
                    q.push(v);
                }
                else if(d[i][v]==d[i][x]+1)
                {
                    pr[i][v][x]=1;
                }
            }
        }
    }
    int res[n][n];
    for(int s=0;s<n;++s)
    {
        for(int t=0;t<=s;++t)
        {
            int d1=d[s][t];
            fill(ok,ok+maxn,1);
            int sum=0;
            for(int k=0;k<n;++k)
            {
                if(d[s][k]+d[k][t]==d1)
                {
                    ok[k]=0;++sum;
                }
            }
            if(sum!=(d1+1))
            {
                res[s][t]=0;res[t][s]=0;continue;
            }
            int res1=1;
            for(int k=0;k<n;++k)
            {
                if(ok[k])
                {
                    int o=(pr[s][k] & pr[t][k]).count();
                    res1*=o;res1%=p;
                }
            }
            res[s][t]=res1;res[t][s]=res1;continue;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}