#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define N 305
#define uint long long int
using namespace std;
uint dp[N][N][N];
uint a[N][N];
int p[4]={-1, -1, 0, 0};
int r[4]={0, 0, -1, -1};
int q[4]={-1, 0, -1, 0}; 
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int k=0; k<=n; k++)
        {
            dp[i][0][k]=-1001*1001;
            dp[0][i][k]=-1001*1001;
        }
    }
    dp[1][1][1]=a[1][1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i+j>2)
            {
            for(int k=i; k<=min(n, i+j-1); k++)
            {
                dp[i][j][k]=-1001*1001;
                for(int l=0; l<4; l++)
                {
                    if( i+p[l] && j+r[l] && k+q[l]>=i+p[l] && k+q[l]-(i+j-1))
                    {
                        //cout<<dp[i+p[l]][j+r[l]][k+q[l]]<<" "<<i+p[l]<<" "<<j+r[l]<<" "<<k+q[l]<<endl;
                        dp[i][j][k]=max(dp[i][j][k], dp[i+p[l]][j+r[l]][k+q[l]]);
                    }
                }
                dp[i][j][k]+=a[i][j];
                dp[i][j][k]+=a[k][i+j-k];
                if(k==i)
                {
                    dp[i][j][k]-=a[i][j];
                }
            }
            }
        }
    }
    // cout<<dp[1][1][1]<<" "<<dp[1][2][1]<<" "<<dp[1][2][2]<<endl;
    cout<<dp[n][n][n]<<endl;
    // system("pause");
    return 0;
}
/*
2 
-1 -1
-1 -1
*/