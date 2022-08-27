#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int n,k;
  cin>>n>>k;
  if(n==1){
      if(k==0){
          cout<<1;
          return 0;

      }
      cout<<-1;
      return 0;
  }
  if((n/2)>k){
      cout<<-1;
      return 0;
  }
  int x=k-n/2+1;
  cout<<x<<" "<<2*x<<" ";
  for(int i=1; i<=n-2;i++) cout<<(2*k+2+i)<<" ";
//std::vector<int> a;

  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}