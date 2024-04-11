#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
        }
    }
    int ans=1e18;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int u[n][m];
            int o=a[i][j];
            u[i][j]=0;
            for(int k=i;k<n;++k)
            {
                for(int l=j;l<m;++l)
                {
                    if(k==i && l==j)
                    {
                        continue;
                    }
                    u[k][l]=1e18;
                    int curr=a[k][l]-(o+abs(k-i)+abs(l-j));
                    if(curr<0)
                    {
                        continue;
                    }
                    if(k!=i)
                    {
                        u[k][l]=min(u[k][l],u[k-1][l]+curr);
                    }
                    if(l!=j)
                    {
                        u[k][l]=min(u[k][l],u[k][l-1]+curr);
                    }
                }
            }
            for(int k=i;k>=0;k--)
            {
                for(int l=j;l>=0;l--)
                {
                    if(k==i && l==j)
                    {
                        continue;
                    }
                    u[k][l]=1e18;
                    int curr=a[k][l]-(o-abs(k-i)-abs(l-j));
                    if(curr<0)
                    {
                        continue;
                    }
                    if(k!=i)
                    {
                        u[k][l]=min(u[k][l],u[k+1][l]+curr);
                    }
                    if(l!=j)
                    {
                        u[k][l]=min(u[k][l],u[k][l+1]+curr);
                    }
                }
            }
            //cout<<i<<" "<<j<<" "<<u[0][0]<<" "<<u[n-1][m-1]<<endl;
            ans=min(ans,u[0][0]+u[n-1][m-1]);
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}