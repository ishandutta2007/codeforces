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
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(a*n!=b*m)
    {
        cout<<"NO"<<endl;
        continue;
    }
    int res[n][m];
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) res[i][j]=0;
    int u=__gcd(a,b);
    int a1=a/u;int b1=b/u;
    int x=n/b1;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            int x1=i/b1;
            int y1=j/a1;
            if((x1+y1)%x<u)
            {
                res[i][j]=1;
            }
            else
            {
                res[i][j]=0;
            }
        }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cout<<res[i][j];
        cout<<endl;
    }
    }
    return 0;
}