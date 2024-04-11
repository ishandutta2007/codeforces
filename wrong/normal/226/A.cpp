#include<iostream>

using namespace std;

typedef long long Int;

int main()
{
  Int n, m;

  cin >> n >> m;

  Int v = 1;
  Int x = 3;
  for(; n; n>>=1, x=(x*x)%m)
    if(n&1) v=(v*x)%m;

  cout << (v+m-1)%m << endl;

  return 0;
}