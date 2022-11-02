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
  in n,m,k;
  in f,s;
  f=0;
  s=0;
  cin>>n>>m>>k;
  for(in i=0;i<n;i++){
    in tp;
    cin>>tp;
    f+=(tp==1);
    s+=(tp==2);
  }
  in tt=0;
  m-=f;
  k-=s;
  if(k<0){
    m+=k;
  }
  if(m<0){
    tt-=m;
    m=0;
  }
  cout<<tt<<endl;
  return 0;
}