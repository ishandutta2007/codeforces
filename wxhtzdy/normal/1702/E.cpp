#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int t;cin>>t;
while(t--){
int n;cin>>n;
vector<int> G[n+1];
for(int i=0;i<n;i++){
int a,b;cin>>a>>b;
G[a].push_back(b);
G[b].push_back(a);
}
vector<bool> was(n+1);
vector<int> col(n+1);
bool bip=true;
for(int i=1;i<=n;i++)if(G[i].size()!=2)bip=false;
function<void(int)> DFS=[&](int v){
was[v]=true;
for(int u:G[v]){
if(!was[u]){
col[u]=1-col[v];
DFS(u);
}else{
if(col[u]==col[v])bip=false;
}
}
};
for(int i=1;i<=n;i++){
if(!was[i])DFS(i);
}
cout<<(bip?"YES":"NO")<<"\n";
}
}