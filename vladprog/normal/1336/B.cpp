#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int ans;

void calc(int x,int y,int z)
{
    int val=(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
    ans=min(ans,val);
}

void _solve(int*r,int*g,int*b,int nr,int ng,int nb)
{
    for(int i=1;i<=nr;i++)
    {
        int j=lower_bound(g+1,g+ng+1,r[i])-g;
        if(j==ng+1)
            continue;
        int k=lower_bound(b+1,b+nb+1,g[j])-b;
        if(k==nb+1)
            continue;
        j=lower_bound(g+1,g+ng+1,(r[i]+b[k])/2)-g;
        if(j!=ng+1)
            calc(r[i],g[j],b[k]);
        j=prev(upper_bound(g+1,g+ng+1,(r[i]+b[k])/2))-g;
        if(j!=0)
            calc(r[i],g[j],b[k]);
    }
}
#define solve(r,g,b) _solve(r,g,b,n##r,n##g,n##b)

int r[N],g[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int nr,ng,nb;
        cin>>nr>>ng>>nb;
        for(int i=1;i<=nr;i++)
            cin>>r[i];
        for(int i=1;i<=ng;i++)
            cin>>g[i];
        for(int i=1;i<=nb;i++)
            cin>>b[i];
        sort(r+1,r+nr+1);
        sort(g+1,g+ng+1);
        sort(b+1,b+nb+1);
        ans=8e18;
        solve(r,g,b);
        solve(r,b,g);
        solve(g,r,b);
        solve(g,b,r);
        solve(b,r,g);
        solve(b,g,r);
        cout<<ans<<"\n";
    }
}