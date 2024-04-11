#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110,Q=1e4+10;

int a[N][N],t[Q],r[Q],c[Q],x[Q];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>t[i];
        if(t[i]==1)
            cin>>r[i];
        else if(t[i]==2)
            cin>>c[i];
        else
            cin>>r[i]>>c[i]>>x[i];
    }
    for(int i=q;i>=1;i--)
    {
        if(t[i]==1)
        {
            for(int j=m;j>=1;j--)
                a[r[i]][j+1]=a[r[i]][j];
            a[r[i]][1]=a[r[i]][m+1];
        }
        else if(t[i]==2)
        {
            for(int j=n;j>=1;j--)
                a[j+1][c[i]]=a[j][c[i]];
            a[1][c[i]]=a[n+1][c[i]];
        }
        else
            a[r[i]][c[i]]=x[i];
    }
    for(int i=1;i<=n;i++,cout<<"\n")
        for(int j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
}