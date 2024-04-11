#include <bits/stdc++.h>
using namespace std;


int main(){
  int N, M;
  cin >> N >> M;
  long double a, b, m=10000000;
  for(int i=0; i<N; i++){
    cin >> a >> b;
    m = min(m, M*a/b);
  }
  cout << fixed << setprecision(10) << m << endl;

  return 0;
}