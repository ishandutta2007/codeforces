#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long in;

int main(){
  in n;
  cin>>n;
  in ar=0;
  in l,r,u,d;
  r=-1;
  l=100000;
  u=-1;
  d=100000;
  in x1,x2,y1,y2;
  for(in i=0;i<n;i++){
    cin>>x1>>y1>>x2>>y2;
    ar+=(x2-x1)*(y2-y1);
    if(x1<l)
      l=x1;
    if(x2>r)
      r=x2;
    if(y1<d)
      d=y1;
    if(y2>u)
      u=y2;
  }
  if(ar==(u-d)*(r-l) && (u-d)==(r-l))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}