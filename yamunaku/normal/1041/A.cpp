#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  int a;
  int mi=1000000000,ma=0;
  for(int i=0;i<n;i++){
    cin >> a;
    mi=min(mi,a);
    ma=max(ma,a);
  }
  cout << ma-mi-n+1 << endl;
  return 0;
}