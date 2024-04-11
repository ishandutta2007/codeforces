#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long in;

int main(){
  in n,m;
  cin>>n>>m;
  in d[3009];
  for(in i=0;i<m;i++)
    cin>>d[i];
  sort(d,d+m);
  bool k=1;
  for(in i=0;i+2<m;i++)
    if(d[i+2]==d[i]+2)
      k=0;
  if(m>0){
    if(d[0]==1 || d[m-1]==n)
      k=0;
  }
  if(k)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}