#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define F(i,n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=0;i<n;++i)
#define ALL(i) i.begin(),i.end()

int a[50005],b[50005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> g(n+1,vector<char>(m+1));
        vector<vector<int>> g2(n+1,vector<int>(m+1));
        ii jj cin>>g[i][j];
        ii a[i]=0;
        jj b[j]=0;
        ii jj if(g[i][j]=='*') a[i]++,b[j]++;
        int ans=1e9;
        ii jj ans=min(ans,n-a[i]+m-b[j]-(g[i][j]=='.'));
        cout<<ans<<endl;
    }
}