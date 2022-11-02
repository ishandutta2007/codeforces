#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<algorithm>

using namespace std;
typedef long long int lint;
multiset<lint>d;
lint n,x;
long long int ans=0;

int main(){
  scanf("%I64d%I64d",&n,&x);
  for (lint i=0;i<n;i++){
    lint c;
    scanf("%I64d",&c);
    d.insert(c);
  }
  while(!d.empty()){
    ans+=x*(*(d.begin()));
    d.erase(d.begin());
    if(x>1){x--;}
  }
  printf("%I64d",ans);
  return 0;
}