#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int a,b,c,n;
  cin >> a >> b >> c >> n;
  if(a<c||b<c||a+b<2*c||n-(a+b-c)<1){
    cout << -1 << endl;
  }else{
    cout << n-(a+b-c) << endl;
  }
  return 0;
}