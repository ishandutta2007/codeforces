#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

#define mp make_pair

const int N=2e5+100;

int k;
vector<int> g[N];
int c[N];
vector<int> d;

pii farest(int v,int p1=0,int p2=0)
{
    pii ans(0,v);
    for(int to:g[v])
        if(to!=p1&&to!=p2)
            ans=max(ans,farest(to,v));
    ans.x++;
    return ans;
}

void col(int v,int add)
{
    int cur=(c[v]+add+k-1)%k+1;
    for(int to:g[v])
        if(!c[to])
            c[to]=cur,
            col(to,add);
}

bool diam(int v,int p,int dest)
{
    if(v==dest)
        return d.push_back(v),true;
    for(int to:g[v])
        if(to!=p&&diam(to,v,dest))
            return d.push_back(v),true;
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(k==2)
    {
        c[1]=1;
        col(1,+1);
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)
            cout<<c[i]<<" ";
        exit(0);
    }
    int v1=farest(1).y;
    int v2=farest(v1).y;
    diam(v2,0,v1);
    int len=d.size();
    for(int i=0;i<len;i++)
        c[d[i]]=i%k+1;
    for(int i=0;i<len;i++)
    {
        int h=farest(d[i],(i>0?d[i-1]:0),(i<len-1?d[i+1]:0)).x;
        if(h==1)
            continue;
        int l=i+h;
        int r=len-i-1+h;
        if(l>=k&&r>=k)
            cout<<"No",exit(0);
        if(l<k)
            col(d[i],-1);
        else
            col(d[i],+1);
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
        cout<<c[i]<<" ";
}