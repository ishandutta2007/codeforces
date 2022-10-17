#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int x;
  cin >> x;
  int i=0;
  for(;x>0;i++,x/=2);
  cout << i << endl;
  return 0;
}