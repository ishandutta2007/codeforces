#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL n,m;
  cin >> n >> m;
  LL a,nokori=0;
  for(int i=0;i<n;i++){
    cin >> a;
    cout << (nokori+a)/m << endl;
    nokori=(nokori+a)%m;
  }
  return 0;
}