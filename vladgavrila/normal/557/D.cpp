#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#define maxn 100010

int n, m, cs[maxn], c[2], f[maxn], cl[maxn];
vector<int> v[maxn];
long long sol;

int df(int nod, int cc)
{
    if(f[nod])
    {
        if(cl[nod]!=cc)
        {
            printf("0 1\n");
            exit(0);
        }
        return 0;
    }

    int rez=1;

    f[nod]=1;
    cl[nod]=cc;
    ++c[cc];

    for(int i=0; i<v[nod].size(); ++i)
        rez+=df(v[nod][i], 1-cc);

    return rez;
}

int main()
{
  //  freopen("d.in", "r", stdin);
  //  freopen("d.out", "w", stdout);

    scanf("%d%d", &n, &m);

    if(m==0)
    {
        cout<<3<<" "<<1LL*n*(n-1)*(n-2)/6<<"\n";

        return 0;
    }

    for(int i=1; i<=m; ++i)
    {
        int a, b;

        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; ++i)
    {
        c[0]=c[1]=0;

        if(f[i]==0)
        {
            ++cs[df(i, 0)];

            sol += 1LL*c[0]*(c[0]-1)/2 + 1LL*c[1]*(c[1]-1)/2;
        }
    }

    if(sol>0)
    {
        cout<<1<<" "<<sol<<"\n";
        return 0;
    }

    cout<<2<<" "<<1LL*(n-2*cs[2])*cs[2]+2LL*cs[2]*(cs[2]-1)<<"\n";

    return 0;
}