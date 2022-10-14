#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int t;cin>>t;
while(t--){
int n,k;cin>>n>>k;
map<int,vector<int>>pos;
for(int i=1;i<=n;i++){
int a;cin>>a;
pos[a].push_back(i);
}
while(k--){
int x,y;cin>>x>>y;
if(pos[x].empty()||pos[y].empty()){
cout<<"NO\n";
continue;
}
cout<<(pos[x][0]<pos[y].back()?"YES":"NO")<<"\n";
}
}
}