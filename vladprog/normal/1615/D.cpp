#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int x[N],y[N],v[N];

int par_[2*N];
int * const par=par_+N;

int dsu(int a)
{
    return par[a]==a?a:par[a]=dsu(par[a]);
}

void un(int a,int b)
{
    a=dsu(a);
    b=dsu(b);
    if(a==b)
        return;
    if(rand()&1)
        par[a]=b;
    else
        par[b]=a;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=-n;i<=n;i++)
        par[i]=i;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x[i]>>y[i]>>v[i];
        if(v[i]!=-1)
        {
            int p=__builtin_popcountll(v[i])&1;
            if(p)
                un(x[i],-y[i]),
                un(-x[i],y[i]);
            else
                un(x[i],y[i]),
                un(-x[i],-y[i]);
        }
    }
    while(m--)
    {
        int a,b,p;
        cin>>a>>b>>p;
        if(p)
            un(a,-b),
            un(-a,b);
        else
            un(a,b),
            un(-a,-b);
    }
    for(int i=1;i<=n;i++)
        if(dsu(i)==dsu(-i))
            return (void)(cout<<"NO\n");
    for(int i=2;i<=n;i++)
        if(dsu(i)!=dsu(1)&&dsu(i)!=dsu(-1))
            un(1,i),
            un(-1,-i);
    for(int i=1;i<=n-1;i++)
        if(v[i]==-1)
            v[i]=dsu(x[i])!=dsu(y[i]);
    cout<<"YES\n";
    for(int i=1;i<=n-1;i++)
        cout<<x[i]<<" "<<y[i]<<" "<<v[i]<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}