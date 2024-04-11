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
  int n,k;
  cin >> n >> k;
  cout << n+1+min(n-k,k-1)+n-1+n << endl;
  return 0;
}