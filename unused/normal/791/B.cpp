#include <bits/stdc++.h>
using namespace std;

int p[150005],c[150005],d[150005],r[150005];

int f(int t)
{
    return t==p[t]?t:p[t]=f(p[t]);
}

void g(int a, int b)
{
    a=f(a);b=f(b);
    if(a==b)return;
    if(r[a]<r[b])swap(a,b);
    if(r[a]==r[b])++r[a];
    p[b]=a;
}

int x[150005],y[150005];

int main()
{
    cin.sync_with_stdio(false);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++)p[i]=i;
    for (int i=0;i<m;i++)
    {
        cin>>x[i]>>y[i];
        g(x[i],y[i]);
    }
    for (int i=1;i<=n;i++)c[f(i)]++;
    for (int i=0;i<m;i++)d[f(x[i])]++;
    for (int i=1;i<=n;i++)
    {
        if(f(i)!=i)continue;
        if(c[i]*1ll*(c[i]-1)/2!=d[i])
        {
            cout<<"NO\n";return 0;
        }
    }
    cout<<"YES\n";
}