#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL n,m,a,b;
  cin >> n >> m >> a >> b;
  cout << ((n%m)?min((m-(n%m))*a,(n%m)*b):0) << endl;
  return 0;
}