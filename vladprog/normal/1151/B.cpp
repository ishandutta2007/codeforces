#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=510;

int a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    int x=0,r=0;
    for(int i=1;i<=n;i++)
    {
        set<int> s;
        for(int j=1;j<=m;j++)
            cin>>a[i][j],
            s.insert(a[i][j]);
        if(s.size()!=1)
            r=i;
        x^=a[i][1];
    }
    if(x)
    {
        cout<<"TAK\n";
        for(int i=1;i<=n;i++)
            cout<<1<<" ";
    }
    else if(r)
    {
        int c=0;
        for(int j=1;j<=m;j++)
            if(a[r][1]!=a[r][j])
                c=j;
        cout<<"TAK\n";
        for(int i=1;i<=n;i++)
            cout<<(i==r?c:1)<<" ";
    }
    else
        cout<<"NIE";
}