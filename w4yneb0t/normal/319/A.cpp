#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cassert>
using namespace std;
typedef long long ll;
ll md=1000000007LL;
ll pw[2000];
char xo[2000];
int main(){
  scanf("%s",xo);
  //cin>>xo;
  pw[0]=1;
  for(ll i=1;i<2000;i++){
    pw[i]=(pw[i-1]*2LL)%md;
  }
  ll i;
  ll sm=0;
  for(i=0;xo[i]!='\0';i++);
  for(ll j=0;j<i;j++){
    if(xo[j]=='1'){
      sm+=pw[2LL*i-j-2LL];
      sm%=md;
    }
  }
  int osm=sm;
  printf("%d\n",osm);
  //cout<<sm<<endl;
  return 0;
}