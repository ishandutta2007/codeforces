#include<iostream>

using namespace std;

int main()
{
  int x;
  cin >> x;
  
  if(x == 3) {
    cout << 5 << endl;
    return 0;
  }
  
  int n = 1, m = 1;
  while(true) {
    if(m >= x) {
      cout << n << endl;
      break;
    }
    n += 2;
    m = n * (n/2) + n/2 + 1;
  }
  
  return 0;
}