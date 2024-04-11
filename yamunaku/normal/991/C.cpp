#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL n;
  cin >> n;
  LL left=0;
  LL right=n;
  LL mid;
  LL candy;
  LL v;
  if(n==1||n==2){
    cout << 1 << endl;
    return 0;
  }
  while(right-left>1){
    mid=(left+right)/2;
    candy=n;
    v=0;
    while(candy>0){
      v+=min(mid,candy);
      candy-=min(mid,candy);
      candy-=(candy/10);
    }
    if(2*v<n){
      left=mid;
    }else{
      right=mid;
    }
  }
  cout << right << endl;
  return 0;
}