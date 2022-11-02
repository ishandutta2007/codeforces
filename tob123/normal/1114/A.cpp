#include <bits/stdc++.h>
using namespace std;


int main(){
  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  if(x<=a && ((x+y) <= (a+b)) && (x+y+z) <= (a+b+c)){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

  return 0;
}