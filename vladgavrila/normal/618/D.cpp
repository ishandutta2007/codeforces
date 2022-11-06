#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define maxn 200010
#define inf (1LL*1000000000*1000000000)

int n, x, y, p, m;
int f[maxn];
long long d[maxn][2];
vector<int> v[maxn];

void df(int nod)
{
    if(f[nod])
        return;

    f[nod]=1;

    long long s1=0, b1=inf, b2=inf, nfii=0;
    int fiu;

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu = v[nod][i];
        if(f[fiu])
            continue;
        ++nfii;

        df(fiu);

        s1=s1+d[fiu][1];

        if(d[fiu][0]-d[fiu][1]<b1)
        {
            b2=b1;
            b1=d[fiu][0]-d[fiu][1];
        }
        else
        if(d[fiu][0]-d[fiu][1]<b2)
            b2=d[fiu][0]-d[fiu][1];
    }

    if(nfii==0)
        d[nod][0]=d[nod][1]=0;
    else
    {
        d[nod][0]=s1+b1+nfii-1;
        d[nod][1]=min(d[nod][0], s1+b1+b2+nfii-2);
    }
}

void dfm(int nod);

void dfp(int nod)
{
    if(f[nod])
        return;
    f[nod]=1;

    ++p;

    for(int i=0; i<v[nod].size(); ++i)
        if(f[v[nod][i]]==0)
            dfm(v[nod][i]);
}

void dfm(int nod)
{
    if(f[nod])
        return;
    f[nod]=1;

    ++m;

    for(int i=0; i<v[nod].size(); ++i)
        if(f[v[nod][i]]==0)
            dfp(v[nod][i]);
}

int main()
{
    cout.sync_with_stdio(false);
    cin>>n>>x>>y;

    for(int i=1; i<n; ++i)
    {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    if(x==y)
    {
        cout<<1LL*(n-1)*x<<"\n";
        return 0;
    }

    if(x<y)
    {
        df(1);
        cout<<1LL*(n-1)*x+d[1][1]*(y-x)<<"\n";
        return 0;
    }

    dfm(1);

    if(p==1 || m==1)
        cout<<1LL*(n-2)*y+x<<"\n";
    else
        cout<<1LL*(n-1)*y<<"\n";

    return 0;
}