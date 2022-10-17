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
  int n,h;
  cin >> n >> h;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  vector<int> b;
  b.reserve(n);
  LL tmp=0;
  for(int i=0;i<n;i++){
    b.push_back(a[i]);
    sort(all(b),greater<int>());
    tmp=0;
    for(int j=0;j<=i;j+=2){
      tmp+=b[j];
    }
    if(tmp>h){
      cout << i << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;
}