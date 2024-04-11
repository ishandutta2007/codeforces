#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,m;
  cin >> n >> m;
  if(m<=1){
    cout << 1 << endl;
    return 0;
  }
  cout << min(m,n-m) << endl;
  return 0;
}