#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,w;
int a[N],b[N];
int x,y;
int dp[N],fix[N],dd[N];
vector<int>g[N];
int s,ss;
int ans;
void dfs (int k)
{
   fix[k]=1;
   s+=a[k];
   ss+=b[k];
   for (int i=0;i<=w-a[k];i++)
   dd[i+a[k]]=max(dd[i+a[k]],dp[i]+b[k]);
   for (int i=0;i<g[k].size();i++)
   if (fix[g[k][i]]==0)
   dfs(g[k][i]);
}
int main() {
   cin>>n>>m>>w;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=1;i<=n;i++)cin>>b[i];
   while (m--){
      cin>>x>>y;
      g[x].push_back(y);
      g[y].push_back(x);
   }
   for (int i=1;i<=n;i++)
   if (fix[i]==0){
      s=0;
      ss=0;
      for (int j=1;j<=n;j++)dd[j]=dp[j];
      dfs(i);
      for (int j=0;j<=w-s;j++)
      dd[j+s]=max(dd[j+s],dp[j]+ss);
      for (int j=1;j<=w;j++)dp[j]=dd[j];
   }
   ans=dp[1];
   for (int i=2;i<=w;i++)
   if (dp[i]>ans)
   ans=dp[i];
   cout<<ans<<endl;
	return 0;
}