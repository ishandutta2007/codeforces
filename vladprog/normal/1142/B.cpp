#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=2e5+100,L=20;

int a[N],p[N],next_p[N],next_a[N][L],pos[N],last[N],mn[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        next_p[p[i]]=p[(i+1)%n];
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=m;i>=1;i--)
    {
        pos[a[i]]=i;
        next_a[i][0]=pos[next_p[a[i]]];
    }
    for(int j=0;j<L-1;j++)
        for(int i=m;i>=1;i--)
            next_a[i][j+1]=next_a[next_a[i][j]][j];
    n--;
    for(int i=1;i<=m;i++)
    {
        last[i]=i;
        for(int j=0;j<L;j++)
            if((n>>j)&1)
                last[i]=next_a[last[i]][j];
        if(last[i]==0)
            last[i]=N;
    }
    mn[m+1]=N;
    for(int i=m;i>=1;i--)
        mn[i]=min(last[i],mn[i+1]);
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<(mn[l]<=r);
    }

}