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
  int n,m;
	  cin>>n>>m;
      int ans=1;
      int currm=m;
      for(int i=0; i<n; i++){
          int a;
          cin>>a;
          if(currm<a){
              currm=m-a;
              ans++;
          }
          else currm-=a;
      }
      cout<<ans;
  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}