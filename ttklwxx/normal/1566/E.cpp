#include <iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,vector<int>> G;
int a,n,T,u,v;
bool r;
bool f(int n,int p) {
  vector<int>l=G[n];
  bool b=0;
  for(int i:l){
    if(i!=p){
      r=!f(i,n);
      a+=r;
      b|=r;
    }
  }
  a-=b;
  return b;
}
int main(){
  cin>>T;
  while(T--){
    cin>>n;
    for (int i=0;i<n;i++) {
      G[i+1].clear();
    }
    for (int i=0;i<n-1;i++) {
      cin>>u>>v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    a=1;
    f(1,0);
    cout<<a<<'\n';
  }
}