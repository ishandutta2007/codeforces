#include <bits/stdc++.h>
using namespace std;

int main(){
  long long x, y;
  cin >> x >> y;
  y--;
  bool flag = true;
  if(y == -1)
    flag = false;
  if(x > 0 && y == 0)
    flag = false;
  x -= y;
  if(x < 0 || x % 2 != 0)
    flag = false;

  if(flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}