#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=310;

int a[N*N],b[N*N];
int val[N][N];
int who[N][N];

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
        for(int i=1;i<=n*m;i++)
            cin>>a[i];

        for(int i=1;i<=n*m;i++)
            b[i]=a[i];
        sort(b+1,b+n*m+1);
        for(int i=1,k=1;i<=n;i++)
            for(int j=1;j<=m;j++,k++)
                val[i][j]=b[k];

        map<int,vector<int>> ind;
        for(int i=n*m;i>=1;i--)
            ind[a[i]].push_back(i);
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--)
            {
                auto&vec=ind[val[i][j]];
                who[i][j]=vec.back();
                vec.pop_back();
            }

        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=1;k<j;k++)
                    ans+=who[i][j]>who[i][k];
        cout<<ans<<"\n";
    }
}