#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, d;

int main(){
  cin >> a >> b >> c >> d;
  bool flag = true;
  if(c > 0 && a == 0)
    flag = false;
  if(d != a)
    flag = false;
  cout << flag << endl;

  return 0;
}