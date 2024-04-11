#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=310;

int a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        bool ok=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                int mx=0;
                if(i>1)
                    mx++;
                if(i<n)
                    mx++;
                if(j>1)
                    mx++;
                if(j<m)
                    mx++;
                if(a[i][j]<=mx)
                    a[i][j]=mx;
                else
                    ok=false;
            }
        if(ok)
        {
            cout<<"YES\n";
            for(int i=1;i<=n;i++,cout<<"\n")
                for(int j=1;j<=m;j++)
                    cout<<a[i][j]<<" ";
        }
        else
            cout<<"NO\n";
    }
}