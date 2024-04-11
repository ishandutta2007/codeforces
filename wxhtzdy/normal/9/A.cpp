#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  scanf("%i%i",&a,&b);
  int cnt=0;
  for(int i=max(a,b);i<=6;i++)cnt++;
  string s[7]={"0/1","1/6","1/3","1/2","2/3","5/6","1/1"};
  cout<<s[cnt];
}