#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e8,N=150005;
const ll INF=1e17;
int n,m,u,v;
int fix[N];
vector<int>g[N];
vector<int>vec;
void dfs (int k){
   fix[k]=1;
   vec.pb(k);
   for (int i=0;i<g[k].size();i++)
   if (fix[g[k][i]]==0)
   dfs(g[k][i]);
}
int main(){
   cin>>n>>m;
   while (m--){
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
   }
   for (int i=1;i<=n;i++)
   if (fix[i]==0){
      vec.clear();
      dfs(i);
      for (int j=0;j<vec.size();j++)
      if (g[vec[j]].size()!=vec.size()-1){
         cout<<"NO"<<endl;
         return 0;
      }
   }
   cout<<"YES"<<endl;
   return 0;
}