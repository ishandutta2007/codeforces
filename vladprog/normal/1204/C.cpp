#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int INF=1e9,N=110;

int dist[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        s="_"+s;
        for(int j=1;j<=n;j++)
            if(i!=j)
                dist[i][j]=(s[j]=='1'?1:INF);
    }
    for(int j=1;j<=n;j++)
        for(int i=1;i<=n;i++)
            for(int k=1;k<=n;k++)
                dist[i][k]=min(dist[i][k],dist[i][j]+dist[j][k]);
    int m;
    cin>>m;
    vector<int> v;
    int p;
    cin>>p;
    v.push_back(p);
    int t=0;
    for(int i=2;i<=m;i++)
    {
        int x;
        cin>>x;
        t++;
        if(t>dist[v.back()][x])
        {
            v.push_back(p);
            t=1;
        }
        p=x;
    }
    v.push_back(p);
    cout<<v.size()<<"\n";
    for(int x:v)
        cout<<x<<" ";
}