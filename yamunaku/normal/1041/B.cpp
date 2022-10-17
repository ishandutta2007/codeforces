#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL a,b,x,y;
  cin >> a >> b >> x >> y;
  LL ga,gb,tmp;
  if(x>y) ga=x,gb=y;
  else ga=y,gb=x;
  while(ga%gb){
    tmp=ga%gb;
    ga=gb;
    gb=tmp;
  }
  x/=gb,y/=gb;
  cout << (min(a/x,b/y)) << endl;
  return 0;
}