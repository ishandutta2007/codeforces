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
  int n;
  cin >> n;
  vector<int> l(n),r(n);
  for(int i=0;i<n;i++){
    cin >> l[i] >> r[i];
  }
  int x;
  cin >> x;
  for(int i=0;i<n;i++){
    if(x<l[i]){
      cout << n-i+1 << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}