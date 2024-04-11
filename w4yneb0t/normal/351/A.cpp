#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long in;
in n;
in z=0;
in sm=0;
in ab(in a){
  if(a<0)
    return -a;
  return a;
}
int main(){
  cin>>n;
  char wst;
  in tp;
  for(in i=0;i<2*n;i++){
    cin>>tp>>wst>>tp;
    sm+=tp;
    z+=(tp==0);
  }
  in cb=1000000000LL;
  for(in i=0;i<=z && i<=n;i++){
    if(ab(1000*(n-i)-sm)<cb)
      cb=ab(1000*(n-i)-sm);
  }
  cout<<(cb/1000)<<".";
  if(cb%1000<100)
    cout<<0;
  if(cb%1000<10)
    cout<<0;
  cout<<(cb%1000)<<endl;
  return 0;
}