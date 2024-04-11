#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int ab[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                char a;
                cin>>a;
                ab[i][j]=a-'0';
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                char b;
                cin>>b;
                ab[i][j]^=b-'0';
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ab[i][j]^=ab[i][n];
        for(int j=1;j<=n;j++)
            for(int i=1;i<=n;i++)
                ab[i][j]^=ab[n][j];
        bool ok=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(ab[i][j])
                    ok=false;
        cout<<(ok?"YES\n":"NO\n");
    }
}