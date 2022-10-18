#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=55;

int g[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(n*a!=m*b)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                g[i][j]=0;
        for(int i=0;i<=n*a;i++)
            g[i%n][i/b]=1;
        for(int i=0;i<n;i++,cout<<"\n")
            for(int j=0;j<m;j++)
                cout<<g[i][j];
    }
}