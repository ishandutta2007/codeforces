#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=5e5+100;

vector<int> g[N];
int s[N],l[N],r[N];

int calc(int v,int p)
{
    int&res=s[v]=1;
    for(int to:g[v])
        if(to!=p)
            res+=calc(to,v);
    return res;
}

void build(int v,int p,int a,int b,int c)
{
    for(int to:g[v])
        if(to!=p)
            build(to,v,b,c-(s[to]*2-1)+1,c),
            b++,c-=s[to]*2-1;
    l[v]=a;
    r[v]=b;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int _=1;_<=n-1;_++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    calc(1,0);
    build(1,0,1,2,2*n);
    for(int i=1;i<=n;i++)
        cout<<l[i]<<" "<<r[i]<<"\n";
}