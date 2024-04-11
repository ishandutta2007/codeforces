#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=0;
        int l=1,r=2+n%2;
        while(r<=n)
        {
            for(int i=l;i<=r;i++)
                for(int j=l;j<=r;j++)
                    a[i][j]=1;
            l=r+1;
            r=l+1;
        }
        for(int i=1;i<=n;i++,cout<<"\n")
            for(int j=1;j<=n;j++)
                cout<<a[i][j]<<" ";
    }
}