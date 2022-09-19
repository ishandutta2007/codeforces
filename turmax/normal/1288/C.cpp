#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=(1e9+7);
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ++m;
    int ans=0;
    int s=0;
    int s2=0;
    for(int t=1;t<=n;++t)
    {
        int a=(t-1);
        int b=(n-t);
        int r1[a+1][m];
        int pr[a+2][m];
        for(int i=0;i<m;++i)
        {
            r1[0][i]=1;
            pr[0][i]=0;
            pr[1][i]=1;
        }
        for(int i=1;i<(a+1);++i)
        {
            for(int j=0;j<m;++j)
            {
                if(j==0)
                {
                    r1[i][j]=0;
                }
                else
                {
                r1[i][j]=pr[i+1][j-1];
                }
                pr[i+1][j]=pr[i][j]+r1[i][j];
                r1[i][j]%=p;
                pr[i+1][j]%=p;
            }
        }
        int r2[b+1][m];
        int pr2[b+2][m];
        for(int i=0;i<m;++i)
        {
            r2[0][i]=1;
            pr2[0][i]=0;
            pr2[1][i]=1;
        }
        for(int i=1;i<(b+1);++i)
        {
            for(int j=0;j<m;++j)
            {
                if(j==0)
                {
                    r2[i][j]=0;
                }
                else
                {
                r2[i][j]=pr2[i+1][j-1];
                }
                pr2[i+1][j]=pr2[i][j]+r2[i][j];
                r2[i][j]%=p;
                pr2[i+1][j]%=p;
            }
        }
        //cout<<r1[a][m-1]<<" "<<r2[b][m-1]<<endl;
        ans+=(r1[a][m-1]*s);
        s2+=r1[a][m-1];
        s2%=p;
        s+=r2[b][m-1];
        s%=p;
        ans%=p;
    }
    cout<<(s*s2-ans)%p;
    return 0;
}