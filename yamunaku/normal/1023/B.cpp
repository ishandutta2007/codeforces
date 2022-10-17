#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

// max(k-n,1)<=x<=min(k-1,n)

int main(){
  LL n,k;
  cin >> n >> k;
  cout << max(0,(min(k-1,n)-max(k-n,1)+1)/2) << endl;
  return 0;
}