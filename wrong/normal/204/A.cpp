#include<iostream>

using namespace std;

typedef long long Int;

Int pow10[20];

Int func(int n, int d, Int X)
{
  int xd[20] = {0};
  int xl = 0;
  
  for(Int t=X; t>0; t/=10) xl++;
  if(n > xl) return 0;
  if(n < xl) return pow10[n-2];
  
  for(Int t=X, i=0; i<xl; ++i, t/=10) xd[xl-i-1] = t%10;
  if(d > xd[0]) return 0;
  if(d < xd[0]) return pow10[n-2];
  
  Int mid = (X - xd[0] * pow10[xl-1]) / 10;
  if(d > xd[xl-1]) return mid;
  return mid + 1;
}

Int solve(Int X)
{
  Int res = 0;
  if(X < 10) return X;
  
  res = 9;
  for(int len=2; len<=18; ++len)
    for(int d=1; d<=9; ++d)
      res += func(len, d, X);
  
  return res;
}

int main()
{
  pow10[0] = 1;
  for(int i=1; i<=18; ++i)
    pow10[i] = 10*pow10[i-1];

  Int L, R;
  cin >> L >> R;
  cout << (solve(R) - solve(L-1)) << endl;
  return 0;
}