#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e4+100;

int r[N][6];

int best(int a,int b)
{
    return (r[a][1]<r[b][1])+
           (r[a][2]<r[b][2])+
           (r[a][3]<r[b][3])+
           (r[a][4]<r[b][4])+
           (r[a][5]<r[b][5])>=3?a:b;
}

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
            for(int j=1;j<=5;j++)
                cin>>r[i][j];
        int ans=1;
        for(int i=2;i<=n;i++)
            ans=best(ans,i);
        bool ok=true;
        for(int i=1;i<=n;i++)
            if(ans!=best(ans,i))
                ok=false;
        cout<<(ok?ans:-1)<<"\n";
    }
}