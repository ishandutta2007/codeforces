#include <iostream>
#include <vector>
using namespace std;
int t,n,m,u,v;
long long ans,ans1,p=1,mod=998244353;
vector <long long> a[300005];
bool vis[300005],b[300005];
long long dfs(long long st,bool f)
{
   vis[st]=true;
   b[st]=f;
   if(f) ans=(ans*2)%mod;
   if(!f) ans1=(ans1*2)%mod;
   for(int i=0;i<a[st].size();i++)
   {
      if(vis[a[st][i]] and b[st]==b[a[st][i]])
      {
         ans=0;
         ans1=0;
         break;
      }
      if(!vis[a[st][i]]) dfs(a[st][i],!f);
   }
   return (ans+ans1)%mod;
}
int main ()
{
   ios::sync_with_stdio(false);
   cin>>t;
   while(t--)
   {
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      {
         a[i].clear();
         b[i]=false;
         vis[i]=false;
      }
      for(int i=0;i<m;i++)
      {
         cin>>u>>v;
         a[u].push_back(v);
         a[v].push_back(u);
      }
      p=1;
      for(int i=1;i<=n;i++)
      {
         ans=1;
         ans1=1;
         if(!vis[i]) p=(p*dfs(i,0))%mod;
      }
      cout<<p<<endl;
   }
   return 0;
}