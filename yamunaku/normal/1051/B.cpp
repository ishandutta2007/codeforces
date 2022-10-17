#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL l,r;
  cin >> l >> r;
  cout << "YES" << endl;
  for(;l<r;l+=2){
    cout << l << " " << l+1 << endl;
  }
  return 0;
}