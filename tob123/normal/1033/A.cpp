#include <bits/stdc++.h>
using namespace std;

int N, qx, qy, kx, ky, x, y;

int main(){
  cin >> N;
  cin >> qx >> qy;
  cin >> kx >> ky;
  cin >> x >> y;

  if((x >= qx && kx < qx) || (x <= qx && kx > qx)){
    cout << "NO" << endl;
    return 0;
  }
  if((y >= qy && ky < qy) || (y <= qy && ky > qy)){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;

  return 0;
}