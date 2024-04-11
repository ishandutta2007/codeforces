#include <bits/stdc++.h>
using namespace std;

long long Y, B;

int main(){
  cin >> Y >> B;
  long long y, g, b;
  cin >> y >> g >> b;
  Y = y*2 + g - Y;
  B = g + 3*b - B;
  Y = max(0ll, Y);
  B = max(0ll, B);

  cout << Y + B << endl;

  return 0;
}