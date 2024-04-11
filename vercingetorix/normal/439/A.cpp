#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int n,d;
  int ans=0;
  cin >> n >> d;
  int s=0;
  for(int i=0; i<n; i++){
	  int t;
	  cin >> t;
	  s+=t;

  }
  if (((n-1)*10+s) > d){
	  cout<<-1;
	  return 0;
  }
  else {
	  cout<<(d-s)/5;
  }
 



  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}