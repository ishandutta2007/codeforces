#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int n,q;
cin>>n;
vector<int> G[n];
for(int i=1;i<n;i++){
int a,b;cin>>a>>b;
--a;--b;
G[a].push_back(b);
G[b].push_back(a);
}
const int L=20;
vector<vector<int>> jump(n,vector<int>(L));
vector<int> tin(n),tout(n),dep(n);
int T=0;
function<void(int,int)> DFS=[&](int u,int pr){
jump[u][0]=pr;
dep[u]=dep[pr]+1;
tin[u]=++T;
for(int v:G[u])if(v!=pr)DFS(v,u);
tout[u]=T;
};
DFS(0,0);
for(int j=1;j<L;j++){
for(int i=0;i<n;i++){
jump[i][j]=jump[jump[i][j-1]][j-1];
}
}
auto anc=[&](int i,int j){
return tin[i]<=tin[j]&&tout[j]<=tout[i];
};
auto LCA=[&](int u,int v){
if(dep[u]>dep[v])swap(u,v);
for(int i=L-1;i>=0;i--)if(dep[jump[v][i]]>=dep[u])v=jump[v][i];
for(int i=L-1;i>=0;i--)if(jump[v][i]!=jump[u][i])v=jump[v][i],u=jump[u][i];
return u==v?u:jump[v][0];
};
cin>>q;
while(q--){
int k;cin>>k;
vector<int> a(k);
for(int i=0;i<k;i++){
cin>>a[i];
--a[i];
}
if(k==1){
cout<<"YES\n";
continue;
}
int L=a[0];
for(int i=1;i<k;i++){
L=LCA(L,a[i]);
}
bool have=false;
for(int i:a)if(i==L)have=true;
if(!have)a.push_back(L),k++;
sort(a.begin(),a.end(),[&](int i,int j){
return tin[i]<tin[j];
});
vector<int> path(1,a[0]);
for(int i=1;i<k;i++){
if(anc(path.back(),a[i])){
path.push_back(a[i]);
}else{
break;
}
}
int id=path.size();
if(id==k){
cout<<"YES\n";
continue;
}
bool ok=true;
for(int i=id+1;i<k;i++){
if(!anc(a[i-1],a[i]))ok=false;
}
if(!ok||LCA(path[1],a[id])!=L){
cout<<"NO\n";
}else{
cout<<"YES\n";
}
}
}