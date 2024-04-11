#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int inv2=(p+1)/2;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n+1][n+1];
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if(i==j)
                {
                    a[i][j]=0;
                    continue;
                }
                else if(j==0)
                {
                    a[i][j]=(-k*i);
                    a[i][j]=(a[i][j]%p+p)%p;
                }
                else
                {
                    int u1=a[i-1][j];int u2=a[i-1][j-1];
                    a[i][j]=(u1+u2)*inv2;a[i][j]%=p;a[i][j]+=p;a[i][j]%=p;
                }
            }
        }
        int ans=a[n][n-m];
        cout<<((-ans)%p+p)%p<<'\n';
    }
    return 0;
}