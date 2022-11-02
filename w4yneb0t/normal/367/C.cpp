#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
in f(in a){
  if(a%2){
    return a*(a-1)/2+1;
  }
  return a*(a-1)/2+a/2;
}
in n,m;
in q;
in w[100009];
int main(){
  cin>>n>>m;
  for(in i=0;i<m;i++)
    cin>>q>>w[i];
  sort(w,w+m);
  reverse(w,w+m);
  in sm=0;
  in nb=0;
  while(true){
    if(nb==m || f(nb+1)>n){
      cout<<sm<<endl;
      break;
    }
    sm+=w[nb++];
  }
  return 0;
}