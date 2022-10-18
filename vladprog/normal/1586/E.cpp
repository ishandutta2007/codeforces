#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

vector<int> g[N];
int par[N],dep[N];

void dfs(int v,int p,int d)
{
    par[v]=p;
    dep[v]=d;
    for(int to:g[v])
        if(!par[to])
            dfs(to,v,d+1);
}

int a[N],b[N];
int cnt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1,0);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>a[i]>>b[i];
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    int odd=0;
    for(int i=1;i<=n;i++)
        if(cnt[i]%2)
            odd++;
    if(odd)
        cout<<"NO\n"<<odd/2,
        exit(0);
    cout<<"YES\n";
    for(int i=1;i<=q;i++)
    {
        vector<int> A{a[i]},B{b[i]};
        while(A.back()!=B.back())
            if(dep[A.back()]>dep[B.back()])
                A.push_back(par[A.back()]);
            else
                B.push_back(par[B.back()]);
        A.pop_back();
        reverse(B.begin(),B.end());
        cout<<A.size()+B.size()<<"\n";
        for(int x:A)
            cout<<x<<" ";
        for(int x:B)
            cout<<x<<" ";
        cout<<"\n";
    }
}